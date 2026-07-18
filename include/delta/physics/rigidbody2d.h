#ifndef RIGIDBODY2D_H
#define RIGIDBODY2D_H

#include "../math/vector2.h"

typedef struct {
    double mass;
    double inv_mass;

    vec2 position;
    vec2 velocity;
    vec2 acceleration;
    vec2 force; 
} RigidBody2D;

typedef enum {
    SHAPE_CIRCLE,
    SHAPE_BOX,
} SHAPE;

#endif /* RIGIDBODY2D_H */