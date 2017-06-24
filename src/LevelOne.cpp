#include "LevelOne.h"

LevelOne::LevelOne()
{
    //ctor
    caesar=new Player("res/characters/caesar.png",sf::Vector2f(0,75),sf::Vector2f(5,5));
}

LevelOne::~LevelOne()
{
    //dtor
    delete caesar;
}
Scene* LevelOne::Run(sf::RenderWindow& Wind)
{
    sf::Event ev;
    int groundLevel=75;
    sf::Clock deltaClock;
    sf::Time deltaTime=sf::Time::Zero;
    deltaClock.restart();
    while(Wind.isOpen())
    {
        deltaTime=deltaClock.getElapsedTime();
        deltaClock.restart();
        while(Wind.pollEvent(ev))
        {
            if(ev.type==sf::Event::Closed)
            {
                Wind.close();
            }
        }
        HandleInput();
        if(caesar->getPosition().y<=groundLevel)
        {
            caesar->Fall(deltaTime.asSeconds());
        }
        else
        {
            caesar->Move(sf::Vector2f(0,groundLevel-caesar->getPosition().y));
            caesar->Jump("stop");
        }
        Wind.clear();
        caesar->Draw(Wind);
        Wind.display();
    }
    return NULL;
}
void LevelOne::HandleInput()
{
    sf::Vector2f step=sf::Vector2f(0,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        caesar->Jump("start");
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        step.x=-1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        step.x=1;
    }
    caesar->Move(step);
}
