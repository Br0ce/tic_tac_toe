/** @file min_max.h
 *
 * @brief Concrete move_algorithm
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

#ifndef MIN_MAX_H
#define MIN_MAX_H

#include "../hdr/move_algorithm.h"
#include "../hdr/pitch.h"
#include "../hdr/action.h"
#include "defines.h"


class Min_max : public Move_algorithm
{
public:

  Min_max() = default;
  ~Min_max() = default;

  Index best_move(Pitch& p) override;

  Action compute_next_ai_move(Pitch& p);
  Action compute_next_user_move(Pitch& p);

};

#endif // MIN_MAX_H
