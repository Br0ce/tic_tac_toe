/** @file field.cpp
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

#include "../hdr/field.h"

Field::Field(const Index id, QWidget* parent) :
  QTextEdit(parent),
  id_(id),
  state_(State::free)
{
  init_gui();
}

void Field::init_gui()
{
  setReadOnly(true);
  setFontPointSize(100);
}

QSize Field::sizeHint() const
{
  QSize s = QTextEdit::sizeHint();

  s.rheight() += 20;
  s.rwidth() = std::max(s.width(), s.height());

  return s;
}

void Field::mousePressEvent(QMouseEvent* e)
{
  QTextEdit::mousePressEvent(e);

  if(state() == State::free)
  {
    set_cross();
    emit field_pressed_signal(id_);
  }
}

void Field::set_cross()
{
  set_state(State::cross);
  setText("X");
  setAlignment(Qt::AlignCenter);
}

void Field::set_circle()
{
  set_state(State::circle);
  setText("O");
  setAlignment(Qt::AlignCenter);
}
