#include "Ship.h"

Ship::Ship(float x, float y, float width, float length, sf::RenderWindow* window, int* windowsize)
{
    m_pos = new Vector(x,y);
    m_acceleration = new Vector(0.f, 0.5f);
    m_rotation_speed = 5.f;
    m_width = width;
    m_length = length;
    m_window = window;
    m_windowsize = windowsize;
    m_shape = new sf::ConvexShape(4);
    m_shape->setPoint(0, sf::Vector2f(0,0));
    m_shape->setPoint(1, sf::Vector2f(-(m_width/2),(-m_length/2)));
    m_shape->setPoint(2, sf::Vector2f(0,(m_length/2)));
    m_shape->setPoint(3, sf::Vector2f((m_width/2),(-m_length/2)));
    m_shape->setFillColor(sf::Color(255,0,255));
    m_shape->setPosition(m_pos->getX(), m_pos->getY());
}

Ship::~Ship()
{
    //dtor
}

void Ship::draw(){
    m_window->draw(*m_shape);
}

void Ship::update(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        // Up key is pressed: move our ship
        m_pos->add(m_acceleration);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        // Up key is pressed: move our ship
        m_pos->sub(m_acceleration);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_acceleration->rotate(m_rotation_speed);
        m_shape->rotate(-m_rotation_speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_acceleration->rotate(-m_rotation_speed);
        m_shape->rotate(m_rotation_speed);
    }

    //bounds checking
    if (m_pos->getX() > m_windowsize[0] - m_length/2) m_pos->setX(m_windowsize[0] - m_length/2);
    else if (m_pos->getX() < m_length/2) m_pos->setX(m_length/2);
    if (m_pos->getY() > m_windowsize[1] - m_length/2) m_pos->setY(m_windowsize[1] - m_length/2);
    else if (m_pos->getY() < m_length/2) m_pos->setY(m_length/2);

    //set position
    m_shape->setPosition(m_pos->getX(), m_pos->getY());
}
