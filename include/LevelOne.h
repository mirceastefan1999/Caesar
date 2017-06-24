#ifndef LEVELONE_H
#define LEVELONE_H

#include <Scene.h>
#include<Player.h>

class LevelOne : public Scene
{
    public:
        LevelOne();
        virtual ~LevelOne();
        virtual Scene* Run(sf::RenderWindow& Wind);
        void HandleInput();

    protected:

    private:
        Player* caesar;
};

#endif // LEVELONE_H
