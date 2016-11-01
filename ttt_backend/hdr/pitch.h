/** @file pitch.h
 *
 * @brief Class to represent tic tac toe pitch
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

#ifndef PITCH_H
#define PITCH_H

#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

#include "defines.h"

class Pitch
{
public:

  Pitch(const char* c = "---------");

  void set_pitch(const char* c);
  bool is_free(Index id) const;
  bool is_win(const Player& p) const;
  bool is_draw() const;
  int get_depth() const;
  char at(Index id) const
  { return state_.at(id); }
  void move(Index id, const Player& p);
  void un_move(Index id)
  { state_.at(id) = '-'; }

private:

  bool is_index(Index id) const
  { return ((id > 0) && (id < Pitch_size)); }

  bool is_pitch(const std::string& s) const;
  void init_win_configs();

  std::string state_;
  std::vector<std::vector<Index>> win_configs_;
};

#endif // PITCH_H
