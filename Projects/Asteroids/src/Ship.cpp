#include "Ship.h"

Ship::Ship(float x, float y, float width, float length, sf::RenderWindow* window, int* windowsize)
{
    m_pos = new Vector(x,y);
    m_acceleration = new Vector(0.f, 1.f);
    m_velocity = new Vector(0.f, 0.f);
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

    Vector accel(0,0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        Vector thrust = *m_acceleration;
        thrust.rotate(-m_rotation);
        accel.add(thrust);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_rotation-=m_rotation_speed;
        //m_shape->rotate(-m_rotation_speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_rotation+=m_rotation_speed;
        //m_shape->rotate(m_rotation_speed);
    }

    //float rotangle = Vector::angleBetween((*m_pos-*m_velocity), Vector(0,0));

    m_shape->setRotation(m_rotation);
    m_velocity->add(accel);

    //////////////////////////////
	//slow by using reverse vector

	Vector negVel = *m_velocity;
	negVel.byScalar(0.05);

	*m_velocity = *m_velocity - negVel;

	//////////////////////////////

    //bounds checking
    if (m_pos->getX() > m_windowsize[0] - m_length/2) m_pos->setX(m_windowsize[0] - m_length/2);
    else if (m_pos->getX() < m_length/2) m_pos->setX(m_length/2);
    if (m_pos->getY() > m_windowsize[1] - m_length/2) m_pos->setY(m_windowsize[1] - m_length/2);
    else if (m_pos->getY() < m_length/2) m_pos->setY(m_length/2);

    //set position
    m_pos->add(*m_velocity);
    m_shape->setPosition(m_pos->getX(), m_pos->getY());
}
