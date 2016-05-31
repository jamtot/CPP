#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet
{
    public:
        Bullet(sf::Vector2f pos, sf::Vector2f dir, float bsize, sf::RenderWindow* window, int* windowsize);
        virtual ~Bullet();
        void draw();
        void update();
    protected:
    private:
        float m_size;
        sf::RenderWindow* m_window;
        sf::CircleShape* m_shape;
        int * m_windowsize;

        sf::Vector2f* m_pos;
        sf::Vector2f* m_dir;
        float m_speed;
};

#endif // BULLET_H
