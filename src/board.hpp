#ifndef BOARD_HPP
#define BOARD_HPP

#include <QObject>
#include <QSoundEffect>
#include <QVector>
#include <algorithm>
#include <random>

#include "tilemodel.hpp"

class Board : public QObject {
  Q_OBJECT
 public:
  explicit Board(TileModel* model, QObject* parent = nullptr)
      : QObject(parent),
        m_model(model),
        m_firstSelected(nullptr),
        // Predefined coordinates for the turtle layout
        layer0({{3, 3},   {3, 4},  {3, 5},  {3, 6},  {3, 7},  {3, 8},  {3, 9},
                {3, 10},  {3, 11}, {4, 3},  {4, 4},  {4, 5},  {4, 6},  {4, 7},
                {4, 8},   {4, 9},  {4, 10}, {4, 11}, {5, 3},  {5, 4},  {5, 5},
                {5, 6},   {5, 7},  {5, 8},  {5, 9},  {5, 10}, {5, 11}, {6, 3},
                {6, 4},   {6, 5},  {6, 6},  {6, 7},  {6, 8},  {6, 9},  {6, 10},
                {6, 11},  {7, 3},  {7, 4},  {7, 5},  {7, 6},  {7, 7},  {7, 8},
                {7, 9},   {7, 10}, {7, 11}, {8, 3},  {8, 4},  {8, 5},  {8, 6},
                {8, 7},   {8, 8},  {8, 9},  {8, 10}, {8, 11}, {9, 3},  {9, 4},
                {9, 5},   {9, 6},  {9, 7},  {9, 8},  {9, 9},  {9, 10}, {9, 11},
                {10, 3},  {10, 4}, {10, 5}, {10, 6}, {10, 7}, {10, 8}, {10, 9},
                {10, 10}, {10, 11}}),
        layer1({{4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8}, {4, 9}, {4, 10},
                {5, 4}, {5, 5}, {5, 6}, {5, 7}, {5, 8}, {5, 9}, {5, 10},
                {6, 4}, {6, 5}, {6, 6}, {6, 7}, {6, 8}, {6, 9}, {6, 10},
                {7, 4}, {7, 5}, {7, 6}, {7, 7}, {7, 8}, {7, 9}, {7, 10},
                {8, 4}, {8, 5}, {8, 6}, {8, 7}, {8, 8}, {8, 9}, {8, 10},
                {9, 4}, {9, 5}, {9, 6}, {9, 7}, {9, 8}, {9, 9}, {9, 10}}),
        layer2({{5, 5}, {5, 6}, {5, 7}, {5, 8}, {5, 9}, {6, 5}, {6, 6},
                {6, 7}, {6, 8}, {6, 9}, {7, 5}, {7, 6}, {7, 7}, {7, 8},
                {7, 9}, {8, 5}, {8, 6}, {8, 7}, {8, 8}, {8, 9}}),
        layer3({{6, 6},
                {6, 7},
                {6, 8},
                {7, 6},
                {7, 7},
                {7, 8},
                {8, 6},
                {8, 7},
                {8, 8}}),
        layer4({{7, 7}}) {
    // Initialize sound effects
    m_clickSound.setSource(QUrl("qrc:/sounds/click.wav"));
    m_clickSound.setVolume(0.8);

    m_removePairSound.setSource(QUrl("qrc:/sounds/remove_pair.wav"));
    m_removePairSound.setVolume(0.8);

    m_mistakeSound.setSource(QUrl("qrc:/sounds/mistake.wav"));
    m_mistakeSound.setVolume(0.8);
  }

  Q_INVOKABLE void generateTurtleLayout() {
    m_model->clear();

    // Combine all positions from all layers into one vector
    QVector<QPair<int, int>> allPositions;
    allPositions += layer0;
    allPositions += layer1;
    allPositions += layer2;
    allPositions += layer3;
    allPositions += layer4;

    struct TileDefinition {
      QString type;
      int minVal;
      int maxVal;
    };

    QVector<TileDefinition> standardSets = {
        {"Bamboo", 1, 9}, {"Circle", 1, 9}, {"Pinyin", 1, 15}};

    QStringList seasonTiles = {"Spring", "Summer", "Fall", "Winter"};
    QStringList flowerTiles = {"Chrysanthemum", "Lotus", "Orchid", "Peony"};

    int stdSetIndex = 0;
    int stdValue = standardSets[stdSetIndex].minVal;
    bool usingStandard = true;
    int seasonIndex = 0;
    int flowerIndex = 0;

    // A vector to hold the final (type, value) pairs
    QVector<QPair<QString, int>> tileSequence;
    tileSequence.reserve(allPositions.size());

    // Same logic as getNextTileTypeAndValue
    auto getNextTileTypeAndValue = [&]() {
      if (usingStandard) {
        const auto& set = standardSets[stdSetIndex];
        QString t = set.type;
        int v = stdValue;
        stdValue++;
        if (stdValue > set.maxVal) {
          stdSetIndex = (stdSetIndex + 1) % standardSets.size();
          stdValue = standardSets[stdSetIndex].minVal;
        }
        usingStandard = false;
        return qMakePair(t, v);
      } else {
        static bool useSeason = true;
        QString t;
        int v = 1;
        if (useSeason) {
          t = seasonTiles[seasonIndex];
          seasonIndex = (seasonIndex + 1) % seasonTiles.size();
        } else {
          t = flowerTiles[flowerIndex];
          flowerIndex = (flowerIndex + 1) % flowerTiles.size();
        }
        useSeason = !useSeason;
        usingStandard = true;
        return qMakePair(t, v);
      }
    };

    // Generate all tile type-value pairs in the original deterministic order
    for (int i = 0; i < allPositions.size(); ++i) {
      auto [t, v] = getNextTileTypeAndValue();
      tileSequence.append(qMakePair(t, v));
    }

    // Now shuffle the entire sequence to produce a different starting order
    // each time
    {
      std::random_device rd;
      std::mt19937 g(rd());
      std::shuffle(tileSequence.begin(), tileSequence.end(), g);
    }

    // Assign shuffled tiles to positions
    // We know total count matches the positions
    for (int i = 0; i < allPositions.size(); ++i) {
      const auto& pos = allPositions[i];
      const auto& tv = tileSequence[i];

      // Determine layer based on index i (as before)
      int idx = i;
      int layer = 0;
      int remainder = idx;
      if (remainder >= layer0.size()) {
        remainder -= layer0.size();
        layer = 1;
        if (remainder >= layer1.size()) {
          remainder -= layer1.size();
          layer = 2;
          if (remainder >= layer2.size()) {
            remainder -= layer2.size();
            layer = 3;
            if (remainder >= layer3.size()) {
              remainder -= layer3.size();
              layer = 4;
            }
          }
        }
      }

      Tile* tile = new Tile();
      tile->setType(tv.first);
      tile->setValue(tv.second);
      tile->setFaceUp(true);
      tile->setRow(pos.first);
      tile->setColumn(pos.second);
      tile->setLayer(layer);
      tile->setOpen(false);
      m_model->addTile(tile);
    }

    m_firstSelected = nullptr;
    updateOpenStates();
  }

