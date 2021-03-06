/** @file defines.h
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

#ifndef DEFINES_H
#define DEFINES_H

#include <inttypes.h>

using Index = uint32_t;
using Value = int64_t;

constexpr Value Max_value = INT64_MAX;
constexpr Value Min_value = INT64_MIN;
constexpr Index Pitch_size = 9;

enum class State { free, cross, circle };
enum class Player { user, ai };
enum class Algo { min_max, alpha_beta };

#endif // DEFINES_H
