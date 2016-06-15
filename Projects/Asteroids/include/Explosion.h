#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Particle.h"

using namespace std;

class Explosion
{
    public:
        Explosion(sf::Vector2f pos, int lifespan, int num_parts, sf::RenderWindow* window)
        {
            m_lifespan = lifespan;
            m_pos = pos;
            m_window = window;
            for (int i = 0; i < num_parts; i++){
                m_particles.push_back( Particle(m_pos, sf::Vector2f(2*( rand() / RANDMAX ) -1, 2*( rand() / RANDMAX ) -1)));
            }
        }
        virtual ~Explosion() {}
        void update() {}
        void draw() {}
    protected:
    private:
        int m_lifespan;
        int m_num_parts;
        sf::Vector2f *m_pos;
        sf::RenderWindow* m_window;
        vector<Particle> m_particles; // 2*( rand() / RANDMAX ) -1
};

#endif // EXPLOSION_H
