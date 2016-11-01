/** @file pitch.cpp
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

#include "../hdr/pitch.h"


Pitch::Pitch(const char* c) :
  state_(c)
{
  if(!is_pitch(state_))
    throw std::runtime_error("ERROR: pitch incorrect");

  init_win_configs();
}

bool Pitch::is_pitch(const std::string& s) const
{
  if(s.size() != 9)
    return false;

  if(s.find_first_not_of("xo-") != std::string::npos)
    return false;

  return true;
}

void Pitch::set_pitch(const char* c)
{
  if(is_pitch(c))
    state_ = c;
  else
    throw std::runtime_error("ERROR: inquiry incorrect");
}

bool Pitch::is_free(Index id) const
{
  if(!is_index(id))
    throw std::runtime_error("ERROR: index incorrect");

  if(state_.at(id) != '-')
    return false;
  else
    return true;
}

void Pitch::init_win_configs()
{
  win_configs_.push_back({0, 1, 2});
  win_configs_.push_back({0, 3, 6});
  win_configs_.push_back({0, 4, 8});
  win_configs_.push_back({1, 4, 7});
  win_configs_.push_back({2, 5, 8});
  win_configs_.push_back({2, 4, 6});
  win_configs_.push_back({3, 4, 5});
  win_configs_.push_back({6, 7, 8});
}

bool Pitch::is_win(const Player& p) const
{
  char c = 'o';

  if(p == Player::user)
    c = 'x';

  for(const auto& config : win_configs_)
  {
    if(state_.at(config.at(0)) == c
        && state_.at(config.at(1)) == c
        && state_.at(config.at(2)) == c)
    {
      return true;
    }
  }

  return false;
}

bool Pitch::is_draw() const
{
  return (state_.find("-") == std::string::npos);
}

int Pitch::get_depth() const
{
  return Pitch_size - std::count(state_.cbegin(), state_.cend(), '-');
}

void Pitch::move(Index id, const Player& p)
{
  if(p == Player::ai)
    state_.at(id) = 'o';
  else
    state_.at(id) = 'x';
}
