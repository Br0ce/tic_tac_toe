/** @file socket.h
 *
 * @brief Class to establish communication to backend
 *
 * Copyright (C) 2016  @author Niklas Beck, beck@informatik.uni-bonn.de
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

#ifndef SOCKET_H
#define SOCKET_H

#include <iostream>

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>


class Socket : public QObject
{

  Q_OBJECT

public:

  explicit Socket(QObject* parent = Q_NULLPTR);

signals:

  void ai_move_signal(int);

public slots:

  void socket_connected();
  void socket_disconnected();
  void reading();
  void user_move(const QByteArray a);

private:

  void info(const char* i)
  { std::cout << i << "\n"; }

  QTcpSocket* socket_;
};

#endif // SOCKET_H
