#include <SFML/Graphics.hpp>
#include "game/model/Model.h"
#include "game/view/TestView.h"

int main()
{
    Model<int> model;
    TestView view("Test View", model);

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Right) {
                    model.setData(10);
                }
            }
        }

        window.clear(sf::Color::Black);

        window.display();
    }

    return 0;
}

