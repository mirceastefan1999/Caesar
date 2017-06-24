#include<SFML/Graphics.hpp>
#include<Scene.h>
#include<LevelOne.h>
void initWindow();
sf::RenderWindow Wind;
//SCENES
Scene* lvl1=new LevelOne;
//SCENES
int main()
{
    initWindow();
    Scene* currScene=lvl1;
    while(currScene!=NULL)
    {
        currScene=currScene->Run(Wind);
    }
    return 0;
}

void initWindow()
{
    Wind.create(sf::VideoMode(640, 480),"Caesar", sf::Style::Close);
    Wind.setFramerateLimit(60);
}
