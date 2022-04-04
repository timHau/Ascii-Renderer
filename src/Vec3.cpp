#include "Vec3.h"

Vec3::Vec3()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

Vec3::Vec3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vec3::~Vec3() {}

float Vec3::X() const
{
    return x;
}

float Vec3::Y() const
{
    return y;
}

float Vec3::Z() const
{
    return z;
}

void Vec3::setX(float x)
{
    this->x = x;
}

void Vec3::setY(float y)
{
    this->y = y;
}

void Vec3::setZ(float z)
{
    this->z = z;
}

Vec3 &Vec3::operator=(const Vec3 &other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

Vec3 Vec3::operator+(const Vec3 &other) const
{
    return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator-(const Vec3 &other) const
{
    return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3 Vec3::operator*(const Vec3 &other) const
{
    return Vec3(x * other.x, y * other.y, z * other.z);
}

Vec3 Vec3::operator/(const Vec3 &other) const
{
    return Vec3(x / other.x, y / other.y, z / other.z);
}

Vec3 Vec3::operator*(float scalar) const
{
    return Vec3(x * scalar, y * scalar, z * scalar);
}

Vec3 Vec3::operator/(float scalar) const
{
    return Vec3(x / scalar, y / scalar, z / scalar);
}

Vec3 Vec3::operator-(float scalar) const
{
    return Vec3(x - scalar, y - scalar, z - scalar);
}

Vec3 Vec3::operator-(void) const
{
    return Vec3(-x, -y, -z);
}

Vec3 &Vec3::operator+=(const Vec3 &other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vec3 &Vec3::operator-=(const Vec3 &other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vec3 &Vec3::operator*=(const Vec3 &other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

Vec3 &Vec3::operator/=(const Vec3 &other)
{
    x /= other.x;
    y /= other.y;
    z /= other.z;
    return *this;
}

Vec3 &Vec3::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

Vec3 &Vec3::operator/=(float scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

bool Vec3::operator==(const Vec3 &other) const
{
    return x == other.x && y == other.y && z == other.z;
}

bool Vec3::operator!=(const Vec3 &other) const
{
    return x != other.x || y != other.y || z != other.z;
}

float Vec3::length() const
{
    return sqrtf(x * x + y * y + z * z);
}

float Vec3::lengthSquared() const
{
    return x * x + y * y + z * z;
}

float Vec3::distance(const Vec3 &other) const
{
    return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2) + pow(other.z - z, 2));
}

float Vec3::distanceSquared(const Vec3 &other) const
{
    return pow(other.x - x, 2) + pow(other.y - y, 2) + pow(other.z - z, 2);
}

Vec3 &Vec3::normalize()
{
    float length = this->length();
    x /= length;
    y /= length;
    z /= length;
    return *this;
}

Vec3 Vec3::normalized() const
{
    float length = this->length();
    return Vec3(x / length, y / length, z / length);
}

Vec3 Vec3::cross(const Vec3 &other) const
{
    return Vec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

float Vec3::dot(const Vec3 &other) const
{
    return x * other.x + y * other.y + z * other.z;
}

float Vec3::angle(const Vec3 &other) const
{
    return acos(this->dot(other) / (this->length() * other.length()));
}

Vec3 Vec3::lerp(const Vec3 &other, float t) const
{
    return Vec3(x + (other.x - x) * t, y + (other.y - y) * t, z + (other.z - z) * t);
}

Vec3 Vec3::slerp(const Vec3 &other, float t) const
{
    float theta = angle(other);
    float sinTheta = sin(theta);
    float t1 = sin((1.0f - t) * theta) / sinTheta;
    float t2 = sin(t * theta) / sinTheta;
    return Vec3(x * t1 + other.x * t2, y * t1 + other.y * t2, z * t1 + other.z * t2);
}

Vec3 Vec3::reflect(const Vec3 &normal) const
{
    return *this - normal * 2.0f * this->dot(normal);
}

Vec3 Vec3::abs() const
{
    return Vec3(fabs(x), fabs(y), fabs(z));
}

Vec3 Vec3::max(float v) const
{
    return Vec3(fmax(x, v), fmax(y, v), fmax(z, v));
}

Vec3 Vec3::min(float v) const
{
    return Vec3(fmin(x, v), fmin(y, v), fmin(z, v));
}