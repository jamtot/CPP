#include "Bullet.h"

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f dir, float bsize, sf::RenderWindow* window, int* windowsize)
{
    m_pos = new sf::Vector2f(pos);
    m_dir = new sf::Vector2f(dir);
    m_size = bsize;
    m_window = window;
    m_windowsize = windowsize;
    m_shape = new sf::CircleShape(m_size);
    m_shape->setFillColor(sf::Color(255,0,0));
    m_shape->setPosition(*m_pos);

    m_speed = 1.0f;
}

Bullet::~Bullet()
{
    //dtor
}

void Bullet::draw()
{
    m_window->draw(*m_shape);
}

void Bullet::update()
{

}
