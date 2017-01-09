/** @file helper.cpp
 *
 * @brief Collection of helping-fkt
 *
 * Copyright (C) 2016  Niklas Beck, beck@informatik.uni-bonn.de
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

#include "../hdr/helper.h"


void hlp::info(const char* c)
{ std::cout << c << "\n"; }


bool hlp::is_win(const Player& p, const std::string& s)
{
  char c = 'o';

  if(p == Player::user)
    c = 'x';

  if(s.at(0) == c  && s.at(1) == c  && s.at(2) == c)
    return true;

  if(s.at(0) == c  && s.at(3) == c  && s.at(6) == c)
    return true;

  if(s.at(0) == c  && s.at(4) == c  && s.at(8) == c)
    return true;

  if(s.at(1) == c  && s.at(4) == c  && s.at(7) == c)
    return true;

  if(s.at(2) == c  && s.at(5) == c  && s.at(8) == c)
    return true;

  if(s.at(2) == c  && s.at(4) == c  && s.at(6) == c)
    return true;

  if(s.at(3) == c  && s.at(4) == c  && s.at(5) == c)
    return true;

  if(s.at(6) == c  && s.at(7) == c  && s.at(8) == c)
    return true;

  return false;
}

bool hlp::is_draw(const std::string& s)
{ return (s.find("-") == std::string::npos); }
