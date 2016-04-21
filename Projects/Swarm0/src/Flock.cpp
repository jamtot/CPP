#include "Flock.h"

Flock::Flock(sf::RenderWindow* window, int * windowsize)
{
    m_window = window;
    m_windowsize = windowsize;
}

Flock::~Flock()
{
    //dtor
}

void Flock::draw()
{
    vector<Boid*>::iterator  it;
    for (it = m_boids.begin(); it!=m_boids.end(); ++it)
    {
        (*it)->draw();
    }/**/
}

void Flock::update()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i position = sf::Mouse::getPosition(*m_window);
        addboid(position.x, position.y);
    }

    vector<Boid*>::iterator  it;
    for (it = m_boids.begin(); it!=m_boids.end(); ++it)
    {
        (*it)->run(m_boids);
    }/**/
}

void Flock::addboid(float x, float y)
{
    m_boids.push_back(new Boid(x,y,m_window,m_windowsize));//, m_boids));
}

vector<Boid*>& Flock::getBoids(){ return m_boids; }
