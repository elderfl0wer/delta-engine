#include <stdbool.h>
#include <stdio.h>

#include "../include/delta/constants.h"
#include "../include/delta/math/vector2.h"
#include "../include/delta/physics/rigidbody2d.h"

#define DT 0.1
#define MAX_STEPS 10000

static void print_body(const char *name, const RigidBody2D *rb)
{
    printf(
        "%s\n"
        "  Position     : (%10.4f, %10.4f)\n"
        "  Velocity     : (%10.4f, %10.4f)\n"
        "  Force        : (%10.4f, %10.4f)\n"
        "\n",
        name,
        rb->position.x, rb->position.y,
        rb->velocity.x, rb->velocity.y,
        rb->force.x, rb->force.y
    );
}

int main(void)
{
    RigidBody2D b1 = {
        .mass = 1e12,
        .inv_mass = 1.0 / 1e12,
        .charge = FUNDAMENTAL_CHARGE,
        .position = {0, 0},
        .velocity = {0, 0},
        .acceleration = {0, 0},
        .force = {0, 0},
    };

    RigidBody2D b2 = {
        .mass = 1e12,
        .inv_mass = 1.0 / 1e12,
        .charge = -FUNDAMENTAL_CHARGE,
        .position = {5, 0},
        .velocity = {0, 0},
        .acceleration = {0, 0},
        .force = {0, 0},
    };

    puts("Starting simulation...\n");

    for (int step = 0; step < MAX_STEPS; ++step)
    {
        printf("========== Step %d ==========\n", step);

        /* Compute forces */
        rb2d_object_gravity(&b1, &b2);

        /* Integrate */
        rb2d_update_position(&b1, DT);
        rb2d_update_position(&b2, DT);

        /* Debug output */
        print_body("Body 1", &b1);
        print_body("Body 2", &b2);

        /* Collision */
        if (rb2d_check_collision(&b1, &b2))
        {
            puts("Bodies collided!");
            break;
        }
    }

    return 0;
}
