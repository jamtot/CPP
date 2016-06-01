#ifndef FUNCS_H
#define FUNCS_H

#include <SFML/Graphics.hpp>


class Funcs
{
    public:
        Funcs() {}
        virtual ~Funcs() {}
        static inline float GetVecLen(sf::Vector2f v)
        {
            return sqrt((v.x * v.x) + (v.y * v.y));
        }
        static inline sf::Vector2f Normalise(sf::Vector2f v)
        {
            float len = GetVecLen(v);
            return sf::Vector2f(v.x/len,v.y/len);
        }

    protected:
    private:
};

#endif // FUNCS_H
