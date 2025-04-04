#include <QGuiApplication>
#include <QtTest>

#include "test_board.hpp"
#include "test_tile.hpp"

int main(int argc, char *argv[]) {
  // Create a QGuiApplication to ensure Qt Multimedia and event loops work
  QGuiApplication app(argc, argv);

  int status = 0;
  {
    TestBoard tc;
    status |= QTest::qExec(&tc, argc, argv);
  }
  {
    TestTile tc;
    status |= QTest::qExec(&tc, argc, argv);
  }
  return status;
}
