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