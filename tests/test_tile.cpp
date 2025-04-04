#include "test_tile.hpp"

#include <QtTest>

#include "tile.hpp"

void TestTile::testProperties() {
  Tile t;
  t.setType("Bamboo");
  t.setValue(3);
  t.setOpen(true);
  QCOMPARE(t.type(), QString("Bamboo"));
  QCOMPARE(t.value(), 3);
  QVERIFY(t.open());
}
