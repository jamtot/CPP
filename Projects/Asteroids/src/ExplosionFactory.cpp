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

void ExplosionFactory::makeBoom(sf::Vector2f pos)
{
    m_explosions.push_back(new Explosion(pos,5,128,50,m_window));
}

void ExplosionFactory::draw()
{
    m_iterator = m_explosions.begin();
    for (;m_iterator!=m_explosions.end();++m_iterator)
    {
        (*m_iterator)->draw();
    }
}

void ExplosionFactory::update()
{
    m_iterator = m_explosions.begin();
    for (;m_iterator!=m_explosions.end();++m_iterator)
    {
        (*m_iterator)->update();

        if ((*m_iterator)->isAlive())
            (*m_iterator)->update();
        else
        {
            m_explosions.erase(m_iterator);
            --m_iterator;
        }

    }

}
