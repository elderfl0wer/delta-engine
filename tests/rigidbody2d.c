#include <stdbool.h>
#include <stdio.h>

#include "../include/delta/constants.h"
#include "../include/delta/physics/rigidbody2d.h"
#include "../include/delta/math/vector2.h"

#define UPDATE_TIME 10

int main(void)
{
    RigidBody2D b1;
    b1.mass = 10000000;
    b1.charge = FUNDAMENTAL_CHARGE;
    b1.inv_mass = 1 / b1.mass;

    b1.position.x = 10; b1.position.y = 20;
    b1.velocity.x = 0; b1.velocity.y = 0;
    b1.acceleration.x = 0; b1.acceleration.y = 0;
    b1.force.x = 0; b1.force.y = 0;


    RigidBody2D b2;
    b2.mass = 900000000000;
    b2.charge = -FUNDAMENTAL_CHARGE;
    b2.position.x = 20; b1.position.y = 20;
    b2.velocity.x = 0; b1.velocity.y = 0;
    b2.acceleration.x = 0; b2.acceleration.y = 0;
    b2.force.x = 0; b2.force.y = 0;

    do {
        rb2d_update_position(&b1, UPDATE_TIME);
        printf("b1's initial position is (%f, %f)\n", b1.position.x, b1.position.y);

        rb2d_object_gravity(&b1, &b2);     
        rb2d_update_position(&b1, UPDATE_TIME);

        printf("b1's final position is (%f, %f)\n\n", b1.position.x, b1.position.y);

        rb2d_update_position(&b1, UPDATE_TIME);

        if (b1.position.y <= 0) {

            break;
        }
    } while (true);
}
