#include <math.h>
#include <stdio.h>

#include "../include/delta/math/vector2.h"
#include "../include/delta/math/vector3.h"

int main(void)
{
    vec2 firstVector = {2, 30};
    vec2 secondVector = {-10, 4};

    vec2 sum = vec2_add(&firstVector, &secondVector);
    printf("Sum of vectors (%f, %f)\n", sum.x, sum.y);

    double length = vec2_length(&firstVector);
    printf("Length of first vector %f\n", length);

    vec2 normalizedFirst = vec2_normalize(&firstVector);
    printf("Normalized first vector (%f, %f)\n", normalizedFirst.x, normalizedFirst.y);

    vec3 crossv = vec2_cross(&firstVector, &secondVector);
    printf("inf check of cross Z %d\n", isinf(crossv.z));
    printf("Cross of the first & second vectors is (%f, %f, %f)", crossv.x, crossv.y, crossv.z);
}
