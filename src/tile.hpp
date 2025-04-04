#ifndef TILE_HPP
#define TILE_HPP

#include <QObject>
#include <QString>

/**
 * @file tile.hpp
 * @brief Declares the Tile class representing a single Mahjong tile.
 *
 * This file contains the definition of the Tile class, which stores the tile's
 * properties such as type, value, position (row, column, layer), and states
 * (open, selected, faceUp). It provides signals for property changes and is
 * used by the TileModel to represent the game's tiles.
 */

class Tile : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)
  Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
  Q_PROPERTY(bool faceUp READ faceUp WRITE setFaceUp NOTIFY faceUpChanged)
  Q_PROPERTY(int row READ row WRITE setRow NOTIFY rowChanged)
  Q_PROPERTY(int column READ column WRITE setColumn NOTIFY columnChanged)
  Q_PROPERTY(
      bool selected READ selected WRITE setSelected NOTIFY selectedChanged)
  Q_PROPERTY(bool open READ open WRITE setOpen NOTIFY openChanged)
  Q_PROPERTY(int layer READ layer WRITE setLayer NOTIFY layerChanged)

 public:
  explicit Tile(QObject *parent = nullptr)
      : QObject(parent),
        m_type("Unknown"),
        m_value(0),
        m_faceUp(true),
        m_row(0),
        m_column(0),
        m_selected(false),
        m_open(false),
        m_layer(0) {}

  QString type() const { return m_type; }
  void setType(const QString &type) {
    if (m_type != type) {
      m_type = type;
      emit typeChanged();
    }
  }

  int value() const { return m_value; }
  void setValue(int value) {
    if (m_value != value) {
      m_value = value;
      emit valueChanged();
    }
  }

  bool faceUp() const { return m_faceUp; }
  void setFaceUp(bool faceUp) {
    if (m_faceUp != faceUp) {
      m_faceUp = faceUp;
      emit faceUpChanged();
    }
  }

  int row() const { return m_row; }
  void setRow(int r) {
    if (m_row != r) {
      m_row = r;
      emit rowChanged();
    }
  }

  int column() const { return m_column; }
  void setColumn(int c) {
    if (m_column != c) {
      m_column = c;
      emit columnChanged();
    }
  }

  bool selected() const { return m_selected; }
  void setSelected(bool s) {
    if (m_selected != s) {
      m_selected = s;
      emit selectedChanged();
    }
  }

  bool open() const { return m_open; }
  void setOpen(bool o) {
    if (m_open != o) {
      m_open = o;
      emit openChanged();
    }
  }

  int layer() const { return m_layer; }
  void setLayer(int l) {
    if (m_layer != l) {
      m_layer = l;
      emit layerChanged();
    }
  }

 signals:
  void typeChanged();
  void valueChanged();
  void faceUpChanged();
  void rowChanged();
  void columnChanged();
  void selectedChanged();
  void openChanged();
  void layerChanged();

 private:
  QString m_type;
  int m_value;
  bool m_faceUp;
  int m_row;
  int m_column;
  bool m_selected;
  bool m_open;
  int m_layer;
};

#endif  // TILE_HPP
