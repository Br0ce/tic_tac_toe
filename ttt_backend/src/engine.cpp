/** @file engine.cpp
 *
 * @brief Ai to run tic tac toe game
 *
 * Copyright (C) 2016  Niklas Beck, beck@informatik.uni-bonn.de
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

#include "../hdr/engine.h"

Engine::Engine(QObject* parent) :
  QObject(parent),
  pitch_(),
  move_algo_(Move_algorithm::make_algo(Algo::alpha_beta))
{
  std::iota(actions_.begin(), actions_.end(), 0);
  hlp::info("Engine started");
}

void Engine::incoming_inquiry(QByteArray a)
{
  hlp::info("processing ...");

  try
  {
    pitch_.set_pitch(a.constData());
    hlp::info("inquiry correct: ");
    hlp::info(a.constData());
    const auto id = QByteArray::number(move_algo_->best_move(pitch_));

    emit next_move_signal(id);
  }
  catch(std::exception& e)
  {
    hlp::info("ERROR: inquiry incorrect");
  }
}

void Engine::set_move_algo(const char* c)
{
  if(std::strcmp(c, "-mm") == 0)
  {
    move_algo_ = Move_algorithm::make_algo(Algo::min_max);
    hlp::info("Search-Algorithm: Min-Max");
  }
  else if(std::strcmp(c, "-ab") == 0)
  {
    hlp::info("Search-Algorithm: Alpha-Beta");
  }
  else
  {
    hlp::info("ERROR: cannot parse argument - use default");
    hlp::info("Search-Algorithm: Alpha-Beta");
  }
}
