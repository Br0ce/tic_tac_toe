/** @file alpha_beta.cpp
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

#include "../hdr/alpha_beta.h"

Alpha_beta::Alpha_beta() :
  actions_(9),
  rand_engine_(),
  seed_()
{
  std::iota(actions_.begin(), actions_.end(), 0);
}

Index Alpha_beta::best_move(Pitch& p)
{
  reset_cnt();
  auto id = compute_next_ai_move(p, Min_value, Max_value).get_index();
  cnt_out();

  return id;
}

Action Alpha_beta::compute_next_ai_move(Pitch& p, int64_t alpha, int64_t beta)
{
  inc_cnt();

  if(p.is_win(Player::ai))
    return Action(0, get_value(Player::ai, p));

  if(p.is_win(Player::user))
    return Action(0, get_value(Player::user, p));

  if(p.is_draw())
    return Action(0, 0);

  Action a(0, Min_value);

  for(const auto& id : get_actions())
  {
    if(p.is_free(id))
    {
      p.move(id, Player::ai);
      Action tmp(compute_next_user_move(p, alpha, beta));
      tmp.set_index(id);
      a = std::max(a, tmp);

      if(a.get_value() >= beta)
      {
        p.un_move(id);
        break;
      }

      alpha = std::max(alpha, a.get_value());
      p.un_move(id);
    }
  }
  return a;
}

Action Alpha_beta::compute_next_user_move(Pitch& p, int64_t alpha, int64_t beta)
{
  inc_cnt();

  if(p.is_win(Player::user))
    return Action(0, get_value(Player::user, p));

  if(p.is_win(Player::ai))
    return Action(0, get_value(Player::ai, p));

  if(p.is_draw())
    return Action(0, 0);

  Action a(0, Max_value);

  for(const auto& id : get_actions())
  {
    if(p.is_free(id))
    {
      p.move(id, Player::user);
      Action tmp(compute_next_ai_move(p, alpha, beta));
      tmp.set_index(id);
      a = std::min(a, tmp);

      if(a.get_value() <= alpha)
      {
        p.un_move(id);
        break;
      }

      beta = std::min(beta, a.get_value());
      p.un_move(id);
    }
  }
  return a;
}

void Alpha_beta::shuffle_actions()
{
  rand_engine_.seed(seed_());
  std::shuffle(actions_.begin(), actions_.end(), rand_engine_);
}

std::vector<Index> Alpha_beta::get_actions()
{
  rand_engine_.seed(seed_());
  auto v = actions_;
  std::shuffle(v.begin(), v.end(), rand_engine_);
  return v;
}
