#include "test_board.hpp"

#include <QtTest>

#include "board.hpp"
#include "tile.hpp"
#include "tilemodel.hpp"

void TestBoard::initTestCase() {
  // Setup before any test
}

void TestBoard::testInitialLayout() {
  TileModel model;
  Board board(&model);
  board.generateTurtleLayout();

  QVERIFY(model.rowCount() > 0);

  bool foundOpen = false;
  for (int i = 0; i < model.rowCount(); ++i) {
    Tile* t = model.tileAt(i);
    if (t && t->open()) {
      foundOpen = true;
      break;
    }
  }
  QVERIFY(foundOpen);
}

void TestBoard::testTileSelection() {
  TileModel model;
  Board board(&model);
  board.generateTurtleLayout();

  Tile* openTile = nullptr;
  for (int i = 0; i < model.rowCount(); ++i) {
    Tile* t = model.tileAt(i);
    if (t && t->open()) {
      openTile = t;
      break;
    }
  }
  QVERIFY(openTile != nullptr);
  board.selectTile(openTile->row(), openTile->column());
  QVERIFY(openTile->selected());
}

void TestBoard::testRemovePair() {
  TileModel model;
  Board board(&model);
  board.generateTurtleLayout();

  Tile* firstOpen = nullptr;
  Tile* secondOpen = nullptr;

  for (int i = 0; i < model.rowCount(); ++i) {
    Tile* t1 = model.tileAt(i);
    if (!t1 || !t1->open()) continue;
    for (int j = i + 1; j < model.rowCount(); ++j) {
      Tile* t2 = model.tileAt(j);
      if (!t2 || !t2->open()) continue;
      if (t1->type() == t2->type() && t1->value() == t2->value()) {
        firstOpen = t1;
        secondOpen = t2;
        break;
      }
    }
    if (firstOpen && secondOpen) break;
  }

  if (!firstOpen || !secondOpen) {
    QSKIP("No easily accessible open pair found.", SkipSingle);
  }

  int initialCount = model.rowCount();
  board.selectTile(firstOpen->row(), firstOpen->column());
  board.selectTile(secondOpen->row(), secondOpen->column());
  QCOMPARE(model.rowCount(), initialCount - 2);
}

void TestBoard::testSelectCoveredTile() {
  TileModel model;
  Board board(&model);
  board.generateTurtleLayout();

  Tile* coveredTile = nullptr;
  for (Tile* t : model.allTiles()) {
    if (t && !t->open()) {
      coveredTile = t;
      break;
    }
  }

  if (!coveredTile) {
    QSKIP("No covered tile found, skipping.", SkipSingle);
  }

  int initialCount = model.rowCount();
  board.selectTile(coveredTile->row(), coveredTile->column());
  QCOMPARE(model.rowCount(), initialCount);
  QVERIFY(!coveredTile->selected());
}

void TestBoard::testShuffle() {
  TileModel model;
  Board board(&model);
  board.generateTurtleLayout();

  int initialCount = model.rowCount();
  board.shuffle();
  QCOMPARE(model.rowCount(), initialCount);

  QSet<Tile*> afterSet;
  for (Tile* t : model.allTiles()) {
    QVERIFY(t != nullptr);
    QVERIFY(!afterSet.contains(t));
    afterSet.insert(t);
    QVERIFY(t->row() >= 0);
    QVERIFY(t->column() >= 0);
  }
}

void TestBoard::testNonMatchingPairResetsSelection() {
  TileModel model;
  Board board(&model);
  board.generateTurtleLayout();

  Tile* tileA = nullptr;
  Tile* tileB = nullptr;

  for (int i = 0; i < model.rowCount(); ++i) {
    Tile* t1 = model.tileAt(i);
    if (!t1 || !t1->open()) continue;
    for (int j = i + 1; j < model.rowCount(); ++j) {
      Tile* t2 = model.tileAt(j);
      if (!t2 || !t2->open()) continue;
      if (t1->type() != t2->type() || t1->value() != t2->value()) {
        tileA = t1;
        tileB = t2;
        break;
      }
    }
    if (tileA && tileB) break;
  }

  if (!tileA || !tileB) {
    QSKIP("No two distinct open tiles found.", SkipSingle);
  }

  int initialCount = model.rowCount();
  board.selectTile(tileA->row(), tileA->column());
  board.selectTile(tileB->row(), tileB->column());

  QCOMPARE(model.rowCount(), initialCount);
  QVERIFY(!tileA->selected());
  QVERIFY(!tileB->selected());
}

void TestBoard::cleanupTestCase() {
  // After all tests
}

// No need to include test_board.moc if your project is set up properly
// If needed, ensure Q_OBJECT is in test_board.hpp and HEADERS listed in
// tests.pro
