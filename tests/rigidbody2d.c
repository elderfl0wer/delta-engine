#include <stdbool.h>
#include <stdio.h>

#include "../include/delta/constants.h"
#include "../include/delta/physics/rigidbody2d.h"
#include "../include/delta/math/vector2.h"

#define UPDATE_TIME 0.1

int main(void)
{
    int i = 0; 

    RigidBody2D b1;
    b1.mass = 10;
    b1.position.x = 10; b1.position.y = 20;
    b1.force.x = 0; b1.force.y = 5;

    do {
        printf("b1's initial position is (%f, %f)\n", b1.position.x, b1.position.y);

        rb2d_accumulate_gravity(&b1);

        printf("b1's final position is (%f, %f)\n", b1.position.x, b1.position.y);

        rb2d_update_position(&b1, UPDATE_TIME);
        i += 1;
    } while (i < 1);
}
