#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "board.hpp"
#include "tile.hpp"
#include "tilemodel.hpp"

/**
 * @file main.cpp
 * @brief The entry point of the Mahjong solitaire application.
 *
 * This file sets up the QGuiApplication and QQmlApplicationEngine,
 * registers the Tile class, creates and initializes the Board and TileModel,
 * and exposes them to QML. It then loads the main QML file, starting
 * the event loop for the application. This is where the game begins execution.
 */

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  qmlRegisterType<Tile>("Mahjong", 1, 0, "Tile");

  TileModel tileModel;
  Board board(&tileModel);
  board.generateTurtleLayout();  // Initialize the turtle layout

  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty("tileModel", &tileModel);
  engine.rootContext()->setContextProperty("board", &board);

  const QUrl url(QStringLiteral("src/qml/main.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
