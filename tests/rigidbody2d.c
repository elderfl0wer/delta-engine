#include <stdio.h>
#include <stdbool.h>

#include "../include/delta/physics/rigidbody2d.h"
#include "../include/delta/math/vector3.h"


int main(void)
{
    RigidBody2D rb;
    rb.position.x = 1;
    rb.position.y = 2;

    do {
        vec2 gravity = {0.0f, -9.81f};

        rb2d_apply_force(&rb, gravity);



        rb2d_update_position(&rb, 0.1f);
    } while (true);
}