#include <SFML/Graphics.hpp>
#include <iostream>
static sf::Sprite oWall;






class CPlayer{

float width,height;
float x,y;

sf::Sprite spritePlayer;
sf::Texture texturePlayer;


public:

CPlayer(){
texturePlayer.loadFromFile("entity.png");
spritePlayer.setTexture(texturePlayer);
spritePlayer.setPosition(0,100);

x = spritePlayer.getPosition().x;
y = spritePlayer.getPosition().y;

width = spritePlayer.getGlobalBounds().width;
height = spritePlayer.getGlobalBounds().height;

}


void update(){
float _width,_height;
float _x,_y;


_x = oWall.getPosition().x;
_y= oWall.getPosition().y;

_width = oWall.getGlobalBounds().width;
_height = oWall.getGlobalBounds().height;



if(!(x <= _x+_width&& x+width >= _x && y <= _y+_height &&y+height >= _y)){
y+=0.1f;
}
else{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        y-=100;
    }
}




if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
x+=0.1f;
}

if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
x-=0.1f;
}




spritePlayer.setPosition(x,y);

}

void draw(sf::RenderWindow& window){
window.draw(spritePlayer);
}


sf::Texture getTexture() const
{
return texturePlayer;
}
};





int main()
{
sf::RenderWindow window(sf::VideoMode(1280,665),"Adventures of the Little Wizard");

CPlayer player;


oWall.setTexture(player.getTexture());
oWall.setPosition(0,480);
oWall.setTextureRect(sf::IntRect(0,0,1280,50));




while (window.isOpen())
{
sf::Event event;
while (window.pollEvent(event))
{
if (event.type == sf::Event::Closed)
window.close();
}

window.clear();

player.update();
player.draw(window);

window.draw(oWall);
window.display();
}

return 0;
}
