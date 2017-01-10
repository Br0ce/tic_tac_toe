/** @file session_handler.cpp
 *
 * Copyright (C) 2016  Niklas Beck, beck@informatik.uni-bonn.de
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "../hdr/session_handler.h"

Session_handler::Session_handler(Front_win* gui, QObject* parent) :
  QObject(parent),
  gui_(gui),
  socket_(new Socket(this))
{
  connect(gui_, SIGNAL(user_move_signal(const QByteArray)),
          this, SLOT(check_user_move(const QByteArray)));

  connect(this, SIGNAL(user_move_signal_good(const QByteArray)),
          socket_, SLOT(user_move(const QByteArray)));

  connect(socket_, SIGNAL(ai_move_signal(int)),
          this, SLOT(check_ai_move(int)));

  connect(this, SIGNAL(ai_move_signal_good(int)),
          gui_, SLOT(ai_move(int)));
}

void Session_handler::check_ai_move(int id)
{
  auto s = gui_->get_pitch_status().toStdString();
  s[id] = 'o';

  emit ai_move_signal_good(id);

  if(hlp::is_win(Player::ai, s))
    display_result("O won");
  else if(hlp::is_draw(s))
    display_result("draw");
}

void Session_handler::check_user_move(const QByteArray b)
{
  if(hlp::is_win(Player::user, b.toStdString()))
    display_result("X won");
  else if(hlp::is_draw(b.toStdString()))
    display_result("draw");
  else
    emit user_move_signal_good(b);
}

void Session_handler::display_result(const char* c) const
{
  QMessageBox msb;
  QPushButton* new_game = msb.addButton(tr("new Game"), QMessageBox::AcceptRole);
  QPushButton* quit = msb.addButton(tr("quit"), QMessageBox::RejectRole);
  msb.setDefaultButton(new_game);
  msb.setText(tr(c));
  int ret = msb.exec();

  if(msb.clickedButton() == new_game)
    gui_->clear_pitch();
  else
    gui_->close();
}
