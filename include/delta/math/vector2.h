#ifndef VECTOR2_H
#define VECTOR2_H
typedef struct {
    double x;
    double y;
} vec2;

vec2 vec2_add(vec2 *a, vec2 *b);
vec2 vec2_subtract(vec2 *a, vec2 *b);
double vec2_length(vec2 *a);
vec2 vec2_normalize(vec2 *a);


#endif /* VECTOR2_H */
