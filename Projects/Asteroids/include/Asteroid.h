#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>

class Asteroid
{
    public:
        Asteroid(float x, float y, float asize, float maxspeed, sf::RenderWindow* window, int* windowsize);
        virtual ~Asteroid();
        void draw();
        void update();
        bool isAlive();
    protected:
    private:
        sf::RenderWindow* m_window;
        sf::ConvexShape* m_shape;
        int * m_windowsize;
        sf::Vector2f* m_pos;
        sf::Vector2f* m_velocity;
        float m_size;
        float m_max_speed;
        bool m_alive;
};

#endif // ASTEROID_H
