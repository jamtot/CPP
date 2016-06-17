#include "ExplosionFactory.h"

ExplosionFactory * ExplosionFactory::m_instance = 0;

ExplosionFactory::ExplosionFactory()
{
    //ctor
}

ExplosionFactory::~ExplosionFactory()
{
    //dtor
}

void ExplosionFactory::Clear()
{
    for(size_t i = 0; i < m_explosions.size(); ++i)
    {
        delete m_explosions[i];
    }
    m_explosions.clear();
}

void ExplosionFactory::SetWindow(sf::RenderWindow* window)
{
    m_window = window;
}
