#include "Scene.h"

Vec3 Scene::rotate(const Vec3 &p, float angle)
{
    float theta = angle / 10.0;
    return Vec3(
        cos(theta) * p.X() + sin(theta) * p.Y(),
        cos(theta) * p.Y() - sin(theta) * p.X(),
        p.Z());
}

float Scene::sdf_sphere(const Vec3 &p, Vec3 &pos, float radius)
{
    return (p - pos).length() - radius;
}

float Scene::sdf_torus(Vec3 &p, Vec3 &r, float t)
{
    auto rot_1 = rotate(Vec3(p.Z(), p.Y(), p.Z()), t * -M_PI_2);
    p.setZ(rot_1.X());
    p.setY(rot_1.Y());

    auto rot_2 = rotate(p, t * -M_PI_2);
    p.setX(rot_2.X());
    p.setY(rot_2.Y());

    float x = Vec3(p.X(), 0.0, p.Z()).length() - r.X();
    return Vec3(x, p.Y(), 0.0).length() - r.Y();
}

float Scene::sdf_box(const Vec3 &p, const Vec3 &b)
{
    auto q = p.abs() - b;
    return q.max(0.0).length() + fmin(fmax(q.X(), fmax(q.Y(), q.Z())), 0.0);
}

float Scene::sdf_capsule(const Vec3 &p, const Vec3 &a, const Vec3 &b, float r)
{
    auto pa = p - a;
    auto ba = b - a;
    float h = std::clamp(pa.dot(ba) / ba.lengthSquared(), 0.0f, 1.0f);
    return (pa - ba * h).length() - r;
}

float Scene::op_round(float sdf_primitive, float r)
{
    return sdf_primitive - r;
}

float Scene::op_union(float sdf_primitive_1, float sdf_primitive_2)
{
    return std::min(sdf_primitive_1, sdf_primitive_2);
}

float Scene::op_smooth_union(float sdf_primitive_1, float sdf_primitive_2, float r)
{
    float h = std::clamp(0.5f + 0.5f * (sdf_primitive_1 - sdf_primitive_2) / r, 0.0f, 1.0f);
    return sdf_primitive_1 * (1.0f - h) + sdf_primitive_2 * h - r * h * (1.0f - h);
}

float Scene::op_intersection(float sdf_primitive_1, float sdf_primitive_2)
{
    return std::max(sdf_primitive_1, sdf_primitive_2);
}

float Scene::op_subtraction(float sdf_primitive_1, float sdf_primitive_2)
{
    return std::max(sdf_primitive_1, -sdf_primitive_2);
}

float Scene::op_smooth_subtraction(float sdf_primitive_1, float sdf_primitive_2, float r)
{
    float h = std::clamp(0.5f + 0.5f * (sdf_primitive_1 + sdf_primitive_2) / 0.1f, 0.0f, 1.0f);
    return -sdf_primitive_1 * (1.0f - h) + sdf_primitive_2 * h + r * h * (1.0f - h);
}

float Scene::op_displace(float sdf_primitive, const Vec3 &p, float freq)
{
    return sdf_primitive + sin(freq * p.X()) * sin(freq * p.Y()) * sin(freq * p.Z());
}

float Scene::get_distance(const Vec3 &point, float t)
{
    float plane_dist = point.Y() + 2.0f;

    auto sphere_pos = Vec3(0.0f, 1.0f, 6.0f);
    float sphere_dist = sdf_sphere(point, sphere_pos, 1.0f);

    auto shifted_pos = point - Vec3(0.0f, 0.2f, 6.0f);

    auto torus_radi = Vec3(1.5f, 0.6f, 0.0f);
    auto torus_pos = shifted_pos + Vec3(0.2f, 0.0f, 0.0f);
    float torus_dist = sdf_torus(torus_pos, torus_radi, t);

    float box_dist = sdf_box(shifted_pos, Vec3(0.9f, 0.9f, 1.0f));

    float capsule_dist = sdf_capsule(shifted_pos, Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 1.0f), 0.5f);

    float dist = std::min(torus_dist, plane_dist);

    // float dist = op_union(
    //     plane_dist,
    //     op_displace(
    //         op_smooth_union(
    //             op_round(box_dist, 0.2f),
    //             torus_dist,
    //             0.5f),
    //         point,
    //         2.0f));

    // float dist = op_union(
    //     op_smooth_union(torus_dist, box_dist, 0.5f),
    //     plane_dist
    // );

    // float dist = std::min(plane_dist, std::min(torus_dist, box_dist));
    // float dist = std::min(plane_dist, capsule_dist);

    return dist;
}