#ifndef POINT2D_H
#define POINT2D_H

#include <SFML/Graphics.hpp>

class Point2d
{
    public:
        Point2d(int xpos, int ypos, sf::RenderWindow* window, int * windowsize);
        virtual ~Point2d();
        void draw();
        void update();
    protected:
    private:
        int m_x;
        int m_y;
        sf::RenderWindow* m_window;
        sf::RectangleShape shape;
        int * m_windowsize;

};

#endif // POINT2D_H
