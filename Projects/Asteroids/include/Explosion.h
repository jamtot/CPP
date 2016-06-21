#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Particle.h"

using namespace std;

class Explosion
{
    public:
        Explosion(sf::Vector2f pos, float speed, int lifespan, int num_parts, sf::RenderWindow* window)
        {
            m_lifespan = lifespan;
            m_pos = new sf::Vector2f(pos);
            m_window = window;
            for (int i = 0; i < num_parts; i++){
                m_particles.push_back( Particle(*m_pos, sf::Vector2f(2*( rand() / RAND_MAX ) -1, 2*( rand() / RAND_MAX ) -1),speed,m_window));
            }
            m_alive = true;
        }
        virtual ~Explosion()
        {
            delete m_pos;
            delete m_window;
        }
        void update()
        {
            m_iterator = m_particles.begin();
            for (; m_iterator != m_particles.end(); ++m_iterator)
            {
                (*m_iterator).update();
            }
            if (m_lifespan > 0)
                m_lifespan--;
            else
                m_alive=false;
        }
        void draw()
        {
            if (m_alive)
            {
                m_iterator = m_particles.begin();
                for (; m_iterator != m_particles.end(); ++m_iterator)
                {
                    (*m_iterator).draw();
                }
            }
        }
        bool isAlive(){return m_alive;}
    protected:
    private:
        int m_lifespan;
        int m_num_parts;
        sf::Vector2f *m_pos;
        sf::RenderWindow* m_window;
        vector<Particle> m_particles; // 2*( rand() / RANDMAX ) -1
        vector<Particle>::iterator m_iterator;
        bool m_alive;
};

#endif // EXPLOSION_H
