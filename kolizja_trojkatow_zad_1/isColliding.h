#ifndef KOLIZJA_TROJKATOW_ZAD_1_ISCOLLIDING_H
#define KOLIZJA_TROJKATOW_ZAD_1_ISCOLLIDING_H

#include <iostream>
#include <vector>
#include <array>
#include <cmath>

struct vec2
{
    float x, y;
};
struct triangle
{
    std::array<vec2, 3> points;
};

bool isColliding(const triangle &triangle1, const triangle &triangle2)
{

    std::vector<vec2> normalAxis = {{triangle1.points.at(1).y - triangle1.points.at(0).y, -(triangle1.points.at(1).x -
                                                                                            triangle1.points.at(0).x)},
                                    {triangle1.points.at(2).y - triangle1.points.at(1).y, -(triangle1.points.at(2).x -
                                                                                            triangle1.points.at(1).x)},
                                    {triangle1.points.at(0).y - triangle1.points.at(2).y, -(triangle1.points.at(0).x -
                                                                                            triangle1.points.at(2).x)},
                                    {triangle2.points.at(1).y - triangle2.points.at(0).y, -(triangle2.points.at(1).x -
                                                                                            triangle2.points.at(0).x)},
                                    {triangle2.points.at(2).y - triangle2.points.at(1).y, -(triangle2.points.at(2).x -
                                                                                            triangle2.points.at(1).x)},
                                    {triangle2.points.at(0).y - triangle2.points.at(2).y, -(triangle2.points.at(0).x -
                                                                                            triangle2.points.at(2).x)}};

    for (unsigned i = 0; i < normalAxis.size(); i++)
    {
        vec2 axis = normalAxis[i];

        float minOfTriangle1{INFINITY};
        float maxOfTriangle1{-INFINITY};
        float minOfTriangle2{INFINITY};
        float maxOfTriangle2{-INFINITY};

        for (const auto &point : triangle1.points)
        {
            float projection = point.x * axis.x + point.y * axis.y;

            if (projection < minOfTriangle1)
            {
                minOfTriangle1 = projection;
            }
            if (projection > maxOfTriangle1)
            {
                maxOfTriangle1 = projection;
            }
        }
        for (const auto &point : triangle2.points)
        {
            float projection = point.x * axis.x + point.y * axis.y;

            if (projection < minOfTriangle2)
            {
                minOfTriangle2 = projection;
            }
            if (projection > maxOfTriangle2)
            {
                maxOfTriangle2 = projection;
            }
        }
        if (!(minOfTriangle1 <= maxOfTriangle2 && maxOfTriangle1 >= minOfTriangle2))
        {
            return false;
        }
    }
    return true;
}

#endif //KOLIZJA_TROJKATOW_ZAD_1_ISCOLLIDING_H
