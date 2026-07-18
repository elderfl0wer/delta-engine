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

#include "../../include/delta/math/vector3.h"
#include "../../include/delta/math/vector2.h"

vec3 vec3_from_vec2(vec2 *v)
{
    vec3 ans = {v->x, v->y, 0};
    return ans;
}

double vec3_length(vec3 *v)
{
    double ans = sqrt(v->x*v->x + v->y*v->y + v->z*v->z);
    return ans;
}

vec3 vec3_add(vec3 *a, vec3 *b)
{
    vec3 ans = {a->x+b->x, a->y+b->y, a->z+b->z};
    return ans;
}

vec3 vec3_subtract(vec3 *a, vec3 *b)
{
    vec3 ans = {a->x-b->x, a->y-b->y, a->z-b->z};
    return ans;
}

vec3 vec3_normalize(vec3 *v)
{
    double magnitude = vec3_length(v);
    vec3 ans = {v->x / magnitude, v->y / magnitude, v->z / magnitude};
    return ans;
}

vec3 vec3_scale(vec3 *v, const double factor)
{
    vec3 ans = {v->x * factor, v->y * factor, v->z * factor};
    return ans;
}

double vec3_distance(vec3 *a, vec3 *b)
{
    vec3 ans = vec3_subtract(a, b);
    return vec3_length(&ans);
}

double vec3_dot(vec3 *a, vec3 *b)
{
    double ans = a->x*b->x + a->y*b->y + a->z*b->z;
    return ans;
}

vec3 vec3_cross(vec3 *a, vec3 *b)
{
    vec3 ans = {a->y*b->z - b->y*a->z, b->x*a->z - a->x*b->z, a->x*b->y - b->x*a->y};
    return ans;
}
