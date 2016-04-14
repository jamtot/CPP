#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include "Vector.h"

class Ship
{
    public:
        Ship(float x, float y, float width, float length, sf::RenderWindow* window, int* windowsize);
        virtual ~Ship();
        void draw();
        void update();
    protected:
    private:
        Vector* m_pos;
        float m_width, m_length;
        sf::RenderWindow* m_window;
        sf::ConvexShape* m_shape;
        int * m_windowsize;

        Vector* m_acceleration;
        float m_rotation_speed;

};

#endif // SHIP_H
