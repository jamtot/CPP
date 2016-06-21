#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>

class Particle
{
    public:
        Particle(sf::Vector2f pos,sf::Vector2f vel, float speed, sf::RenderWindow * window)
        {
            m_window = window;
            m_alive = true;
            m_speed = speed;
            m_pos = new sf::Vector2f(pos);
            m_velocity = new sf::Vector2f(vel);
            m_shape = new sf::RectangleShape(sf::Vector2f(1,1));
            //m_shape->setSize(sf::Vector2f(1,1));
            m_shape->setPosition(*m_pos);
        }
        virtual ~Particle()
        {
            delete m_window;
            delete m_shape;
            delete m_pos;
            delete m_velocity;
        }
        void update()
        {
            *m_pos+=*m_velocity*m_speed;
            m_shape->setPosition(*m_pos);
        }
        void draw()
        {
            if (m_alive)
                m_window->draw(*m_shape);
        }
        void kill(){m_alive=false;}
    protected:
    private:
        sf::RenderWindow *m_window;
        sf::RectangleShape *m_shape;
        sf::Vector2f *m_pos;
        sf::Vector2f *m_velocity;
        float m_speed;
        bool m_alive;
};

#endif // PARTICLE_H
