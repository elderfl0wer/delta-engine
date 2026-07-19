/*
    Delta Physics Engine - Newtonian mechanics primarily in 2 dimensions.
    Copyright (C) 2026  Shreyaan Misra

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "../../include/delta/physics/rigidbody2d.h"
#include "../../include/delta/math/vector3.h"
#include "../../include/delta/math/vector2.h"

RigidBody2D rb2d_apply_force(RigidBody2D *rb, vec2 force)
{
  vec2 test = {5, 6};
  rb->position = test;

  return *rb;
} 
