/* @file Front_win.h
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

#ifndef FRONT_WIN_H
#define FRONT_WIN_H

#include <QtWidgets>


class Front_win : public QWidget
{

  Q_OBJECT

public:

  explicit Front_win(QWidget* parent = Q_NULLPTR);

private:

  void init();

  QGridLayout* grid_;

};

#endif // FRONT_WIN_H
