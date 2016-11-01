/** @file action.cpp
 *
 * Copyright (C) 2016  @author Niklas Beck, beck@informatik.uni-bonn.de
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

#ifndef ACTION_H
#define ACTION_H

#include "defines.h"


class Action
{
public:

  Action();
  explicit Action(Index id, Value v);

  bool operator<(const Action& r) const
  { return value_ < r.get_value(); }

  bool operator>(const Action& r) const
  { return value_ > r.get_value(); }

  void set_index(Index id)
  { index_ = id; }

  void set_value(Value v)
  { value_ = v; }

  Index get_index() const
  { return index_; }

  Value get_value() const
  { return value_; }

private:

  Index index_;
  Value value_;

};


#endif // ACTION_H
