/** @file min_max.cpp
 *
 *
 * Copyright (C) 2016 @author Niklas Beck, beck@informatik.uni-bonn.de
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

#include "../hdr/min_max.h"


Index Min_max::best_move(Pitch& p)
{
  reset_cnt();
  auto id = compute_next_ai_move(p).get_index();
  cnt_out();
  return id;
}


Action Min_max::compute_next_ai_move(Pitch& p)
{
  inc_cnt();
  if(p.is_win(Player::ai))
    return Action(0, get_value(Player::ai, p));

  if(p.is_win(Player::user))
    return Action(0, get_value(Player::user, p));

  if(p.is_draw())
    return Action(0, 0);

  Action a(0, Min_value);
  for(Index id = 0; id < Pitch_size; ++id)
  {
    if(p.is_free(id))
    {
      p.move(id, Player::ai);
      Action tmp(compute_next_user_move(p));
      tmp.set_index(id);
      a = std::max(a, tmp);
      p.un_move(id);
    }
  }
  return a;
}

Action Min_max::compute_next_user_move(Pitch& p)
{
  inc_cnt();
  if(p.is_win(Player::user))
    return Action(0, get_value(Player::user, p));

  if(p.is_win(Player::ai))
    return Action(0, get_value(Player::ai, p));

  if(p.is_draw())
    return Action(0, 0);

  Action a(0, Max_value);
  for(Index id = 0; id < Pitch_size; ++id)
  {
    if(p.is_free(id))
    {
      p.move(id, Player::user);
      Action tmp(compute_next_ai_move(p));
      tmp.set_index(id);
      a = std::min(a, tmp);
      p.un_move(id);
    }
  }
  return a;
}
