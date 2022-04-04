#ifndef SCENE_H
#define SCENE_H

#include "Vec3.h"
#include <math.h>

Vec3 rotate_torus(const Vec3 &p, float angle)
{
    float theta = angle / 10.0;
    return Vec3(
        cos(theta) * p.X() + sin(theta) * p.Y(),
        cos(theta) * p.Y() - sin(theta) * p.X(),
        p.Z());
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

    static float sdf_box(const Vec3 &p, const Vec3 &b)
    {
        auto q = p.abs() - b;
        return q.max(0.0).length() + fmin(fmax(q.X(), fmax(q.Y(), q.Z())), 0.0);
    }

    static float sdf_capsule(const Vec3 &p, const Vec3 &a, const Vec3 &b, float r)
    {
        auto pa = p - a;
        auto ba = b - a;
        float h = std::clamp(pa.dot(ba) / ba.lengthSquared(), 0.0f, 1.0f);
        return (pa - ba * h).length() - r; 
    }

    static float op_round(float sdf_primitive, float r)
    {
        return sdf_primitive - r;
    }

    static float get_distance(const Vec3 &point, float t)
    {
        float plane_dist = point.Y() + 2.0f;

        auto sphere_pos = Vec3(0.0f, 1.0f, 6.0f);
        float sphere_dist = sdf_sphere(point, sphere_pos, 1.0f);

        auto torus_radi = Vec3(1.5f, 0.6f, 0.0f);
        auto shifted_pos = point - Vec3(0.0f, 0.2f, 6.0f);
        float torus_dist = sdf_torus(shifted_pos, torus_radi, t);

        float box_dist = sdf_box(shifted_pos, Vec3(0.9f, 0.9f, 1.0f));

        float capsule_dist = sdf_capsule(shifted_pos, Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 1.0f), 0.5f);

        // float dist = std::min(torus_dist, plane_dist);
        float dist = std::min(op_round(box_dist, 0.5f), plane_dist);
        // float dist = std::min(plane_dist, std::min(torus_dist, box_dist));
        // float dist = std::min(plane_dist, capsule_dist);

        return dist;
    }
};

#endif