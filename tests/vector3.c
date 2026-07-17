#include <stdio.h>

#include "../include/delta/math/vector3.h"
#include "../include/delta/math/vector2.h"

int main(void)
{
    vec2 v1 = {30, 5};
    vec3 v2 = vec3_from_vec2(&v1);

    printf("3-D version of v1 vector is (%f, %f, %f)", v2.x, v2.y, v2.z);
}
