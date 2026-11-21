#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({ 800, 600 }),
        "BlockBuster Game"
    );

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Blue);
        window.display();
    }

    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    cout << "hello world";
}
