#include <QApplication>

#include "../hdr/dispatcher.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  Dispatcher d;

  return app.exec();
}
