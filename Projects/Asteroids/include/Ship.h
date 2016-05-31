#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <vector>
#include <math.h>

#define DEGREES_TO_RADIANS(angle) ((angle) / 180.0 * M_PI)

using namespace std;

class Ship
{
    public:
        Ship(float x, float y, float width, float length, sf::RenderWindow* window, int* windowsize);
        virtual ~Ship();
        void draw();
        void update();
        void fire_bullet();
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
        vector<Bullet> *m_bullet_vec;
};

#endif // SHIP_H