  Q_INVOKABLE void selectTile(int row, int column) {
    Tile* clicked = m_model->findTileByPosition(row, column);
    if (!clicked || !clicked->open()) return;

    if (m_firstSelected == clicked) return;

    if (!m_firstSelected) {
      // First tile selected
      clicked->setSelected(true);
      m_firstSelected = clicked;
      m_clickSound.play();
    } else {
      // Second tile selected
      if (tilesMatch(m_firstSelected, clicked)) {
        // Matching pair
        Tile* toRemove1 = m_firstSelected;
        Tile* toRemove2 = clicked;
        m_firstSelected = nullptr;
        m_model->removeTile(toRemove1);
        m_model->removeTile(toRemove2);
        updateOpenStates();
        m_removePairSound.play();
      } else {
        // No match - play mistake sound
        m_firstSelected->setSelected(false);
        clicked->setSelected(false);
        m_firstSelected = nullptr;
        m_mistakeSound.play();
      }
    }
  }

  Q_INVOKABLE void shuffle() {
    QList<Tile*> all = m_model->takeAllTiles();
    if (all.isEmpty()) return;

    struct TilePosition {
      int row;
      int column;
      int layer;
    };

    QVector<TilePosition> positions;
    positions.reserve(all.size());

    for (Tile* t : all) {
      TilePosition pos = {t->row(), t->column(), t->layer()};
      positions.append(pos);
    }

    std::vector<Tile*> tilesVector;
    tilesVector.reserve(all.size());
    for (Tile* t : all) {
      tilesVector.push_back(t);
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(tilesVector.begin(), tilesVector.end(), g);

    m_model->clear();

    for (int i = 0; i < positions.size(); ++i) {
      Tile* t = tilesVector[i];
      t->setRow(positions[i].row);
      t->setColumn(positions[i].column);
      t->setLayer(positions[i].layer);
      t->setSelected(false);
      t->setOpen(false);
      m_model->addTile(t);
    }

    updateOpenStates();
  }

 private:
  void updateOpenStates() {
    QList<Tile*> all = m_model->allTiles();
    for (Tile* t : all) {
      int r = t->row();
      int c = t->column();
      int l = t->layer();

      bool covered = false;
      for (Tile* other : all) {
        if (other->layer() > l && other->row() == r && other->column() == c) {
          covered = true;
          break;
        }
      }

      if (covered) {
        t->setOpen(false);
        continue;
      }

      Tile* left = nullptr;
      Tile* right = nullptr;
      for (Tile* other : all) {
        if (other->layer() == l && other->row() == r &&
            other->column() == c - 1)
          left = other;
        if (other->layer() == l && other->row() == r &&
            other->column() == c + 1)
          right = other;
      }

      bool isOpen = (left == nullptr || right == nullptr);
      t->setOpen(isOpen);
    }
  }

  bool tilesMatch(Tile* a, Tile* b) {
    if (!a || !b) return false;

    QString A = a->type();
    QString B = b->type();

    QSet<QString> seasons = {"Spring", "Summer", "Fall", "Winter"};
    QSet<QString> flowers = {"Chrysanthemum", "Lotus", "Orchid", "Peony"};

    bool aIsSeason = seasons.contains(A);
    bool bIsSeason = seasons.contains(B);
    bool aIsFlower = flowers.contains(A);
    bool bIsFlower = flowers.contains(B);

    if (aIsSeason && bIsSeason) return true;
    if (aIsFlower && bIsFlower) return true;

    return (A == B && a->value() == b->value());
  }

  TileModel* m_model;
  Tile* m_firstSelected;

  QSoundEffect m_clickSound;
  QSoundEffect m_removePairSound;
  QSoundEffect m_mistakeSound;

  const QVector<QPair<int, int>> layer0;
  const QVector<QPair<int, int>> layer1;
  const QVector<QPair<int, int>> layer2;
  const QVector<QPair<int, int>> layer3;
  const QVector<QPair<int, int>> layer4;
};

#endif  // BOARD_HPP
