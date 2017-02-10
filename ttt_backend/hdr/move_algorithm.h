/** @file move_algorithm.h
 *
 * @brief State - pattern
 *
 * Copyright (C) 2016  @author Niklas Beck, beck@informatik.uni-bonn.de
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

#ifndef MOVE_ALGORITHM_H
#define MOVE_ALGORITHM_H

#include <memory>
#include <iostream>

#include "defines.h"
#include "../hdr/pitch.h"
#include "../hdr/analyser.h"


class Move_algorithm
{
public:

  Move_algorithm() : cnt_(0) {}
  virtual ~Move_algorithm() = default;

  Index best_move(Pitch& p);
  virtual Index compute_move(Pitch& p) = 0;
  Value get_value(const Player& player, const Pitch& pitch) const;

  static std::unique_ptr<Move_algorithm> make_algo(const Algo& a);

  void reset_cnt()
  { cnt_ = 0; }

  void inc_cnt()
  { cnt_++; }

  const std::size_t* get_cnt_ptr() const
  { return  &cnt_; }

private:

  std::size_t cnt_;
};

#endif // MOVE_ALGORITHM_H
