#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280,665), "Adventures of the Little Wizard");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    sf::Texture tPlayer;
    tPlayer.loadFromFile("entity.png");

    sf::Sprite sPlayer;
    sPlayer.setTexture(tPlayer);
    sPlayer.setPosition(50,100);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sPlayer);
        window.display();
    }

    return 0;
}
//git
