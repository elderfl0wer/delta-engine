

#include "../../include/delta/math/vector3.h"
#include "../../include/delta/math/vector2.h"

vec3 vec3_from_vec2(vec2 *v)
{
    vec3 ans = {v->x, v->y, 0};
    return ans;
}
