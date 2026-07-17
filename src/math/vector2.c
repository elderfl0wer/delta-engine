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

#include "../../include/delta/math/vector2.h"
#include "../../include/delta/math/vector3.h"

vec2 vec2_add(vec2 *a, vec2 *b)
{
    vec2 ans = {a->x+b->x, a->y+b->y};
    return ans;
}

vec2 vec2_subtract(vec2 *a, vec2 *b)
{
    vec2 ans = {a->x+b->x, a->y+b->y};
    return ans;
}

double vec2_length(vec2 *a)
{
    return sqrt(a->x*a->x + a->y*a->y);
}

vec2 vec2_normalize(vec2 *a)
{
    double magnitude = vec2_length(a);
    vec2 ans = {a->x / magnitude, a->y / magnitude};
    return ans;
}

vec2 vec2_scale(vec2 *v, const double factor)
{
    vec2 ans = {v->x * factor, v->y * factor};
    return ans;
}

double vec2_dot(vec2 *a, vec2 *b)
{
    return (a->x * b->x) + (a->y * b->y);
}

vec3 vec2_cross(vec2 *a, vec2 *b)
{
    vec3 v1 = vec3_from_vec2(a);
    vec3 v2 = vec3_from_vec2(b);

    vec3 cross = {0, 0, (a->x*b->y) - (b->x*a->y)};
    double magnitude = vec3_length(&cross);
    vec3 ans = {0, 0, cross.z / magnitude};

    return ans;
}
