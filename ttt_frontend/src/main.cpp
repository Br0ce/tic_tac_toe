#include <QApplication>
#include <QMainWindow>

#include "../hdr/front_win.h"


int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  Front_win w;
  w.show();

  return app.exec();
}
