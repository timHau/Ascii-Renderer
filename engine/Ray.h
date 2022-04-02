#ifndef RAY_H
#define RAY_H

#define RAY_MARCH_MAX_STEPS 100
#define RAY_MARCH_MAX_DISTANCE 100.0f
#define SURFACE_DIST 0.01f

#include <termox/termox.hpp>
#include <string>
#include <iostream>
#include "Vec3.h"
#include "Scene.h"


class Ray
{
public:
    Ray(const Vec3 &o, const Vec3 &d)
        : origin(o), direction(d){};

    auto at(float t) const -> Vec3
    {
        return origin + direction * t;
    }

    auto march() const -> float {
        float dist = 0.0f;

        for (int i = 0; i < RAY_MARCH_MAX_STEPS; ++i)
        {
            Vec3 p = at(dist);
            float dist_scene = Scene::get_distance(p);
            dist += dist_scene;
            if (dist > RAY_MARCH_MAX_DISTANCE || dist_scene < SURFACE_DIST)
                break;
        }

        return dist;
    }

    ox::Glyph color() const
    {
        float dist = march() / 250.0f;
        std::cout << dist << std::endl;
        return alphabet.at((1.0 - dist) * (alphabet.size() - 1));
    }

private:
    Vec3 origin;
    Vec3 direction;
    std::string alphabet = " .\'`^,:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao#MW&8%B@$";
};

#endif