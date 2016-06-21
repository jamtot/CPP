#ifndef EXPLOSIONFACTORY_H
#define EXPLOSIONFACTORY_H

#include <SFML/Graphics.hpp>
#include "Explosion.h"
using namespace std;

class ExplosionFactory
{
    public:
        ExplosionFactory();
        virtual ~ExplosionFactory();
        static ExplosionFactory * getInstance()
        {
            if (m_instance == 0)
            {//if the instance is null, initialise it
                m_instance = new ExplosionFactory();
            }
            return m_instance;
        }
        void Clear();
        void makeBoom(sf::Vector2f pos);
        void SetWindow(sf::RenderWindow* window);
        void draw();
        void update();
    protected:
    private:
        static ExplosionFactory * m_instance;
        vector<Explosion*> m_explosions;
        vector<Explosion*>::iterator m_iterator;
        sf::RenderWindow * m_window;
};

#endif // EXPLOSIONFACTORY_H
