#include "Ship.h"

Ship::Ship(float x, float y, float width, float length, sf::RenderWindow* window, int* windowsize)
{
    m_pos = new sf::Vector2f(x,y);
    m_acceleration = new sf::Vector2f(0.f, 1.f);
    m_velocity = new sf::Vector2f(0.f, 0.f);
    m_rotation = 0.f;
    m_rotation_speed = 5.f;
    m_max_speed = 5.f;
    m_width = width;
    m_length = length;
    m_window = window;
    m_windowsize = windowsize;
    m_shape = new sf::ConvexShape(4);
    m_shape->setPoint(0, sf::Vector2f(0,0));
    m_shape->setPoint(1, sf::Vector2f(-(m_width/2),(-m_length/2)));
    m_shape->setPoint(2, sf::Vector2f(0,(m_length/2)));
    m_shape->setPoint(3, sf::Vector2f((m_width/2),(-m_length/2)));
    m_shape->setFillColor(sf::Color(0,255,255));
    m_shape->setPosition(*m_pos);

    m_bullet_vec = new vector<Bullet>;
    m_firing = false;
    m_shoot_time = 50; // delay timer for shots if held down
    m_timer = 0;
}

Ship::~Ship()
{
    //dtor
}

void Ship::draw()
{
    m_window->draw(*m_shape);

    vector<Bullet>::iterator it;
    for (it = m_bullet_vec->begin(); it != m_bullet_vec->end(); ++it)
    {
        (*it).draw();
    }
}

void Ship::fire_bullet(sf::Vector2f dir)
{
    float len = sqrt((dir.x * dir.x) + (dir.y * dir.y));
    dir.x = dir.x/len;
    dir.y = dir.y/len;
    m_bullet_vec->push_back( Bullet(*m_pos, dir, 10.f, 2.f, m_window, m_windowsize) );
}

void Ship::update(){

    sf::Vector2f accel(0,0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_rotation-=m_rotation_speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_rotation+=m_rotation_speed;
    }

        m_shape->setRotation(m_rotation);
        float theta = DEGREES_TO_RADIANS(m_rotation);
        float cs = cos(theta);
        float sn = sin(theta);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        sf::Vector2f thrust = *m_acceleration;
        accel+=thrust;
        // rotate the vector
        sf::Vector2f newAccel;
        newAccel.x = accel.x * cs - accel.y * sn;
        newAccel.y = accel.x * sn + accel.y * cs;
        *m_velocity+=newAccel;

        if (Funcs::GetVecLen(*m_velocity) > m_max_speed)
            *m_velocity=Funcs::Normalise(*m_velocity)*m_max_speed;
    }
    else
    {
        if (Funcs::GetVecLen(*m_velocity) > 0.01f)
        {
            //slow by using reverse vector
            sf::Vector2f negVel = *m_velocity * 0.05f;
            *m_velocity = *m_velocity - negVel;
        }
        else
        {
            *m_velocity=sf::Vector2f(0.f,0.f);
        }
    }




    //bounds checking
    if (m_pos->x > m_windowsize[0] - m_length/2) m_pos->x = (m_windowsize[0] - m_length/2);
    else if (m_pos->x < m_length/2) m_pos->x = m_length/2;
    if (m_pos->y > m_windowsize[1] - m_length/2) m_pos->y = (m_windowsize[1] - m_length/2);
    else if (m_pos->y < m_length/2) m_pos->y = m_length/2;

    //set position
    *m_pos+=*m_velocity;
    m_shape->setPosition(*m_pos);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !m_firing)
    { // if the mouse is clicked, use mouse position for shot
        sf::Vector2f position = (sf::Vector2f)sf::Mouse::getPosition(*m_window);
        position-=*m_pos;
        fire_bullet(position);
        m_firing = true;
        m_timer = m_shoot_time;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !m_firing)
    { // if space is pressed, use ship direction for shot
        sf::Vector2f dir(0,1);
        sf::Vector2f rotdir;
        rotdir.x = dir.x * cs - dir.y * sn;
        rotdir.y = dir.x * sn + dir.y * cs;
        fire_bullet(rotdir);
        m_firing = true;
        m_timer = m_shoot_time;
    }
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        m_firing = false;
    }


    if (m_timer > 0)
    { m_timer--; }
    else if (m_timer == 0)
    {
        m_firing = false;
    }

    vector<Bullet>::iterator it;
    for (it = m_bullet_vec->begin(); it != m_bullet_vec->end(); ++it)
    {
        (*it).update();
    }
}
