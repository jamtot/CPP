#ifndef BOID_H
#define BOID_H

#include "Vector.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>

using namespace std;

class Boid
{
    public:
        Boid(float x, float y, sf::RenderWindow * window, int * windowsize);//, vector<Boid*> * boidvec);
        virtual ~Boid();
        void draw();
        void update();
        void run(vector<Boid*>& boids);
        void applyforce(Vector force);
        void flock(vector<Boid*>& boids);
        Vector seek(Vector target);
        Vector separate(vector<Boid*>& boids);
        Vector align(vector<Boid*>& boids);
        Vector cohesion(vector<Boid*>& boids);
        void borders();

        Vector getPos(){return *m_pos;}
        Vector getVel(){return *m_velocity;}
    protected:
    private:
        sf::RenderWindow * m_window;
        int * m_windowsize;
        sf::CircleShape* m_shape;

        //vector<Boid*> * m_boidvec;

        Vector * m_pos;
        Vector * m_velocity;
        Vector * m_acceleration;
        float m_r;
        float m_maxforce; // Maximum steering force
        float m_maxspeed; // Maximum speed
        float m_rotation;
};

#endif // BOID_H
