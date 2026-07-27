#include <stdbool.h>
#include <stdio.h>

#include "../include/delta/constants.h"
#include "../include/delta/math/vector2.h"
#include "../include/delta/physics/rigidbody2d.h"

#define DT 4e-6
#define MAX_STEPS 3000000
#define PRINT_EVERY 100

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
        .mass = 2.0,
        .inv_mass = 1.0 / 2.0,
        .charge = 9e-4,
        .position = {-0.27, 0.11},
        .velocity = {0, 0},
        .acceleration = {0, 0},
        .force = {0, 0},
    };

    RigidBody2D b2 = {
        .mass = 9.0,
        .inv_mass = 1.0 / 9.0,
        .charge = -9e-4,
        .position = {0.44, 0.33},
        .velocity = {0, 0},
        .acceleration = {0, 0},
        .force = {0, 0},
    };

    puts("Starting simulation...\n");

    for (int step = 0; step < MAX_STEPS; ++step)
    {
        /* Compute forces */
        // rb2d_object_gravity(&b1, &b2);
        rb2d_coloumb_force(&b1, &b2);

        /* Integrate */
        rb2d_update_position(&b1, DT);
        rb2d_update_position(&b2, DT);

        /* Debug output */
        if (step % PRINT_EVERY == 0)
        {
            printf("========== Step %d ==========\n", step);
            print_body("Body 1", &b1);
            print_body("Body 2", &b2);
        }

        /* Collision */
        if (rb2d_check_collision(&b1, &b2))
        {
            printf("Bodies collided! (step %d)\n", step);
            print_body("Body 1", &b1);
            print_body("Body 2", &b2);
            break;
        }
    }

    return 0;
}
