#include <gtest/gtest.h>
#include "../isColliding.h"


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST (COLLISION_TEST, checkingIfCollisionOfTriangles)
{
    //GIVEN
    triangle triangle1{vec2{150.f, 150.f}, vec2{250.f, 300.f}, vec2{500.f, 250.f}};
    triangle triangle2{vec2{190.f, 180.f}, vec2{25.f, 300.f}, vec2{50.f, 25.f}};

    //WHEN,THEN
    EXPECT_EQ(isColliding(triangle1, triangle2), true);
}

TEST (COLLISION_TEST, checkingIfNotCollisionOfTriangles)
{
    //GIVEN
    triangle triangle1{vec2{150.f, 150.f}, vec2{250.f, 300.f}, vec2{50.f, 250.f}};
    triangle triangle2{vec2{600.f, 220.f}, vec2{450.f, 500.f}, vec2{520.f, 700.f}};

    //WHEN,THEN
    EXPECT_EQ(isColliding(triangle1, triangle2), false);
}

TEST (COLLISION_TEST, checkingIfCollisionOfTrianglesWhenVertexOfFirstCrossedSideOfSecondTriangle)
{
    //GIVEN
    triangle triangle1{vec2{150.f, 150.f}, vec2{250.f, 300.f}, vec2{50.f, 250.f}};
    triangle triangle2{vec2{100.f, 100.f}, vec2{270.f, 535.f}, vec2{295.f, 260.f}};

    //WHEN,THEN
    EXPECT_EQ(isColliding(triangle1, triangle2), true);

}

TEST (COLLISION_TEST, checkingIfCollisionOfTrianglesWhenCommonVertexOfBothTriangles)
{
    //GIVEN
    triangle triangle1{vec2{150.f, 150.f}, vec2{250.f, 300.f}, vec2{50.f, 250.f}};
    triangle triangle2{vec2{150.f, 150.f}, vec2{410.f, 535.f}, vec2{435.f, 260.f}};

    //WHEN,THEN
    EXPECT_EQ(isColliding(triangle1, triangle2), true);
}






