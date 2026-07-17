

#include "../../include/delta/math/vector3.h"
#include "../../include/delta/math/vector2.h"
#include <math.h>

vec3 vec3_from_vec2(vec2 *v)
{
    vec3 ans = {v->x, v->y, 0};
    return ans;
}

double vec3_length(vec3 *v)
{
    double ans = sqrt(v->x*v->x + v->y*v->y + v->z*v->z);
}
