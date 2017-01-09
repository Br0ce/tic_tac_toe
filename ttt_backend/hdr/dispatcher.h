/** @file dispacher.h
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

#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <iostream>

#include <QObject>

#include "../hdr/server.h"
#include "../hdr/engine.h"
#include "../../ttt_lib/hdr/helper.h"


class Dispatcher : public QObject
{

  Q_OBJECT

public:

  explicit Dispatcher(const char* arg, QObject* parent = Q_NULLPTR);


private:

  Server* server_;
  Engine* engine_;

};

#endif // DISPATCHER_H
