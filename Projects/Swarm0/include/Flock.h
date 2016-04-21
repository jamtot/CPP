#ifndef FLOCK_H
#define FLOCK_H

#include <vector>
#include "Boid.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Flock
{
    public:
        Flock(sf::RenderWindow* window, int * windowsize);
        virtual ~Flock();
        void draw();
        void update();
        void addboid(float x, float y);
        vector<Boid*>& getBoids();
    protected:
    private:
        sf::RenderWindow * m_window;
        int * m_windowsize;
        vector<Boid*> m_boids;
};

#endif // FLOCK_H
