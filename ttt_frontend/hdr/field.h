/** @file field.h
 *
 * @brief Smallest Unit on tic tac toe pitch
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

#ifndef FIELD_H
#define FIELD_H

#include <QTextEdit>

#include "defines.h"

class Field : public QTextEdit
{

  Q_OBJECT


public:

  Field(const Index id, QWidget* parent = Q_NULLPTR);

  QSize sizeHint() const override;

  void set_state(State s)
  { state_ = s; }

  State get_state() const
  { return state_; }

  void set_cross();
  void set_circle();

signals:

  void field_pressed_signal();

protected:

  void mousePressEvent(QMouseEvent* e) override;

private:

  void init_gui();

  Index id_;
  State state_;
};

#endif // FIELD_H
