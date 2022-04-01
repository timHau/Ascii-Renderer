#include "Vector3.h"

Vector3::Vector3() {
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

Vector3::Vector3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3::~Vector3() {}

float Vector3::getX() const {
    return x;
}

float Vector3::getY() const {
    return y;
}

float Vector3::getZ() const {
    return z;
}

Vector3& Vector3::operator=(const Vector3& other) {
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(const Vector3& other) const {
    return Vector3(x * other.x, y * other.y, z * other.z);
}

Vector3 Vector3::operator/(const Vector3& other) const {
    return Vector3(x / other.x, y / other.y, z / other.z);
}

Vector3 Vector3::operator*(float scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 Vector3::operator/(float scalar) const {
    return Vector3(x / scalar, y / scalar, z / scalar);
}

Vector3 Vector3::operator-(void) const {
    return Vector3(-x, -y, -z);
}

Vector3& Vector3::operator+=(const Vector3& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vector3& Vector3::operator*=(const Vector3& other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

Vector3& Vector3::operator/=(const Vector3& other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    return *this;
}

Vector3& Vector3::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

Vector3& Vector3::operator/=(float scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

bool Vector3::operator==(const Vector3& other) const {
    return x == other.x && y == other.y && z == other.z;
}

bool Vector3::operator!=(const Vector3& other) const {
    return x != other.x || y != other.y || z != other.z;
}

float Vector3::length() const {
    return sqrtf(x * x + y * y + z * z);
}

float Vector3::lengthSquared() const {
    return x * x + y * y + z * z;
}

float Vector3::distance(const Vector3& other) const {
    return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2) + pow(other.z - z, 2));
}

float Vector3::distanceSquared(const Vector3& other) const {
    return pow(other.x - x, 2) + pow(other.y - y, 2) + pow(other.z - z, 2);
}

Vector3& Vector3::normalize() {
    float length = this->length();
    x /= length;
    y /= length;
    z /= length;
    return *this;
}

Vector3 Vector3::normalized() const {
    float length = this->length();
    return Vector3(x / length, y / length, z / length);
}

Vector3 Vector3::cross(const Vector3& other) const {
    return Vector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

float Vector3::dot(const Vector3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

float Vector3::angle(const Vector3& other) const {
    return acos(this->dot(other) / (this->length() * other.length()));
}

Vector3 Vector3::lerp(const Vector3& other, float t) const {
    return Vector3(x + (other.x - x) * t, y + (other.y - y) * t, z + (other.z - z) * t);
}

Vector3 Vector3::slerp(const Vector3& other, float t) const {
    float theta = angle(other);
    float sinTheta = sin(theta);
    float t1 = sin((1.0f - t) * theta) / sinTheta;
    float t2 = sin(t * theta) / sinTheta;
    return Vector3(x * t1 + other.x * t2, y * t1 + other.y * t2, z * t1 + other.z * t2);
}

Vector3 Vector3::reflect(const Vector3& normal) const {
    return *this - normal * 2.0f * this->dot(normal);
}