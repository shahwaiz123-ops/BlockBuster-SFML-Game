
#include <SFML/Graphics.hpp>

#include <iostream>

using namespace std;

// Haram Yaseen's Part

void drawPlayer(sf::RenderWindow& window)

{

    sf::RectangleShape paddle({ 100.f, 14.f });

    sf::CircleShape ball(6.f);

    paddle.setFillColor(sf::Color::Cyan);

    ball.setFillColor(sf::Color::White);

    paddle.setPosition({ 250.f, 650.f });

    ball.setPosition({ 294.f, 638.f });

    window.draw(paddle);

    window.draw(ball);
}
void drawBricks(sf::RenderWindow& window)

{

    sf::RectangleShape brick({ 58.f, 23.f });

    for (int r = 0; r < 8; r++)

    {

        for (int c = 0; c < 10; c++)

        {

            if (r < 2)

                brick.setFillColor(sf::Color::Red);

            else if (r < 5)

                brick.setFillColor(sf::Color::Yellow);

            else

                brick.setFillColor(sf::Color::Green);

            brick.setPosition({

                c * 60.f + 1,

                100.f + r * 25.f + 1

                });

            window.draw(brick);

        }

    }


}
int main()
{
    sf::RenderWindow window(
        sf::VideoMode({ 600, 700 }), "Block Buster");

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (!window.isOpen())
            break;

        window.clear(sf::Color(25, 25, 45));

        drawBricks(window);
        drawPlayer(window);

        window.display();
    }

    return 0;
}