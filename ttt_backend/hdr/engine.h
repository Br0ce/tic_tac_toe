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
#include <cstring>
#include <vector>
#include <algorithm>
#include <memory>

#include <QObject>
#include <QDebug>

#include "../hdr/pitch.h"
#include "../hdr/action.h"
#include "../hdr/move_algorithm.h"
#include "defines.h"
#include "../../ttt_lib/hdr/helper.h"


class Engine : public QObject
{

  Q_OBJECT

public:

  explicit Engine(QObject* parent = Q_NULLPTR);

  Action compute_next_ai_move();
  Action compute_next_user_move();
  Value get_value(const Player& p) const;
  void set_move_algo(const char* c);

signals:

  void next_move_signal(QByteArray);

public slots:

  void incoming_inquiry(QByteArray a);

private:

  void reset_cnt()
  { cnt_ = 0; }

  void shuffle_actions();

  Pitch pitch_;
  std::unique_ptr<Move_algorithm> move_algo_;
  std::size_t cnt_;
  std::vector<Index> actions_;
  std::default_random_engine dre_;
  std::random_device rd_;

};

#endif // ENGINE_H
