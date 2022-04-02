#ifndef Vec3_H
#define Vec3_H

#include <math.h>

class Vec3
{
private:
    float x;
    float y;
    float z;

public:
    Vec3();
    Vec3(float x, float y, float z);
    ~Vec3();

    float X() const;
    float Y() const;
    float Z() const;

    Vec3 &operator=(const Vec3 &other);
    Vec3 operator+(const Vec3 &other) const;
    Vec3 operator-(const Vec3 &other) const;
    Vec3 operator*(const Vec3 &other) const;
    Vec3 operator/(const Vec3 &other) const;
    Vec3 operator*(float scalar) const;
    Vec3 operator/(float scalar) const;
    Vec3 operator-(float scalar) const;
    Vec3 operator-() const;

    Vec3 &operator+=(const Vec3 &other);
    Vec3 &operator-=(const Vec3 &other);
    Vec3 &operator*=(const Vec3 &other);
    Vec3 &operator/=(const Vec3 &other);
    Vec3 &operator*=(float scalar);
    Vec3 &operator/=(float scalar);

    bool operator==(const Vec3 &other) const;
    bool operator!=(const Vec3 &other) const;

    float length() const;
    float lengthSquared() const;
    float distance(const Vec3 &other) const;
    float distanceSquared(const Vec3 &other) const;
    Vec3 &normalize();
    Vec3 normalized() const;
    Vec3 cross(const Vec3 &other) const;
    float dot(const Vec3 &other) const;
    float angle(const Vec3 &other) const;
    Vec3 lerp(const Vec3 &other, float t) const;
    Vec3 slerp(const Vec3 &other, float t) const;
    Vec3 reflect(const Vec3 &normal) const;
};

#endif