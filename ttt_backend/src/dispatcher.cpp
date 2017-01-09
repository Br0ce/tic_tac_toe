/** @file dispacher.h
 *
 * Copyright (C) 2016 @author Niklas Beck, beck@informatik.uni-bonn.de
 *
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

#include "../hdr/dispatcher.h"

Dispatcher::Dispatcher(const char* arg, QObject* parent) :
  QObject(parent),
  server_(new Server(this)),
  engine_(new Engine(this))
{
  hlp::info("Dispatcher started");

  if(arg == nullptr)
    hlp::info("Search-Algorithm: Alpha-Beta");
  else
    engine_->set_move_algo(arg);

  connect(server_, SIGNAL(to_engine_signal(QByteArray)),
          engine_, SLOT(incoming_inquiry(QByteArray)));

  connect(engine_, SIGNAL(next_move_signal(QByteArray)),
          server_, SLOT(next_move(QByteArray)));
}
