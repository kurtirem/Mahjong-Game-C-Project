#ifndef TILEMODEL_HPP
#define TILEMODEL_HPP

#include <QAbstractListModel>
#include <QVector>

#include "tile.hpp"

/**
 * @file tilemodel.hpp
 * @brief Declares the TileModel class for managing a collection of Tile
 * objects.
 *
 * This file contains the TileModel class, a QAbstractListModel that exposes
 * Tile objects to the QML view. It handles adding, removing, and accessing
 * tiles, as well as responding to tile property changes. The model assigns
 * roles for tile attributes and integrates closely with the Board class to
 * reflect the current game state in the UI.
 */

class TileModel : public QAbstractListModel {
  Q_OBJECT
 public:
  enum TileRoles {
    TypeRole = Qt::UserRole + 1,
    ValueRole,
    FaceUpRole,
    RowRole,
    ColumnRole,
    SelectedRole,
    OpenRole,
    LayerRole
  };

  explicit TileModel(QObject* parent = nullptr) : QAbstractListModel(parent) {}

  int rowCount(const QModelIndex& parent = QModelIndex()) const override {
    Q_UNUSED(parent)
    return m_tiles.size();
  }

  QVariant data(const QModelIndex& index,
                int role = Qt::DisplayRole) const override {
    if (!index.isValid() || index.row() < 0 || index.row() >= m_tiles.size())
      return QVariant();

    Tile* tile = m_tiles.at(index.row());
    if (!tile) return QVariant();

    switch (role) {
      case TypeRole:
        return tile->type();
      case ValueRole:
        return tile->value();
      case FaceUpRole:
        return tile->faceUp();
      case RowRole:
        return tile->row();
      case ColumnRole:
        return tile->column();
      case SelectedRole:
        return tile->selected();
      case OpenRole:
        return tile->open();
      case LayerRole:
        return tile->layer();
      default:
        return QVariant();
    }
  }

  QHash<int, QByteArray> roleNames() const override {
    QHash<int, QByteArray> roles;
    roles[TypeRole] = "type";
    roles[ValueRole] = "value";
    roles[FaceUpRole] = "faceUp";
    roles[RowRole] = "row";
    roles[ColumnRole] = "column";
    roles[SelectedRole] = "selected";
    roles[OpenRole] = "open";
    roles[LayerRole] = "layer";
    return roles;
  }

  void addTile(Tile* tile) {
    beginInsertRows(QModelIndex(), m_tiles.size(), m_tiles.size());
    m_tiles.append(tile);
    endInsertRows();

    connect(tile, &Tile::typeChanged, this, &TileModel::onTileChanged);
    connect(tile, &Tile::valueChanged, this, &TileModel::onTileChanged);
    connect(tile, &Tile::faceUpChanged, this, &TileModel::onTileChanged);
    connect(tile, &Tile::rowChanged, this, &TileModel::onTileChanged);
    connect(tile, &Tile::columnChanged, this, &TileModel::onTileChanged);
    connect(tile, &Tile::selectedChanged, this, &TileModel::onTileChanged);
    connect(tile, &Tile::openChanged, this, &TileModel::onTileChanged);
    connect(tile, &Tile::layerChanged, this, &TileModel::onTileChanged);
  }

  void clear() {
    if (m_tiles.isEmpty()) return;
    beginRemoveRows(QModelIndex(), 0, m_tiles.size() - 1);
    qDeleteAll(m_tiles);
    m_tiles.clear();
    endRemoveRows();
  }

  QList<Tile*> takeAllTiles() {
    if (m_tiles.isEmpty()) return QList<Tile*>();

    beginRemoveRows(QModelIndex(), 0, m_tiles.size() - 1);
    QList<Tile*> all = m_tiles.toList();
    m_tiles.clear();
    endRemoveRows();

    return all;
  }

  Tile* tileAt(int rowIndex) const {
    if (rowIndex < 0 || rowIndex >= m_tiles.size()) return nullptr;
    return m_tiles.at(rowIndex);
  }

  Tile* findTileByPosition(int r, int c) const {
    Tile* topmost = nullptr;
    for (Tile* t : m_tiles) {
      if (t->row() == r && t->column() == c) {
        if (!topmost || t->layer() > topmost->layer()) {
          topmost = t;
        }
      }
    }
    return topmost;
  }

  void removeTile(Tile* tile) {
    int idx = m_tiles.indexOf(tile);
    if (idx >= 0) {
      beginRemoveRows(QModelIndex(), idx, idx);
      m_tiles.removeAt(idx);
      delete tile;
      endRemoveRows();
    }
  }

  QList<Tile*> allTiles() const { return m_tiles.toList(); }

 private slots:
  void onTileChanged() {
    Tile* changedTile = qobject_cast<Tile*>(sender());
    if (!changedTile) return;
    int idx = m_tiles.indexOf(changedTile);
    if (idx >= 0) {
      QModelIndex modelIndex = index(idx, 0);
      emit dataChanged(modelIndex, modelIndex,
                       {TypeRole, ValueRole, FaceUpRole, RowRole, ColumnRole,
                        SelectedRole, OpenRole, LayerRole});
    }
  }

 private:
  QVector<Tile*> m_tiles;
};

#endif  // TILEMODEL_HPP
