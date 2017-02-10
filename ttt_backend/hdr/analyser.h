/** 
 * @file analyser.h
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

#ifndef TICTACTOE_ANALYSER_H
#define TICTACTOE_ANALYSER_H

#include <chrono>

#include "../../ttt_lib/hdr/helper.h"


class Analyser
{

  using clock = std::chrono::high_resolution_clock;
  using time_unit = std::chrono::nanoseconds;

public:

  explicit Analyser(const std::size_t* cnt_ptr);

  ~Analyser();

  void start_clock();
  void stop_clock();

  double get_duration() const;
  std::size_t get_iterations() const;

private:

  clock clock_;
  std::chrono::time_point<clock> start_;
  std::chrono::time_point<clock> end_;
  bool is_started_;
  bool is_stopped_;
  const size_t* cnt_ptr_;

};


#endif //TICTACTOE_ANALYSER_H
