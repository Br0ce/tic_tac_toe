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
          socket_, SLOT(user_move(const QByteArray)));

  connect(socket_, SIGNAL(ai_move_signal(int)),
          gui_, SLOT(ai_move(int)));
}
