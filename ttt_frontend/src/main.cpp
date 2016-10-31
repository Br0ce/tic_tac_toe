#include <QApplication>
#include <QMainWindow>

#include "../hdr/front_win.h"
#include "../hdr/session_handler.h"


int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  Front_win* gui = new Front_win;
  gui->show();
  Session_handler handler(gui);

  return app.exec();
}
