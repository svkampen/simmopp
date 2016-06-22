#include <gtest/gtest.h>

#include <simmo/angle.hpp>

using namespace simmo;

TEST(angle_test, constructor)
{
    angle a = angle::rad(12.5);
    EXPECT_FLOAT_EQ(a.rad(), 12.5);

    angle b = angle::deg(12.5);
    EXPECT_FLOAT_EQ(b.deg(), 12.5);
}

TEST(angle_test, conversion)
{
    angle a = angle::deg(45);
    EXPECT_FLOAT_EQ(a.rad(), M_PI / 4);

    angle b = angle::rad(1);
    EXPECT_FLOAT_EQ(b.deg(), 57.29578);
}

TEST(angle_test, plus_minus)
{
    angle a = angle::deg(90);
    angle b = angle::deg(30);

    EXPECT_FLOAT_EQ((a + b).deg(), 120);
    EXPECT_FLOAT_EQ((b + a).deg(), 120);

    EXPECT_FLOAT_EQ((a - b).deg(), 60);
    EXPECT_FLOAT_EQ((b - a).deg(), -60);
}

TEST(angle_test, assign_plus_minus)
{
    angle a = angle::deg(90);
    EXPECT_FLOAT_EQ(a.deg(), 90);

    a += angle::deg(10);
    EXPECT_FLOAT_EQ(a.deg(), 100);

    a -= angle::deg(55);
    EXPECT_FLOAT_EQ(a.deg(), 45);
}

TEST(angle_test, multiply_divide)
{
    angle a = angle::deg(90);

    EXPECT_FLOAT_EQ((2 * a).deg(), 180);
    EXPECT_FLOAT_EQ((a * 2).deg(), 180);
    EXPECT_FLOAT_EQ((a / 0.5).deg(), 180);

    EXPECT_FLOAT_EQ((0.5 * a).deg(), 45);
    EXPECT_FLOAT_EQ((a * 0.5).deg(), 45);
    EXPECT_FLOAT_EQ((a / 2).deg(), 45);
}

TEST(angle_test, assign_multiply_divide)
{
    angle a = angle::deg(90);
    EXPECT_FLOAT_EQ(a.deg(), 90);

    a *= 2;
    EXPECT_FLOAT_EQ(a.deg(), 180);

    a /= 4;
    EXPECT_FLOAT_EQ(a.deg(), 45);
}
