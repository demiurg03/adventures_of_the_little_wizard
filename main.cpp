#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280,665), "Adventures of the Little Wizard");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    sf::Texture tPlayer;
    tPlayer.loadFromFile("test_entity.png");

    float fPlayer=0;

    sf::Sprite sPlayer;
    sPlayer.setTexture(tPlayer);
    sPlayer.setTextureRect( sf::IntRect(0,0,50,50) );
    sPlayer.setPosition(50,100);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            sPlayer.move(-0.1,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            sPlayer.move(0.1,0);

            fPlayer += 0.5;
        if (fPlayer > 8) fPlayer -=8 ;

            sPlayer.setTextureRect( sf::IntRect(0*int(fPlayer),0,50,50) );
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            sPlayer.move(0,-0.1);
        }

        window.clear();
        window.draw(sPlayer);
        window.display();
    }

    return 0;
}
//git
