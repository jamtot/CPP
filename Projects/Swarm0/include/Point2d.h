#ifndef POINT2D_H
#define POINT2D_H

#include <SFML/Graphics.hpp>
#include "Vector.h"

class Point2d
{
    public:
        Point2d(float xpos, float ypos, sf::RenderWindow* window, int * windowsize);
        virtual ~Point2d();
        void draw();
        void update();
    protected:
    private:
        Vector *m_pos;
        sf::RenderWindow* m_window;
        sf::RectangleShape* m_shape;
        int * m_windowsize;

};

#endif // POINT2D_H
