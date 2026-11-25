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
//Haram fatima part
#include<SFML/Graphics.hpp>
#include<cmath>
//paddle and ball
sf::RectangleShape paddle(sf::vectors2f(100.f, 15.f));
sf::CircleShape ball(8.f);
//speed of bal,x for horizontal,y for vertical
sf::vector2f ballVelocity(250.f, -250f);
bool ballLaunched = false;
const float paddleSpeed = 400.f;