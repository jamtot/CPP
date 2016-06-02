#ifndef ASTEROIDFACTORY_H
#define ASTEROIDFACTORY_H

#include <vector>
#include "Asteroid.h"
//#include <iostream>

using namespace std;

// this class is a singleton
// there will only be one
class AsteroidFactory
{
    public:
        AsteroidFactory() {}

        ~AsteroidFactory()
        {
            for(size_t i = 0; i < m_asteroids.size(); ++i)
            {
                delete m_asteroids[i];
            }
            m_asteroids.clear();
        }

        static AsteroidFactory * getInstance()
        {
            if (m_instance == 0)
            {//if the instance is null, initialise it
                m_instance = new AsteroidFactory();
            }
            return m_instance;
        }

        void Clear()
        {
            for(size_t i = 0; i < m_asteroids.size(); ++i)
            {
                delete m_asteroids[i];
            }
            m_asteroids.clear();
        }

        void CreateObject(float x, float y, float asize, float maxspeed, sf::RenderWindow* window, int* windowsize)
        {
            m_asteroids.push_back(new Asteroid(x, y, asize, maxspeed, window, windowsize));
        }

        void draw()
        {
            m_iterator = m_asteroids.begin();
            for (; m_iterator != m_asteroids.end(); ++m_iterator)
            {
                (*m_iterator)->draw();
            }
        }

        void update()
        {
            m_iterator = m_asteroids.begin();
            for (; m_iterator != m_asteroids.end(); ++m_iterator)
            {
                if ((*m_iterator)->isAlive())
                    (*m_iterator)->update();
                else
                {
                    m_asteroids.erase(m_iterator);
                    --m_iterator;
                    //cout << m_asteroids.size() << endl;
                }
            }
        }
    protected:
    private:
        static AsteroidFactory * m_instance;
        vector<Asteroid*> m_asteroids;
        vector<Asteroid*>::iterator m_iterator;
};

#endif // ASTEROIDFACTORY_H
