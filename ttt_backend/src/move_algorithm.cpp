/** @file move_algorithm.cpp
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

#include "../hdr/move_algorithm.h"

#include "../hdr/min_max.h"
#include "../hdr/alpha_beta.h"

Value Move_algorithm::get_value(const Player& player, const Pitch& pitch) const
{
  if(player == Player::ai)
    return 10 - pitch.get_depth();
  else
    return -(10 - pitch.get_depth());
}

std::unique_ptr<Move_algorithm> Move_algorithm::make_algo(const Algo& a)
{
  std::unique_ptr<Move_algorithm> tmp(nullptr);

  if(a == Algo::min_max)
    tmp.reset(new Min_max);
  else if(a == Algo::alpha_beta)
    tmp.reset(new Alpha_beta);

  return tmp;
}
