#ifndef VECTOR3_H
#define VECTOR3_H

struct vec2_tag;
typedef struct vec2_tag vec2;

typedef struct vec3_tag {
    double x;
    double y;
    double z;
} vec3;

vec3 vec3_from_vec2(vec2 *v);
double vec3_length(vec3 *v);
vec3 vec3_add(vec3 *a, vec3 *b);
vec3 vec3_subtract(vec3 *a, vec3 *b);
vec3 vec3_normalize(vec3 *v);
vec3 vec3_scale(vec3 *v, const double factor);
double vec3_distance(vec3 *a, vec3 *b);
double vec3_dot(vec3 *a, vec3 *b);
vec3 vec3_cross(vec3 *a, vec3 *b);


#endif /* VECTOR3_H */
