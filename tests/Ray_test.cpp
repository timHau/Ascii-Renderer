#include <gtest/gtest.h>
#include "../engine/math_utils/Ray.h" 

TEST(Ray, Initialization) {
    Ray r1(Vector3(1.0f, 2.0f, 3.0f), Vector3(4.0f, 5.0f, 6.0f));
    EXPECT_FLOAT_EQ(1.0f, r1.origin.getX());
    EXPECT_FLOAT_EQ(2.0f, r1.origin.getY());
    EXPECT_FLOAT_EQ(3.0f, r1.origin.getZ());
    EXPECT_FLOAT_EQ(4.0f, r1.direction.getX());
    EXPECT_FLOAT_EQ(5.0f, r1.direction.getY());
    EXPECT_FLOAT_EQ(6.0f, r1.direction.getZ());
}

TEST(Ray, At) {
    Ray r1(Vector3(1.0f, 2.0f, 3.0f), Vector3(4.0f, 5.0f, 6.0f));
    EXPECT_FLOAT_EQ(3.0f, r1.at(0.5f).getX());
    EXPECT_FLOAT_EQ(4.5f, r1.at(0.5f).getY());
    EXPECT_FLOAT_EQ(6.0f, r1.at(0.5f).getZ());
}