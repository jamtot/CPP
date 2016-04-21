#include "Boid.h"

Boid::Boid(float x, float y, sf::RenderWindow * window, int * windowsize)//, vector<Boid*> * boidvec)
{
    m_pos = new Vector(x,y);
    m_acceleration = new Vector(0, 0);

    float angle = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(2*M_PI)));
    //float angle = 0;
    m_velocity = new Vector(cos(angle), sin(angle));

    m_r = 2.0;
    m_maxforce = 2;
    m_maxspeed = 1.0;

    m_window = window;
    m_windowsize = windowsize;
    m_shape = new sf::CircleShape(10,3);
    m_shape->setFillColor(sf::Color(255,255,255));
    m_shape->setPosition(m_pos->getX(), m_pos->getY());

    //m_boidvec = boidvec;
}

Boid::~Boid()
{
    //dtor
}

void Boid::draw()
{
    m_window->draw(*m_shape);
}

void Boid::update()
{
   // Update velocity
    m_velocity->add(*m_acceleration);
    // Limit speed
    m_velocity->limit(m_maxspeed);
    m_pos->add(*m_velocity);
    // Reset accelertion to 0 each cycle
    m_acceleration->setVector(Vector(0,0));

    m_shape->setPosition(m_pos->getX(), m_pos->getY());
    Vector vel = *m_velocity;
    vel.normalise();

    //atan2(v1.s_cross(v2), v1.dot(v2))
    //Vector org(0,1);
    //float dot = vel.getX()*org.getX() + vel.getY()*org.getY();      // dot product
    //float det = vel.getX()*org.getY() - vel.getY()*org.getX();      // determinant
    //float angle = atan2(det, dot);
    //float angle = vel
    //angle+=90;
    //m_shape->setRotation(angle);
}

void Boid::run(vector<Boid*>& boids)
{
    flock(boids);
    borders();
}

void Boid::applyforce(Vector force)
{
    m_acceleration->add(force);
}

void Boid::flock(vector<Boid*>& boids)
{
    Vector sep = separate(boids);   // Separation
    Vector ali = align(boids);      // Alignment
    Vector coh = cohesion(boids);   // Cohesion
    // Arbitrarily weight these forces
    sep.byScalar(1.5);
    ali.byScalar(1.0);
    coh.byScalar(1.0);
    // Add the force vectors to acceleration
    applyforce(sep);
    applyforce(ali);
    applyforce(coh);
}

Vector Boid::seek(Vector target)
{
    Vector desired = Vector::sub(target, *m_pos);  // A vector pointing from the location to the target
    // Scale to maximum speed
    desired.normalise();
    desired.byScalar(m_maxspeed);

    // Steering = Desired minus Velocity
    Vector steer = Vector::sub(desired, *m_velocity);
    steer.limit(m_maxforce);  // Limit to maximum steering force
    return steer;
}

Vector Boid::separate(vector<Boid*>& boids)
{
    float desiredseparation = 25.0f;
    Vector steer(0, 0);
    int count = 0;

    vector<Boid*>::iterator it;
    for (it = boids.begin(); it!=boids.end(); ++it)
    {
        float d = Vector::dist(*m_pos, (*it)->getPos());
        // 0 means it's the same boid
        if ((d > 0) && (d < desiredseparation))
        {
            // Calculate vector pointing away from neighbor
            Vector diff = Vector::sub(*m_pos, (*it)->getPos());
            diff.normalise();
            diff.div(d);        // Weight by distance
            steer.add(diff);
            count++;            // Keep track of how many
        }
    }

    // Average -- divide by how many
    if (count > 0)
    {
        steer.div(float(count));
    }

    // As long as the vector is greater than 0
    if (steer.mag() > 0)
    {

        // Implement Reynolds: Steering = Desired - Velocity
        steer.normalise();
        steer.byScalar(m_maxspeed);
        steer.sub(*m_velocity);
        steer.limit(m_maxforce);
    }
    return steer;
}

Vector Boid::align(vector<Boid*>& boids)
{
    float neighbordist = 50;
    Vector sum(0, 0);
    int count = 0;

    vector<Boid*>::iterator it;
    for (it = boids.begin(); it!=boids.end(); ++it)
    {
        float d = Vector::dist(*m_pos, (*it)->getPos());
        if ((d > 0) && (d < neighbordist))
        {
            sum.add((*it)->getVel());
            count++;
        }
    }
    if (count > 0)
    {
        sum.div(float(count));

        // Implement Reynolds: Steering = Desired - Velocity
        sum.normalise();
        sum.byScalar(m_maxspeed);
        Vector steer = Vector::sub(sum, *m_velocity);
        steer.limit(m_maxforce);
        return steer;
    }
    else
    {
        return Vector(0, 0);
    }
}

Vector Boid::cohesion(vector<Boid*>& boids)
{
    float neighbordist = 50;
    Vector sum(0, 0);   // Start with empty vector to accumulate all locations
    int count = 0;

    vector<Boid*>::iterator it;
    for (it = boids.begin(); it!=boids.end(); ++it)
    {
        float d = Vector::dist(*m_pos, (*it)->getPos());
        if ((d > 0) && (d < neighbordist))
        {
            sum.add((*it)->getPos()); // Add location
            count++;
        }
    }
    if (count > 0) {
        sum.div(float(count));
        return seek(sum);  // Steer towards the location
    }
    else
    {
        return Vector(0, 0);
    }
}

void Boid::borders()
{
    if (m_pos->getX() < -m_r) m_pos->setX(m_windowsize[0]+m_r);
    if (m_pos->getY() < -m_r) m_pos->setY(m_windowsize[1]+m_r);
    if (m_pos->getX() > m_windowsize[0]+m_r) m_pos->setX(-m_r);
    if (m_pos->getY() > m_windowsize[1]+m_r) m_pos->setY(-m_r);
}
