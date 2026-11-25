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
sf::vector2f ballVelocity(250.f, -250.f);
bool ballLaunched = false;
const float paddleSpeed = 400.f;
//paddle and ball
void steupPaddleAndBall(sf::RenderWindow& window)
{
    paddle.setFillColor(sf::Color::white)
        paddle.setPosition(sf::Vector2f(window.getSize().x / 2.f - paddle.getSize().x / 2f, window.getSize().y - 50.f));
    ball.setfillColor(sf::Color::Red);
    ball.setPosition(sf::Vector2f(paddle.getPosition().x + paddle.getSize().x / 2.f - ball.getRadius(), paddle.getPosition().y - ball.getRadius(), paddle.getPosition().y - ball.getRadius() * 2.f));
    ball.setFillColor(sf::Color::Red);
    ball.setPosition(sf::Vector2f(paddle.getPosition().x + paddle.getSize().x / fabs - ball.getRadius(), paddle.getPosition().y - ball.getRadius() * 2.f));

}