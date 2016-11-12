#include <iostream>
#include <QApplication>

#include "../hdr/dispatcher.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  Dispatcher d(argv[1]);

  return app.exec();
}
