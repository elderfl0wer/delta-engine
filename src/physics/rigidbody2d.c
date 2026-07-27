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
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../include/delta/math/vector3.h"
#include "../../include/delta/math/vector2.h"
#include "../../include/delta/physics/rigidbody2d.h"
#include "../../include/delta/constants.h"

// --------------------- General ------------------------------ //

void rb2d_apply_force(RigidBody2D *rb, vec2 force)
{
    rb->force.x += force.x;
    rb->force.y += force.y;
}

void rb2d_update_position(RigidBody2D *rb, double dt)
{
    double accel_x = rb->force.x / rb->mass;
    double accel_y = rb->force.y / rb->mass;

    rb->velocity.x += accel_x * dt;
    rb->velocity.y += accel_y * dt;

    rb->position.x += rb->velocity.x * dt;
    rb->position.y += rb->velocity.y * dt;

    rb->force.x = 0;
    rb->force.y = 0;
}

void rb2d_apply_accel(RigidBody2D *rb, vec2 accel)
{
    rb->acceleration.x += accel.x;
    rb->acceleration.y += accel.y;
}

void rb2d_object_destroy(RigidBody2D **rb)
{
    if (rb == NULL || *rb == NULL) return;

    free(*rb);
    *rb = NULL;
}

bool rb2d_check_collision(RigidBody2D *a, RigidBody2D *b)
{
    return vec2_distance(&a->position, &b->position) <= COLLISION_SEPERATION ? true : false;
}

// --------------------- Gravity ------------------------------ //

void rb2d_accumulate_gravity(RigidBody2D *rb)
{
    if (rb == NULL) return; 

    rb->force.y += rb->mass * FREE_FALL_ACCEL;
}

void rb2d_object_gravity(RigidBody2D *a, RigidBody2D *b)
{
    if (a == NULL) return;
    if (b == NULL) return;

    double object_seperation = vec2_distance(&a->position, &b->position);

    double force_magnitude = GRAVITATIONAL_CONSTANT * ((a->mass * b->mass) / pow(object_seperation, 2));

    vec2 force_point = {(a->position.x*a->mass + b->position.x*b->mass) / (a->mass+b->mass), (a->position.y*a->mass + b->position.y*b->mass) / (a->mass+b->mass)};
    const double force_point_length = vec2_length(&force_point);
    if (object_seperation < COLLISION_SEPERATION) return;

    a->force.x += force_magnitude * (force_point.x / force_point_length);
    a->force.y += force_magnitude * (force_point.y / force_point_length);

    b->force.x -= force_magnitude * (force_point.x / force_point_length);
    b->force.y -= force_magnitude * (force_point.y / force_point_length);
}

// -------------------Electrical Force------------------------- //

void rb2d_coloumb_force(RigidBody2D *a, RigidBody2D *b)
{
    if (a == NULL) return;
    if (b == NULL) return;

    double object_seperation = vec2_distance(&a->position, &b->position);

    double force_magnitude = COLOUMB_CONSTANT * ((a->charge * b->charge) / pow(object_seperation, 2));

    vec2 force_point = {(a->position.x*a->mass + b->position.x*b->mass) / (a->mass+b->mass), (a->position.y*a->mass + b->position.y*b->mass) / (a->mass+b->mass)};
    const double force_point_length = vec2_length(&force_point);
    if (object_seperation < COLLISION_SEPERATION) return;

    a->force.x += force_magnitude * (force_point.x / force_point_length);
    a->force.y += force_magnitude * (force_point.y / force_point_length);

    b->force.x -= force_magnitude * (force_point.x / force_point_length);
    b->force.y -= force_magnitude * (force_point.y / force_point_length);

}
