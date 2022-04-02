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

    auto march() const -> float
    {
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

    auto get_normal(const Vec3 &p) const -> Vec3
    {
        float dist = Scene::get_distance(p);
        Vec3 n = Vec3(
            dist - Scene::get_distance(p - Vec3(0.01f, 0.0f, 0.0f)),
            dist - Scene::get_distance(p - Vec3(0.0f, 0.01f, 0.0f)),
            dist - Scene::get_distance(p - Vec3(0.0f, 0.0f, 0.01f)));
        return n.normalize();
    }

    auto get_light(float dist) const -> float
    {
        Vec3 p = at(dist);
        Vec3 light_pos = Vec3(0.0f, 5.0f, 6.0f);
        Vec3 l = (light_pos - p).normalize();
        Vec3 normal = get_normal(p);

        float diffuse = std::clamp(l.dot(normal), 0.0f, 1.0f);
        float shadow_ray = Ray(p + normal * SURFACE_DIST * 2.0, l).march();
        if (shadow_ray < (light_pos - p).length())
            diffuse *= 0.1f;
        return diffuse;
    }

    ox::Glyph color() const
    {
        float dist = march();
        auto diffuse = get_light(dist);
        auto s = alphabet.at(diffuse * (alphabet.size() - 1));

        if (diffuse <= 0.3)
        {
            auto fg = s | ox::fg(ox::Color::Dark_gray);
            return with_bg ? (fg | ox::bg(ox::Color::Black)) : fg;
        }
        else if (diffuse <= 0.75)
        {
            auto fg = s | ox::fg(ox::Color::Light_gray);
            return with_bg ? (fg | ox::bg(ox::Color::Dark_gray)) : fg;
        }
        else
        {
            auto fg = s | ox::fg(ox::Color::White);
            return with_bg ? (fg | ox::bg(ox::Color::Light_gray)) : fg;
        }
    }

private:
    bool with_bg = false;
    Vec3 origin;
    Vec3 direction;
    std::string alphabet = ".\'`^,:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao#MW&8%B@$";
};

#endif