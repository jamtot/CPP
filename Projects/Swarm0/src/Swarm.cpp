#include "Swarm.h"

Swarm::Swarm(sf::RenderWindow* window, int points, int * windowsize)
{
    m_window = window;
    m_windowsize = windowsize;
    for (int i = 0; i < points; i++){
        m_points.push_back(new Point2d(rand()%m_windowsize[0],rand()%m_windowsize[1],m_window,m_windowsize));
    }
}

Swarm::~Swarm()
{
    //dtor
}

void Swarm::draw()
{
    vector<Point2d*>::iterator  it;
    for (it = m_points.begin(); it!=m_points.end(); ++it)
    {
        (*it)->draw();
    }
}

void Swarm::update()
{
    vector<Point2d*>::iterator  it;
    for (it = m_points.begin(); it!=m_points.end(); ++it)
    {
        (*it)->update();
    }
}
