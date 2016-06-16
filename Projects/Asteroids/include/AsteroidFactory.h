#ifndef ASTEROIDFACTORY_H
#define ASTEROIDFACTORY_H

#include <vector>
#include "Asteroid.h"
#include "Ship.h"
#include "Bullet.h"
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

        static AsteroidFactory * getInstance(Ship * ship)
        {
            if (m_instance == 0)
            {//if the instance is null, initialise it
                m_instance = new AsteroidFactory();
            }
            return m_instance;
        }

        void SetShip(Ship * ship)
        {
            m_player_ship = ship;
            m_bullet_vec = m_player_ship->get_bullets();
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

                vector<Bullet>::iterator it;
                for (it = m_bullet_vec->begin(); it != m_bullet_vec->end(); ++it)
                {

                    if ( ( ((*it).getPos()->x - (*m_iterator)->getPos()->x) * ((*it).getPos()->x - (*m_iterator)->getPos()->x) +
                        ((*it).getPos()->y - (*m_iterator)->getPos()->y) * ((*it).getPos()->y - (*m_iterator)->getPos()->y) ) <
                        ((*m_iterator)->getSize() * (*m_iterator)->getSize() ))
                    {
                        (*it).kill();
                        (*m_iterator)->kill();
                    }

                }

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
        Ship* m_player_ship;
        vector<Bullet> *m_bullet_vec;

};

#endif // ASTEROIDFACTORY_H
