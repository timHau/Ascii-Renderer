#include <gtest/gtest.h>
#include "../engine/Vec3.h"

TEST(Vec3, Initialization) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    EXPECT_EQ(1.0, v1.X());
    EXPECT_EQ(2.0f, v1.Y());
    EXPECT_EQ(3.0f, v1.Z());
}

TEST(Vec3, Addition) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(4.0f, 5.0f, 6.0f);
    Vec3 v3 = v1 + v2;
    EXPECT_EQ(5.0f, v3.X());
    EXPECT_EQ(7.0f, v3.Y());
    EXPECT_EQ(9.0f, v3.Z());
}

TEST(Vec3, Subtraction) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(4.0f, 5.0f, 6.0f);
    Vec3 v3 = v1 - v2;
    EXPECT_EQ(-3.0f, v3.X());
    EXPECT_EQ(-3.0f, v3.Y());
    EXPECT_EQ(-3.0f, v3.Z());
}

TEST(Vec3, Multiplication) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(4.0f, 5.0f, 6.0f);
    Vec3 v3 = v1 * v2;
    EXPECT_EQ(4.0f, v3.X());
    EXPECT_EQ(10.0f, v3.Y());
    EXPECT_EQ(18.0f, v3.Z());
}

TEST(Vec3, Division) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(4.0f, 5.0f, 6.0f);
    Vec3 v3 = v1 / v2;
    EXPECT_EQ(0.25f, v3.X());
    EXPECT_EQ(0.4f, v3.Y());
    EXPECT_EQ(0.5f, v3.Z());
}

TEST(Vec3, ScalarMultiplication) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2 = v1 * 2.0f;
    EXPECT_EQ(2.0f, v2.X());
    EXPECT_EQ(4.0f, v2.Y());
    EXPECT_EQ(6.0f, v2.Z());
}

TEST(Vec3, ScalarDivision) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2 = v1 / 2.0f;
    EXPECT_EQ(0.5f, v2.X());
    EXPECT_EQ(1.0f, v2.Y());
    EXPECT_EQ(1.5f, v2.Z());
}

TEST(Vec3, ScalarSubtraction) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2 = v1 - 1.0f;
    EXPECT_EQ(0.0f, v2.X());
    EXPECT_EQ(1.0f, v2.Y());
    EXPECT_EQ(2.0f, v2.Z());
}

TEST(Vec3, Inverse) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2 = -v1;
    EXPECT_EQ(-1.0f, v2.X());
    EXPECT_EQ(-2.0f, v2.Y());
    EXPECT_EQ(-3.0f, v2.Z());
}

TEST(Vec3, AddAssign) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(4.0f, 5.0f, 6.0f);
    v1 += v2;
    EXPECT_EQ(5.0f, v1.X());
    EXPECT_EQ(7.0f, v1.Y());
    EXPECT_EQ(9.0f, v1.Z());
}

TEST(Vec3, SubAssign) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(4.0f, 5.0f, 6.0f);
    v1 -= v2;
    EXPECT_EQ(-3.0f, v1.X());
    EXPECT_EQ(-3.0f, v1.Y());
    EXPECT_EQ(-3.0f, v1.Z());
}

TEST(Vec3, MulAssign) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(4.0f, 5.0f, 6.0f);
    v1 *= v2;
    EXPECT_EQ(4.0f, v1.X());
    EXPECT_EQ(10.0f, v1.Y());
    EXPECT_EQ(18.0f, v1.Z());
}

TEST(Vec3, DivAssign) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(4.0f, 5.0f, 6.0f);
    v1 /= v2;
    EXPECT_EQ(0.25f, v1.X());
    EXPECT_EQ(0.4f, v1.Y());
    EXPECT_EQ(0.5f, v1.Z());
}

TEST(Vec3, ScalarMulAssign) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    v1 *= 2.0f;
    EXPECT_EQ(2.0f, v1.X());
    EXPECT_EQ(4.0f, v1.Y());
    EXPECT_EQ(6.0f, v1.Z());
}

TEST(Vec3, ScalarDivAssign) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    v1 /= 2.0f;
    EXPECT_EQ(0.5f, v1.X());
    EXPECT_EQ(1.0f, v1.Y());
    EXPECT_EQ(1.5f, v1.Z());
}

TEST(Vec3, Equal) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(1.0f, 2.0f, 3.0f);
    EXPECT_TRUE(v1 == v2);
}

TEST(Vec3, NotEqual) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(2.0f, 2.0f, 3.0f);
    EXPECT_TRUE(v1 != v2);
}

TEST(Vec3, Length) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    EXPECT_EQ(3.7416573867739413f, v1.length());
}

TEST(Vec3, LengthSquared) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    EXPECT_EQ(14.0f, v1.lengthSquared());
}

TEST(Vec3, Distance) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(4.0f, 5.0f, 6.0f);
    EXPECT_EQ(5.196152422706632f, v1.distance(v2));
}

TEST(Vec3, DistanceSquared) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(4.0f, 5.0f, 6.0f);
    EXPECT_EQ(27.0f, v1.distanceSquared(v2));
}

TEST(Vec3, Cross) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(4.0f, 5.0f, 6.0f);
    Vec3 v3 = v1.cross(v2);
    EXPECT_EQ(-3.0f, v3.X());
    EXPECT_EQ(6.0f, v3.Y());
    EXPECT_EQ(-3.0f, v3.Z());
}

TEST(Vec3, Dot) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(4.0f, 5.0f, 6.0f);
    EXPECT_EQ(32.0f, v1.dot(v2));
}

TEST(Vec3, Noramize) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    v1.normalize();
    EXPECT_FLOAT_EQ(0.2672612419124244f, v1.X());
    EXPECT_FLOAT_EQ(0.5345224838248488f, v1.Y());
    EXPECT_FLOAT_EQ(0.8017837257372732f, v1.Z());
}

TEST(Vec3, Angle) {
    Vec3 v1(1.0f, 0.0f, 0.0f);
    Vec3 v2(0.0f, 1.0f, 0.0f);
    EXPECT_FLOAT_EQ(M_PI_2, v1.angle(v2));
}

TEST(Vec3, Lerp) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(4.0f, 5.0f, 6.0f);
    Vec3 v3 = v1.lerp(v2, 0.5f);
    EXPECT_FLOAT_EQ(2.5f, v3.X());
    EXPECT_FLOAT_EQ(3.5f, v3.Y());
    EXPECT_FLOAT_EQ(4.5f, v3.Z());
}

TEST(Vec3, Slerp) {
    Vec3 v1(1.0f, 2.0f, 3.0f);
    Vec3 v2(4.0f, 5.0f, 6.0f);
    Vec3 v3 = v1.slerp(v2, 0.5f);
    EXPECT_FLOAT_EQ(2.5160077f, v3.X());
    EXPECT_FLOAT_EQ(3.5224109f, v3.Y());
    EXPECT_FLOAT_EQ(4.5288143f, v3.Z());
}

TEST(Vec3, Reflect) {
    Vec3 v1(1.0f, 1.0f, 0.0f);
    Vec3 v2(2.0f, 1.0f, 0.0f);
    Vec3 v3 = v1.reflect(v2);
    EXPECT_FLOAT_EQ(-11.0f, v3.X());
    EXPECT_FLOAT_EQ(-5.0f, v3.Y());
    EXPECT_FLOAT_EQ(0.0f, v3.Z());
}