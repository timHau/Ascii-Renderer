#ifndef SCENE_H
#define SCENE_H

#include "Vec3.h"

class Scene 
{
public:
    static float get_distance(const Vec3 &point)
    {
        float sphere_radius = 1.0f;
        Vec3 sphere(0.0f, 1.0f, 6.0f);
        float sphere_dist = (point - sphere).length() - sphere_radius;

        float plane = point.getY();

        float dist = std::min(sphere_dist, plane);
        return dist;
    }

};

#endif