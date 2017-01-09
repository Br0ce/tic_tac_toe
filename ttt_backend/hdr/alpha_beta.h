/** @file Alpha_beta.h
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

#ifndef ALPHA_BETA_H
#define ALPHA_BETA_H

#include <algorithm>
#include <random>

#include "../hdr/move_algorithm.h"
#include "../hdr/action.h"
#include "defines.h"
#include "../../ttt_lib/hdr/helper.h"

class Alpha_beta : public Move_algorithm
{
public:

  Alpha_beta();
  ~Alpha_beta() = default;

  Index best_move(Pitch& p) override;

  Action compute_next_ai_move(Pitch& p, int64_t alpha, int64_t beta);
  Action compute_next_user_move(Pitch& p, int64_t alpha, int64_t beta);

private:

  std::vector<Index> get_actions();
  void shuffle_actions();

  std::vector<Index> actions_;
  std::default_random_engine rand_engine_;
  std::random_device seed_;

};

#endif // ALPHA_BETA_H
