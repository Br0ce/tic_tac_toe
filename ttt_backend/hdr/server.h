/** @file server.h
 *
 * @brief Class to handle networktraffic / inquiry from ttt_frontend
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

#ifndef SERVER_H
#define SERVER_H

#include <iostream>

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>


class Server : public QObject
{

  Q_OBJECT

public:

  explicit Server(QObject* parent = Q_NULLPTR);

signals:

  void to_engine_signal(QByteArray a);

public slots:

  void connection();
  void session_disconnected();
  void next_move(QByteArray a);

private:

  void info(const char* c)
  { std::cout << c << "\n"; }

  QTcpServer* server_;
  QTcpSocket* session_;

};

#endif // SERVER_H
