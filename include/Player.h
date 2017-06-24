#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
class Player
{
    public:
        Player();
        Player(std::string path_to_texture,sf::Vector2f o_position);
        Player(std::string path_to_texture,sf::Vector2f o_position,sf::Vector2f scale);
        sf::Vector2f getPosition();
        void setVelocity(float x,float y);
        sf::Vector2f getVelocity();
        void Move(sf::Vector2f offset);
        void Jump(std::string option);
        void Fall(float dt);
        void Draw(sf::RenderWindow& Wind);
        virtual ~Player();

    protected:

    private:
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        sf::Vector2f velocity;
        bool m_jumping;
};

#endif // PLAYER_H
