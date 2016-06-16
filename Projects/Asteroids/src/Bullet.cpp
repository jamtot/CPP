#include "Bullet.h"

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f dir, float speed, float bsize, sf::RenderWindow* window, int* windowsize)
{
    m_pos = new sf::Vector2f(pos);
    m_dir = new sf::Vector2f(dir);
    m_size = bsize;
    m_window = window;
    m_windowsize = windowsize;
    m_shape = new sf::CircleShape(m_size);
    m_shape->setFillColor(sf::Color(255,0,0));
    m_shape->setPosition(*m_pos);

    m_speed = speed;
    *m_dir=(*m_dir)*m_speed;
    m_alive = true;
}

Bullet::~Bullet()
{
    //dtor
}

void Bullet::draw()
{
    if (m_alive)
        m_window->draw(*m_shape);
}

void Bullet::update()
{
    *m_pos+=*m_dir;
    m_shape->setPosition(*m_pos);
    if ( m_pos->x < 0 || m_pos->x > m_windowsize[0]
        || m_pos->y < 0 || m_pos->y > m_windowsize[1])
        m_alive = false;
}

bool Bullet::isAlive() { return m_alive; }
sf::Vector2f * Bullet::getPos() { return m_pos; }
void Bullet::kill() { m_alive = false; }
