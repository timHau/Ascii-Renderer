#include <gtest/gtest.h>
#include "../engine/math/Vector3.h"

TEST(Vector3, Initialization) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    EXPECT_EQ(1.0, v1.getX());
    EXPECT_EQ(2.0f, v1.getY());
    EXPECT_EQ(3.0f, v1.getZ());
}

TEST(Vector3, Addition) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2(4.0f, 5.0f, 6.0f);
    Vector3 v3 = v1 + v2;
    EXPECT_EQ(5.0f, v3.getX());
    EXPECT_EQ(7.0f, v3.getY());
    EXPECT_EQ(9.0f, v3.getZ());
}

TEST(Vector3, Subtraction) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2(4.0f, 5.0f, 6.0f);
    Vector3 v3 = v1 - v2;
    EXPECT_EQ(-3.0f, v3.getX());
    EXPECT_EQ(-3.0f, v3.getY());
    EXPECT_EQ(-3.0f, v3.getZ());
}

TEST(Vector3, Multiplication) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2(4.0f, 5.0f, 6.0f);
    Vector3 v3 = v1 * v2;
    EXPECT_EQ(4.0f, v3.getX());
    EXPECT_EQ(10.0f, v3.getY());
    EXPECT_EQ(18.0f, v3.getZ());
}

TEST(Vector3, Division) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2(4.0f, 5.0f, 6.0f);
    Vector3 v3 = v1 / v2;
    EXPECT_EQ(0.25f, v3.getX());
    EXPECT_EQ(0.4f, v3.getY());
    EXPECT_EQ(0.5f, v3.getZ());
}

TEST(Vector3, ScalarMultiplication) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2 = v1 * 2.0f;
    EXPECT_EQ(2.0f, v2.getX());
    EXPECT_EQ(4.0f, v2.getY());
    EXPECT_EQ(6.0f, v2.getZ());
}

TEST(Vector3, ScalarDivision) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2 = v1 / 2.0f;
    EXPECT_EQ(0.5f, v2.getX());
    EXPECT_EQ(1.0f, v2.getY());
    EXPECT_EQ(1.5f, v2.getZ());
}

TEST(Vector3, Inverse) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2 = -v1;
    EXPECT_EQ(-1.0f, v2.getX());
    EXPECT_EQ(-2.0f, v2.getY());
    EXPECT_EQ(-3.0f, v2.getZ());
}

TEST(Vector3, AddAssign) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2(4.0f, 5.0f, 6.0f);
    v1 += v2;
    EXPECT_EQ(5.0f, v1.getX());
    EXPECT_EQ(7.0f, v1.getY());
    EXPECT_EQ(9.0f, v1.getZ());
}

TEST(Vector3, SubAssign) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2(4.0f, 5.0f, 6.0f);
    v1 -= v2;
    EXPECT_EQ(-3.0f, v1.getX());
    EXPECT_EQ(-3.0f, v1.getY());
    EXPECT_EQ(-3.0f, v1.getZ());
}

TEST(Vector3, MulAssign) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2(4.0f, 5.0f, 6.0f);
    v1 *= v2;
    EXPECT_EQ(4.0f, v1.getX());
    EXPECT_EQ(10.0f, v1.getY());
    EXPECT_EQ(18.0f, v1.getZ());
}

TEST(Vector3, DivAssign) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2(4.0f, 5.0f, 6.0f);
    v1 /= v2;
    EXPECT_EQ(0.25f, v1.getX());
    EXPECT_EQ(0.4f, v1.getY());
    EXPECT_EQ(0.5f, v1.getZ());
}

TEST(Vector3, ScalarMulAssign) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    v1 *= 2.0f;
    EXPECT_EQ(2.0f, v1.getX());
    EXPECT_EQ(4.0f, v1.getY());
    EXPECT_EQ(6.0f, v1.getZ());
}

TEST(Vector3, ScalarDivAssign) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    v1 /= 2.0f;
    EXPECT_EQ(0.5f, v1.getX());
    EXPECT_EQ(1.0f, v1.getY());
    EXPECT_EQ(1.5f, v1.getZ());
}

TEST(Vector3, Equal) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2(1.0f, 2.0f, 3.0f);
    EXPECT_TRUE(v1 == v2);
}

TEST(Vector3, NotEqual) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2(2.0f, 2.0f, 3.0f);
    EXPECT_TRUE(v1 != v2);
}

TEST(Vector3, Length) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    EXPECT_EQ(3.7416573867739413f, v1.length());
}

TEST(Vector3, LengthSquared) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    EXPECT_EQ(14.0f, v1.lengthSquared());
}

TEST(Vector3, Distance) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2(4.0f, 5.0f, 6.0f);
    EXPECT_EQ(5.196152422706632f, v1.distance(v2));
}

TEST(Vector3, DistanceSquared) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2(4.0f, 5.0f, 6.0f);
    EXPECT_EQ(27.0f, v1.distanceSquared(v2));
}

TEST(Vector3, Cross) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2(4.0f, 5.0f, 6.0f);
    Vector3 v3 = v1.cross(v2);
    EXPECT_EQ(-3.0f, v3.getX());
    EXPECT_EQ(6.0f, v3.getY());
    EXPECT_EQ(-3.0f, v3.getZ());
}

TEST(Vector3, Dot) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2(4.0f, 5.0f, 6.0f);
    EXPECT_EQ(32.0f, v1.dot(v2));
}

TEST(Vector3, Noramize) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    v1.normalize();
    EXPECT_FLOAT_EQ(0.2672612419124244f, v1.getX());
    EXPECT_FLOAT_EQ(0.5345224838248488f, v1.getY());
    EXPECT_FLOAT_EQ(0.8017837257372732f, v1.getZ());
}

TEST(Vector3, Angle) {
    Vector3 v1(1.0f, 0.0f, 0.0f);
    Vector3 v2(0.0f, 1.0f, 0.0f);
    EXPECT_FLOAT_EQ(M_PI_2, v1.angle(v2));
}

TEST(Vector3, Lerp) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2(4.0f, 5.0f, 6.0f);
    Vector3 v3 = v1.lerp(v2, 0.5f);
    EXPECT_FLOAT_EQ(2.5f, v3.getX());
    EXPECT_FLOAT_EQ(3.5f, v3.getY());
    EXPECT_FLOAT_EQ(4.5f, v3.getZ());
}

TEST(Vector3, Slerp) {
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2(4.0f, 5.0f, 6.0f);
    Vector3 v3 = v1.slerp(v2, 0.5f);
    EXPECT_FLOAT_EQ(2.5160077f, v3.getX());
    EXPECT_FLOAT_EQ(3.5224109f, v3.getY());
    EXPECT_FLOAT_EQ(4.5288143f, v3.getZ());
}

TEST(Vector3, Reflect) {
    Vector3 v1(1.0f, 1.0f, 0.0f);
    Vector3 v2(2.0f, 1.0f, 0.0f);
    Vector3 v3 = v1.reflect(v2);
    EXPECT_FLOAT_EQ(-11.0f, v3.getX());
    EXPECT_FLOAT_EQ(-5.0f, v3.getY());
    EXPECT_FLOAT_EQ(0.0f, v3.getZ());
}