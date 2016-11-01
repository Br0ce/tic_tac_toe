/** @file engine.h
 *
 * @brief Ai to run tic tac toe game
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

#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <vector>

#include <QObject>
#include <QDebug>

#include "../hdr/pitch.h"
#include "../hdr/action.h"
#include "defines.h"


class Engine : public QObject
{

  Q_OBJECT

public:

  explicit Engine(QObject* parent = Q_NULLPTR);

  Action compute_next_move(const Player& p);
  Index best_move();
  std::vector<Index> actions();
  Value get_value(const Player& p) const;

signals:

  void next_move_signal(QByteArray);

public slots:

  void incoming_inquiry(QByteArray a);

private:

  void info(const char* c)
  { std::cout << c << "\n"; }

  Pitch pitch_;

};

#endif // ENGINE_H
