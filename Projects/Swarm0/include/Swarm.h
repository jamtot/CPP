#ifndef SWARM_H
#define SWARM_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Point2d.h"

using namespace std;

class Swarm
{
    public:
        Swarm(sf::RenderWindow* window, int points, int * windowsize);
        virtual ~Swarm();
        void draw();
        void update();
    protected:
    private:
        sf::RenderWindow* m_window;
        vector<Point2d*>  m_points;
        int * m_windowsize;
};

#endif // SWARM_H
