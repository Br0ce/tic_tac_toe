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
  pitch_()
{
  info("Engine started");
}

void Engine::incoming_inquiry(QByteArray a)
{
  info("processing ...");

  try
  {
    pitch_.set_pitch(a.constData());
    info("inquiry correct: ");
    info(a.constData());
    const auto a = QByteArray::number(best_move());
    emit next_move_signal(a);
  }
  catch(std::exception& e)
  {

  }
}

Action Engine::compute_next_move(const Player& p)
{
  if(pitch_.is_win(Player::ai))
    return Action(get_value(Player::ai), 0);

  if(pitch_.is_win(Player::user))
    return Action(get_value(Player::user), 0);

  if(pitch_.is_draw())
    return Action(0, 0);

  Action a;
  for(const auto& id : actions())
  {
    if(pitch_.is_free(id))
    {
      pitch_.move(id, p);

      if(p == Player::user)
      {
        Action tmp(compute_next_move(Player::ai));
        tmp.set_index(id);
        a = std::min(a, tmp);
      }
      else
      {
        Action tmp(compute_next_move(Player::user));
        tmp.set_index(id);
        a = std::max(a, tmp);
      }
      pitch_.un_move(id);
    }
  }

  return a;
}

Index Engine::best_move()
{
  return compute_next_move(Player::ai).get_index();
}

std::vector<Index> Engine::actions()
{
  std::vector<Index> tmp(8);
  for(Index i = 0; i < Pitch_size; ++i)
    tmp.at(i) = i;

  return tmp;
}

Value Engine::get_value(const Player& p) const
{
  if(p == Player::ai)
    return 10 - pitch_.get_depth();
  else
    return -(10 - pitch_.get_depth());
}
