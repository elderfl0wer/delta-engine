#ifndef VECTOR2_H
#define VECTOR2_H

struct vec3_tag;
typedef struct vec3_tag vec3;

typedef struct vec2_tag {
    double x;
    double y;
} vec2;

vec2 vec2_add(vec2 *a, vec2 *b);
vec2 vec2_subtract(vec2 *a, vec2 *b);
double vec2_length(vec2 *a);
vec2 vec2_normalize(vec2 *a);
vec3 vec2_cross(vec2 *a, vec2 *b);
vec2 vec2_scale(vec2 *v, const double factor);
double vec2_dot(vec2 *a, vec2 *b);
double vec2_distance(vec2 *a, vec2 *b);
double vec2_horizontal_angle(vec2 *v);


#endif /* VECTOR2_H */
