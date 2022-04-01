#ifndef VECTOR3_H
#define VECTOR3_H

#include <math.h>

class Vector3
{
private:
    float x;
    float y;
    float z;

public:
    Vector3();
    Vector3(float x, float y, float z);
    ~Vector3();

    float getX() const;
    float getY() const;
    float getZ() const;

    Vector3 &operator=(const Vector3 &other);
    Vector3 operator+(const Vector3 &other) const;
    Vector3 operator-(const Vector3 &other) const;
    Vector3 operator*(const Vector3 &other) const;
    Vector3 operator/(const Vector3 &other) const;
    Vector3 operator*(float scalar) const;
    Vector3 operator/(float scalar) const;
    Vector3 operator-() const;

    Vector3 &operator+=(const Vector3 &other);
    Vector3 &operator-=(const Vector3 &other);
    Vector3 &operator*=(const Vector3 &other);
    Vector3 &operator/=(const Vector3 &other);
    Vector3 &operator*=(float scalar);
    Vector3 &operator/=(float scalar);

    bool operator==(const Vector3 &other) const;
    bool operator!=(const Vector3 &other) const;

    float length() const;
    float lengthSquared() const;
    float distance(const Vector3 &other) const;
    float distanceSquared(const Vector3 &other) const;
    Vector3 &normalize();
    Vector3 normalized() const;
    Vector3 cross(const Vector3 &other) const;
    float dot(const Vector3 &other) const;
    float angle(const Vector3 &other) const;
    Vector3 lerp(const Vector3 &other, float t) const;
    Vector3 slerp(const Vector3 &other, float t) const;
    Vector3 reflect(const Vector3 &normal) const;
    // Vector3 refract(const Vector3& normal, float eta) const;
};

#endif