/** 
 * @file analyser.cpp
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

#include "hdr/analyser.h"


Analyser::Analyser(const std::size_t* cnt_ptr) :
  clock_(),
  start_(),
  end_(),
  is_started_(false),
  is_stopped_(false),
  cnt_ptr_(cnt_ptr)
{}

void Analyser::start_clock()
{
  is_started_ = true;
  start_ = clock_.now();
}

void Analyser::stop_clock()
{
  end_ = clock_.now();
  is_stopped_ = true;
  is_started_ = false;
}

double Analyser::get_duration() const
{
  if(is_stopped_)
  {
    return std::chrono::duration_cast<time_unit>
        (end_ - start_).count();
  }
  else return 0;
}

std::size_t Analyser::get_iterations() const
{ return *cnt_ptr_ ; }

Analyser::~Analyser()
{
  std::cout << "\nevaluated "
            << *cnt_ptr_
            << " moves";

  if(is_started_ && !is_stopped_)
  {
    std::cout << " in "
              << std::chrono::duration_cast<time_unit>
                  (clock_.now() - start_).count()
              << " ns\n";
  }
}
