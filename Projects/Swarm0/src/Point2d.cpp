#include "Point2d.h"

Point2d::Point2d(float xpos, float ypos, sf::RenderWindow* window, int * windowsize)
{
    m_pos = new Vector(xpos, ypos);
    m_window = window;
    m_windowsize = windowsize;
    m_shape = new sf::RectangleShape(sf::Vector2f(2,2));
    //m_shape.setSize(sf::Vector2f(2, 2));
    m_shape->setFillColor(sf::Color(255,255,255));
    m_shape->setPosition(m_pos->getX(), m_pos->getY());
}

Point2d::~Point2d()
{
    //dtor
}

void Point2d::draw()
{
    m_window->draw(*m_shape);
}

void Point2d::update()
{
    //move to a random position within 2 pixels of last position
    m_pos->addX((rand()%5)-2);
    m_pos->addY((rand()%5)-2);

    //check bounds
    if (m_pos->getX() > m_windowsize[0]) m_pos->setX(m_windowsize[0]-1);
    else if (m_pos->getX() < 0) m_pos->setX(0);
    if (m_pos->getY() > m_windowsize[1]) m_pos->setY(m_windowsize[1]-1);
    else if (m_pos->getY() < 0) m_pos->setY(0);

    //set position
    m_shape->setPosition(m_pos->getX(), m_pos->getY());
}
