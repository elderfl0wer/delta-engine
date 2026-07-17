#ifndef VECTOR3_H
#define VECTOR3_H

#include "vector2.h"

typedef struct {
    double x;
    double y;
    double z;
} vec3;

vec3 vec3_from_vec2(vec2 *v);

#endif /* VECTOR3_H */
