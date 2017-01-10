/** @file session_handler.h
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

#ifndef SESSION_HANDLER_H
#define SESSION_HANDLER_H

#include <QObject>

#include "../hdr/front_win.h"
#include "../hdr/socket.h"
#include "../../ttt_lib/hdr/helper.h"


class Session_handler : public QObject
{

  Q_OBJECT

public:

  explicit Session_handler(Front_win* gui,
                           QObject* parent = Q_NULLPTR);

signals:

  void user_move_signal_good(const QByteArray);
  void ai_move_signal_good(int);

private slots:

  void check_user_move(const QByteArray b);
  void check_ai_move(int id);

private:

  void display_result(const char* c) const;

  Front_win* gui_;
  Socket* socket_;

};

#endif // SESSION_HANDLER_H
