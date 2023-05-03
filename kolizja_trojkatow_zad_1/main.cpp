#include <SFML/Graphics.hpp>
#include "isColliding.h"


int main()
{
    triangle triangle1{vec2{150.f, 150.f}, vec2{250.f, 300.f}, vec2{500.f, 250.f}};
    triangle triangle2{vec2{190.f, 180.f}, vec2{25.f, 300.f}, vec2{50.f, 25.f}};


    sf::RenderWindow window(sf::VideoMode(800, 800), "Triangle Collision");

    sf::VertexArray firstTriangle(sf::Triangles, 3);
    firstTriangle[0].position = sf::Vector2f(triangle1.points.at(0).x, triangle1.points.at(0).y);
    firstTriangle[1].position = sf::Vector2f(triangle1.points.at(1).x, triangle1.points.at(1).y);
    firstTriangle[2].position = sf::Vector2f(triangle1.points.at(2).x, triangle1.points.at(2).y);
    firstTriangle[0].color = sf::Color::Green;
    firstTriangle[1].color = sf::Color::Green;
    firstTriangle[2].color = sf::Color::Green;

    sf::VertexArray secondTriangle(sf::Triangles, 3);
    secondTriangle[0].position = sf::Vector2f(triangle2.points.at(0).x, triangle2.points.at(0).y);
    secondTriangle[1].position = sf::Vector2f(triangle2.points.at(1).x, triangle2.points.at(1).y);
    secondTriangle[2].position = sf::Vector2f(triangle2.points.at(2).x, triangle2.points.at(2).y);
    secondTriangle[0].color = sf::Color::Blue;
    secondTriangle[1].color = sf::Color::Blue;
    secondTriangle[2].color = sf::Color::Blue;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        sf::Vector2f diff = sf::Vector2f(mouse_pos) - secondTriangle[1].position;

        float x = diff.x;
        float y = diff.y;

        for (int i = 0; i < secondTriangle.getVertexCount(); ++i)
        {
            secondTriangle[i].position += diff;
        }

        for (auto &point: triangle2.points)
        {
            point.x += x;
            point.y += y;
        }

        if (isColliding(triangle1, triangle2))
        {
            secondTriangle[0].color = sf::Color::Red;
            secondTriangle[1].color = sf::Color::Red;
            secondTriangle[2].color = sf::Color::Red;
        }
        else
        {
            secondTriangle[0].color = sf::Color::Blue;
            secondTriangle[1].color = sf::Color::Blue;
            secondTriangle[2].color = sf::Color::Blue;
        }

        window.clear();
        window.draw(firstTriangle);
        window.draw(secondTriangle);
        window.display();
    }


    return 0;
}
