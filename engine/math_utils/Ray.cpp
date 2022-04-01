#include "Ray.h"

Ray::Ray(const Vector3 &o, const Vector3 &d)
    : origin(o), direction(d)
{
}

Vector3 Ray::at(float t) const
{
    return origin + direction * t;
}

double hit_sphere(const Vector3 &center, double radius, const Ray &r)
{
    Vector3 oc = r.origin - center;
    auto a = r.direction.lengthSquared();
    auto half_b = oc.dot(r.direction);
    auto c = oc.lengthSquared() - radius*radius;
    auto discriminant = half_b*half_b - a*c;

    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-half_b - sqrt(discriminant) ) / a;
    }
}

ox::Glyph Ray::color() const
{
    auto t = hit_sphere(Vector3(0, 0, -1), 0.5, *this);
    if (t > 0.0) {
        Vector3 N = (at(t) - Vector3(0, 0, -1)).normalize();
        auto c = (N.getX() + 1.0) * 0.5; // in [0,1]
        auto s = alphabet.at(static_cast<int>(c * (alphabet.size() - 1)));
        // return s | ox::fg(ox::Color::Red);
        return s;
    }

    auto unit_dir = direction.normalized();
    t = 0.5 * (unit_dir.getY() + 1.0);

    auto c = 0.0;
    // auto c = 1.0 * (1.0 - t) + 0.5 * t;
    // auto r = static_cast<int>(255.0 * c);
    // ox::Color::Value_t color_val = static_cast<ox::Color::Value_t>(0);
    // if (64 <= r && r < 128)
    // {
    //     color_val = static_cast<ox::Color::Value_t>(8);
    // }
    // else if (128 <= r && r < 192)
    // {
    //     color_val = static_cast<ox::Color::Value_t>(7);
    // }
    // else if (192 <= r && r < 256)
    // {
    //     color_val = static_cast<ox::Color::Value_t>(14);
    // }

    auto s = alphabet.at(static_cast<int>(c * (alphabet.size() - 1)));
    // return s | ox::fg(ox::Color{color_val});
    return s;
}