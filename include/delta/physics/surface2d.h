#ifndef SURFACE2D_H
#define SURFACE2D_H

#include "../math/vector2.h"
#include "rigidbody2d.h"

typedef struct {
    vec2 vector;

    double restitution;
    double friction;
} Surface2D;

#endif /* SURFACE2D_H */
