#include "Player.h"

Player::Player()
{
    //ctor
    m_jumping=false;
}

Player::~Player()
{
    //dtor
}
Player::Player(std::string path_to_texture,sf::Vector2f o_position)
{
    m_texture.loadFromFile(path_to_texture);
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(o_position);
    m_jumping=false;
}
Player::Player(std::string path_to_texture,sf::Vector2f o_position,sf::Vector2f scale)
{
    m_texture.loadFromFile(path_to_texture);
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(o_position);
    m_sprite.setScale(scale);
    m_jumping=false;
}
sf::Vector2f Player::getPosition()
{
    return m_sprite.getPosition();
}
sf::Vector2f Player::getVelocity()
{
    return velocity;
}
void Player::setVelocity(float x,float y)
{
    velocity.x=x;
    velocity.y=y;
}
void Player::Move(sf::Vector2f offset)
{
    m_sprite.move(offset);
}
void Player::Draw(sf::RenderWindow& Wind)
{
    Wind.draw(m_sprite);
}
void Player::Jump(std::string option)
{
    if(option=="start")
    {
        if(!m_jumping)
        {
            m_jumping=true;
            velocity.y=-100.0f;
        }
    }
    else if(option=="stop")
    {
        if(m_jumping)
        {
            m_jumping=false;
        }
    }
    else
    {
        printf("invalid option when calling jump!");
    }
}
void Player::Fall(float dt)
{
    if(m_jumping)
    {
        m_sprite.move(0,dt*velocity.y);
        velocity.y+=100*dt;
    }
}
