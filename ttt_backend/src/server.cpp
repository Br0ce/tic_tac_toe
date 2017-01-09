/** @file server.cpp
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

#include "hdr/server.h"

Server::Server(QObject* parent) :
  QObject(parent),
  server_(new QTcpServer(this)),
  session_(Q_NULLPTR)
{
  connect(server_, SIGNAL(newConnection()),
          this, SLOT(connection()));

  if(!server_->listen(QHostAddress::Any, 12345))
    hlp::info("ERROR: Server cannot start");
  else
    hlp::info("Server started");

  hlp::info("\nwaiting for connection ...\n");
}

void Server::connection()
{
  hlp::info("\n-- connected --\n");

  session_ = server_->nextPendingConnection();

  while(session_->waitForReadyRead())
  {
    hlp::info("recieved inquiry");

    emit to_engine_signal(session_->readAll());

    hlp::info("\nwaiting for next inquiry\n");

    connect(session_, SIGNAL(disconnected()),
            this, SLOT(session_disconnected()));
  }
}

void Server::next_move(QByteArray a)
{
  hlp::info("\nsending next move");

  session_->write(a);
  session_->flush();
}

void Server::session_disconnected()
{
  hlp::info("-- disconnected --");
  hlp::info("\nwaiting for connection ...");
}
