#ifndef SCENE_H
#define SCENE_H

#include "Vec3.h"
#include "algorithm"
#include <math.h>

class Scene
{
public:
    static float sdf_sphere(const Vec3 &p, Vec3 &pos, float radius);
    static float sdf_torus(Vec3 &p, Vec3 &r, float t);
    static float sdf_box(const Vec3 &p, const Vec3 &b);
    static float sdf_capsule(const Vec3 &p, const Vec3 &a, const Vec3 &b, float r);
    static float op_round(float sdf_primitive, float r);
    static float op_union(float sdf_primitive_1, float sdf_primitive_2);
    static float op_smooth_union(float sdf_primitive_1, float sdf_primitive_2, float r);
    static float op_intersection(float sdf_primitive_1, float sdf_primitive_2);
    static float op_subtraction(float sdf_primitive_1, float sdf_primitive_2);
    static float op_smooth_subtraction(float sdf_primitive_1, float sdf_primitive_2, float r);
    static float op_displace(float sdf_primitive, const Vec3 &p, float freq);
    static float get_distance(const Vec3 &point, float t);
    static Vec3 rotate(const Vec3 &p, float angle);
};

#endif