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

#endif /* VECTOR3_H */
