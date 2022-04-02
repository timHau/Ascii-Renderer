#ifndef SCENE_H
#define SCENE_H

#include "Vec3.h"
#include <math.h>

Vec3 rotate_torus(const Vec3 &p, float angle)
{
    float theta = angle / 20.0;
    return Vec3(
        cos(theta) * p.X() + sin(theta) * p.Y(),
        cos(theta) * p.Y() - sin(theta) * p.X(),
        p.Z()
    );
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
        auto rot_1 = rotate_torus(Vec3(p.Z(), p.Y(), p.Z()), t * -M_PI_2);
        p.setZ(rot_1.X());
        p.setY(rot_1.Y());

        auto rot_2 = rotate_torus(p, t * -M_PI_2);
        p.setX(rot_2.X());
        p.setY(rot_2.Y());

        float x = Vec3(p.X(), 0.0, p.Z()).length() - r.X();
        return Vec3(x, p.Y(), 0.0).length() - r.Y();
    }

    static float get_distance(const Vec3 &point, float t)
    {
        float plane = point.Y() + 1.0f;

        auto sphere_pos = Vec3(0.0f, 1.0f, 6.0f);
        float sphere_dist = sdf_sphere(point, sphere_pos, 1.0f);

        auto torus_radi = Vec3(1.5f, 0.4f, 0.0f);
        auto shifted_torus_pos = point - Vec3(0.0f, 0.5f, 6.0f);
        float torus_dist = sdf_torus(shifted_torus_pos, torus_radi, t);

        float dist = std::min(torus_dist, plane);
        return dist;
    }

};

#endif