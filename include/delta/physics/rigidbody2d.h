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
    SHAPE_POINT,
} SHAPE;

typedef struct {
    double radius;
    vec2 center;
} Circle;

// Only position makes this useless ? Make all non-shaped bodies point objects be default ?
typedef struct {
    vec2 position;
} Point;

#endif /* RIGIDBODY2D_H */