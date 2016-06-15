#include "Asteroid.h"
#include "Funcs.h"

Asteroid::Asteroid(float x, float y, float asize, float maxspeed, sf::RenderWindow* window, int* windowsize)
{
    m_window = window;
    m_windowsize = windowsize;
    m_max_speed = maxspeed;
    m_size = asize;
    m_pos = new sf::Vector2f(x,y);
    m_velocity = new sf::Vector2f(Funcs::ZeroToX(m_max_speed*2)-m_max_speed, Funcs::ZeroToX(m_max_speed*2)-m_max_speed);
    m_shape = new sf::ConvexShape(8);
    m_shape->setPoint(0, sf::Vector2f(0.f,1.f)*m_size);
    m_shape->setPoint(1, sf::Vector2f(.75f,.75f)*m_size);
    m_shape->setPoint(2, sf::Vector2f(1.f,0.f)*m_size);
    m_shape->setPoint(3, sf::Vector2f(.75f,-.75f)*m_size);
    m_shape->setPoint(4, sf::Vector2f(0.f,-1.f)*m_size);
    m_shape->setPoint(5, sf::Vector2f(-.75f,-.75f)*m_size);
    m_shape->setPoint(6, sf::Vector2f(-1.f,0.f)*m_size);
    m_shape->setPoint(7, sf::Vector2f(-.75f,.75f)*m_size);
    // adding 128 to modulo 128 to avoid very dark asteroids
    m_shape->setFillColor(sf::Color((rand()%128)+128,(rand()%128)+128,(rand()%128)+128));
    m_shape->setPosition(*m_pos);

    m_alive = true;

    //stop asteroids spawning ON player
    //make them spawn offscreen and make sure they come on

}

Asteroid::~Asteroid()
{
    //dtor
}

void Asteroid::draw()
{
    if (m_alive)
        m_window->draw(*m_shape);
}

void Asteroid::update()
{
    *m_pos+=*m_velocity;
    m_shape->setPosition(*m_pos);
    /*if ( m_pos->x < 0-m_size || m_pos->x > m_windowsize[0]+m_size
        || m_pos->y < 0-m_size || m_pos->y > m_windowsize[1]+m_size)
        m_alive = false;*/

    if (m_pos->x < 0-m_size)
        m_pos->x = m_windowsize[0]+m_size;
    else if (m_pos->x > m_windowsize[0]+m_size)
        m_pos->x = 0-m_size;

    if (m_pos->y < 0-m_size)
        m_pos->y = m_windowsize[1]+m_size;
    else if (m_pos->y > m_windowsize[1]+m_size)
        m_pos->y = 0-m_size;
}

bool Asteroid::isAlive()
{
    return m_alive;
}
