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

void rb2d_apply_force(RigidBody2D *rb, vec2 force);
void rb2d_update_position(RigidBody2D *rb, double dt);
void rb2d_apply_accel(RigidBody2D *rb, vec2 accel);
void rb2d_accumulate_gravity(RigidBody2D *rb);

#endif /* RIGIDBODY2D_H */