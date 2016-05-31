#include "Ship.h"

Ship::Ship(float x, float y, float width, float length, sf::RenderWindow* window, int* windowsize)
{
    m_pos = new sf::Vector2f(x,y);
    m_acceleration = new sf::Vector2f(0.f, 1.f);
    m_velocity = new sf::Vector2f(0.f, 0.f);
    m_rotation = 0.f;
    m_rotation_speed = 5.f;
    m_max_speed = 5.f;
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
    m_shape->setPosition(*m_pos);
}

Ship::~Ship()
{
    //dtor
}

void Ship::draw(){
    m_window->draw(*m_shape);
}

void Ship::update(){

    sf::Vector2f accel(0,0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        sf::Vector2f thrust = *m_acceleration;
        accel+=thrust;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_rotation-=m_rotation_speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_rotation+=m_rotation_speed;
    }

    float theta = DEGREES_TO_RADIANS(m_rotation);
    float cs = cos(theta);
    float sn = sin(theta);

    sf::Vector2f newAccel;
    newAccel.x = accel.x * cs - accel.y * sn;
    newAccel.y = accel.x * sn + accel.y * cs;

    m_shape->setRotation(m_rotation);
    *m_velocity+=newAccel;

    //////////////////////////////
	//slow by using reverse vector

	sf::Vector2f negVel = *m_velocity * 0.05f;
	*m_velocity = *m_velocity - negVel;

	//////////////////////////////

    //bounds checking
    if (m_pos->x > m_windowsize[0] - m_length/2) m_pos->x = (m_windowsize[0] - m_length/2);
    else if (m_pos->x < m_length/2) m_pos->x = m_length/2;
    if (m_pos->y > m_windowsize[1] - m_length/2) m_pos->y = (m_windowsize[1] - m_length/2);
    else if (m_pos->y < m_length/2) m_pos->y = m_length/2;

    //set position
    *m_pos+=*m_velocity;
    m_shape->setPosition(*m_pos);
}
