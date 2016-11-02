/** @file socket.cpp
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

#include "../hdr/socket.h"

Socket::Socket(QObject* parent) :
  QObject(parent),
  socket_(new QTcpSocket(this))
{
  connect(socket_, SIGNAL(connected()),
          this, SLOT(socket_connected()));
  connect(socket_, SIGNAL(disconnected()),
          this, SLOT(socket_disconnected()));
  connect(socket_, SIGNAL(readyRead()),
          this, SLOT(reading()));

  info("connecting ...");

  socket_->connectToHost("127.0.0.1", 12345);
  if(!socket_->waitForConnected(3000))
  {
    info("ERROR: ");
    std::cout << socket_->errorString().toStdString() << "\n";
  }
}

void Socket::socket_connected()
{
  info("connected");
}

void Socket::socket_disconnected()
{
  info("disconnected");
}

void Socket::reading()
{
  info("reading ...");

  //TODO check message
  auto tmp = socket_->readAll().toInt();
  emit ai_move_signal(tmp);

  info("received ai move");
}

void Socket::user_move(const QByteArray a)
{
  info("sending inquiry");

  socket_->write(a);
  socket_->flush();
}
