/** @file front_win.cpp
 *
 * @brief Simple main-window for tic tac toe frontend
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

#include "../hdr/front_win.h"

Front_win::Front_win(QWidget* parent) :
  QWidget(parent),
  grid_(new QGridLayout(this))
{
  init();
}

void Front_win::init()
{
  setWindowTitle("tic tac toe");
  grid_->setSpacing(2);
  grid_->setSizeConstraint(QLayout::SetFixedSize);
}
