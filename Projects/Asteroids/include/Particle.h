#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>

class Particle
{
    public:
        Particle(sf::Vector2f pos,sf::Vector2f vel, float speed) {}
        virtual ~Particle() {}
        void update()
        {
            m_pos+=m_velocity*m_speed;
        }
        void draw()
        {
            m_window->draw(*m_shape);
        }
    protected:
    private:
        sf::RenderWindow *m_window;
        sf::RectangleShape *m_shape;
        sf::Vector2f *m_pos;
        sf::Vector2f *m_velocity;
        float m_speed;
};

#endif // PARTICLE_H
