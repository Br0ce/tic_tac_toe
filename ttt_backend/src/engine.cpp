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
  cnt_(0)
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
    info("ERROR: inquiry incorrect");
  }
}

Action Engine::compute_next_ai_move()
{
  cnt_++;
  if(pitch_.is_win(Player::ai))
    return Action(0, get_value(Player::ai));

  if(pitch_.is_win(Player::user))
    return Action(0, get_value(Player::user));

  if(pitch_.is_draw())
    return Action(0, 0);

  Action a(0, -1000);
  for(Index id = 0; id < Pitch_size; ++id)
  {
    if(pitch_.is_free(id))
    {
      pitch_.move(id, Player::ai);
      Action tmp(compute_next_user_move());
      tmp.set_index(id);
      a = std::max(a, tmp);
      pitch_.un_move(id);
    }
  }
  return a;
}

Action Engine::compute_next_user_move()
{
  cnt_++;
  if(pitch_.is_win(Player::user))
    return Action(0, get_value(Player::user));

  if(pitch_.is_win(Player::ai))
    return Action(0, get_value(Player::ai));

  if(pitch_.is_draw())
    return Action(0, 0);

  Action a(0, 1000);
  for(Index id = 0; id < Pitch_size; ++id)
  {
    if(pitch_.is_free(id))
    {
      pitch_.move(id, Player::user);
      Action tmp(compute_next_ai_move());
      tmp.set_index(id);
      a = std::min(a, tmp);
      pitch_.un_move(id);
    }
  }
  return a;
}

Index Engine::best_move()
{
  reset_cnt();
  auto id = compute_next_ai_move().get_index();
  info("evaluated: ");
  std::cout << cnt_ << "\n";
  return id;
}

std::vector<Index> Engine::actions()
{
  std::vector<Index> tmp(9);
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
