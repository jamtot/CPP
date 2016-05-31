#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include "Vector.h"

#define DEGREES_TO_RADIANS(angle) ((angle) / 180.0 * M_PI)

class Ship
{
    public:
        Ship(float x, float y, float width, float length, sf::RenderWindow* window, int* windowsize);
        virtual ~Ship();
        void draw();
        void update();
    protected:
    private:
        float m_width, m_length;
        sf::RenderWindow* m_window;
        sf::ConvexShape* m_shape;
        int * m_windowsize;

        float m_rotation;
        float m_rotation_speed;

        sf::Vector2f* m_pos;
        sf::Vector2f* m_acceleration;
        sf::Vector2f* m_velocity;
        float m_max_speed;

        //add vector of bullets
};

#endif // SHIP_H
