#ifndef SCENE_H
#define SCENE_H

#include "Vec3.h"
#include <math.h>

void rotate_torus(Vec3 &p, float angle)
{
    p =  p * cos(angle / 50.0) + Vec3(p.Y(), -p.X(), p.Z()) * sin(angle / 50.0);
}

class Scene 
{
public:

    static float sdf_sphere(const Vec3 &p, Vec3 &pos, float radius)
    {
        return (p - pos).length() - radius;
    }

    static float sdf_torus(Vec3 &p, Vec3 &r, float t)
    {
        rotate_torus(p, t * -M_PI_2);
        float x = Vec3(p.X(), 0.0, p.Z()).length() - r.X();
        return Vec3(x, p.Y(), 0.0).length() - r.Y();
    }

    static float get_distance(const Vec3 &point, float t)
    {
        float plane = point.Y();

        auto sphere_pos = Vec3(0.0f, 1.0f, 6.0f);
        float sphere_dist = sdf_sphere(point, sphere_pos, 1.0f);

        auto torus_radi = Vec3(1.5f, 0.4f, 0.0f);
        auto shifted_torus_pos = point - Vec3(0.0f, 0.5f, 6.0f);
        float torus_dist = sdf_torus(shifted_torus_pos, torus_radi, t);

        // float dist = std::min(torus_dist, plane);
        float dist = torus_dist;
        return dist;
    }

};

#endif