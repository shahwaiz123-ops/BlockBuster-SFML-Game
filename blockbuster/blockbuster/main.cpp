
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


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
using namespace sf;
void centertext(Text& text, float x, float y) {
    FloatRect bounds = text.getLocalBounds();
    text.setOrigin({
        bounds.position.x + bounds.size.x / 2, bounds.position.y + bounds.size.y / 2,
        });
    text.setPosition({ x,y });

}

void drawMenu(sf::RenderWindow& window,sf::Font& font, int gameStarted)
{
    sf::Text title(font, "BLOCK BUSTER", 55);
    title.setFillColor(sf::Color::Cyan);
    title.setStyle(sf::Text::Bold);
    centertext(title, 300.f, 200.f);
    window.draw(title);
    string options[3] = {
        "NEW GAME",
        "CONTINUE GAME",
        "EXIT GAME"
    };
    sf::RectangleShape button({ 300.f, 60.f });
    sf::Vector2f mouse = window.mapPixelToCoords(
        sf::Mouse::getPosition(window)
    );
    for (int i = 0; i < 3; i++)
    {
        button.setPosition({
            150.f, 280.f + i * 85.f
            });
        button.setOutlineThickness(2.f);
        button.setOutlineColor(sf::Color::Cyan);
        // Hover effect
        if (button.getGlobalBounds().contains(mouse))
            button.setFillColor(sf::Color(40, 130, 220));
        else
            button.setFillColor(sf::Color(25, 55, 110));
        // Disable Continue before New Game
        if (i == 1 && gameStarted == 0)
            button.setFillColor(sf::Color(65, 65, 75));
        sf::Text text(font, options[i], 25);
        text.setFillColor(sf::Color::White);
        centertext(text, 300.f, 310.f + i * 85.f);
        window.draw(button);
        window.draw(text);
    }
}

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({ 600, 700 }), "Block Buster"
    );
    window.setFramerateLimit(60);
    // Load font
    sf::Font font;
    if (!font.openFromFile("arial.ttf"))
    {
        cout << "Font loading failed!" << endl;
        return 1;
    }
    int screen = 0;
    int gameStarted = 0;
    int score = 0;
    int level = 1;
    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            // ESC returns to main menu
            if (const auto* key =
                event->getIf<sf::Event::KeyPressed>())
            {
                if (key->code == sf::Keyboard::Key::Escape)
                    screen = 0;
            }
            // Mouse click detection
            if (const auto* click =
                event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (click->button == sf::Mouse::Button::Left
                    && screen == 0)
                {
                    sf::Vector2f mouse =
                        window.mapPixelToCoords(click->position);
                    float x = mouse.x;
                    float y = mouse.y;
                    // NEW GAME
                    if (x >= 150 && x <= 450 &&
                        y >= 280 && y <= 340)
                    {
                        score = 0;
                        level = 1;
                        gameStarted = 1;
                        screen = 1;
                    }
                    // CONTINUE GAME
                    else if (x >= 150 && x <= 450 &&
                        y >= 365 && y <= 425)
                    {
                        if (gameStarted == 1)
                            screen = 1;
                    }
                    // EXIT GAME
                    else if (x >= 150 && x <= 450 &&
                        y >= 450 && y <= 510)
                    {
                        window.close();
                    }
                }
            }
        }

        if (!window.isOpen())
            break;
        window.clear(sf::Color(25, 25, 45));      
        // Main menu screen
        if (screen == 0)
        {
            drawMenu(window, font, gameStarted);
        }
        // Gameplay screen
        else if (screen == 1)
        {
            drawBricks(window);
            drawPlayer(window);
        }
        window.display();
    }
    return 0;
}