#ifndef Ray_h
#define Ray_h

#include "Vector3.h"
#include <termox/termox.hpp>
#include <string>

class Ray 
{
public:
    Ray(const Vector3 &origin, const Vector3 &direction);
    Vector3 at(float t) const;
    ox::Glyph color() const;

public:
    Vector3 origin;
    Vector3 direction;
    std::string alphabet = " .\'`^,:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao#MW&8%B@$"; 
};

#endif