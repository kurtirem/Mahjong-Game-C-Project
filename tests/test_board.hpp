#ifndef TEST_BOARD_HPP
#define TEST_BOARD_HPP

#include <QObject>

class TestBoard : public QObject {
  Q_OBJECT
 private slots:
  void initTestCase();
  void testInitialLayout();
  void testTileSelection();
  void testRemovePair();
  void testSelectCoveredTile();
  void testShuffle();
  void testNonMatchingPairResetsSelection();
  void cleanupTestCase();
};

#endif  // TEST_BOARD_HPP
