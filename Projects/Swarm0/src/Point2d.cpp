#include "Point2d.h"

Point2d::Point2d(int xpos, int ypos, sf::RenderWindow* window, int * windowsize)
{
    m_x = xpos;
    m_y = ypos;
    m_window = window;
    m_windowsize = windowsize;
    shape.setSize(sf::Vector2f(2, 2));
    shape.setFillColor(sf::Color(255,255,255));
    shape.setPosition(float(m_x),float(m_y));
}

Point2d::~Point2d()
{
    //dtor
}

void Point2d::draw()
{
    m_window->draw(shape);
}

void Point2d::update()
{
    m_x+=(rand()%5)-2;
    m_y+=(rand()%5)-2;
    if (m_x > m_windowsize[0]) m_x = m_windowsize[0]-1;
    else if (m_x < 0) m_x = 0;
    if (m_y > m_windowsize[1]) m_x = m_windowsize[1]-1;
    else if (m_y < 0) m_y = 0;
    shape.setPosition(float(m_x),float(m_y));
}
