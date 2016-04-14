#ifndef VECTOR_H
#define VECTOR_H

#include "math.h"

class Vector
{
    public:
        Vector(float x, float y)
        {
            m_x = x;
            m_y = y;
        }
        virtual ~Vector() {}

        void rotate(float angle)//angle in degrees
        {
            angle=angle/360.f*2.f*3.141592f;//convert to radians
            m_x = m_x*cos(angle)+m_y*sin(angle);
            m_y = m_x*sin(angle)+m_y*cos(angle);
        }
        void normalise()
        {
            float len = sqrt((m_x*m_x)+(m_y*m_y));
            m_x = m_x/len;
            m_y = m_x/len;
        }
        void byScalar(double scalar){
            m_x*=scalar;
            m_y*=scalar;
        }

        Vector operator+(Vector param)
        {
            Vector temp(m_x+param.getX(), m_y+param.getY());
            return (temp);
        }
        Vector operator-(Vector param)
        {
            Vector temp(m_x-param.getX(), m_y-param.getY());
            return (temp);
        }
        Vector operator*(float param)
        {
            Vector temp(m_x*param, m_y*param);
            return (temp);
        }
        void add(Vector v){m_x+=v.getX();m_y+=v.getY();}
        void sub(Vector v){m_x-=v.getX();m_y-=v.getY();}
        Vector getPos(){return Vector(m_x, m_y);}
        float getX(){return m_x;}
        float getY(){return m_y;}
        void setVector(Vector v){m_x=v.getX();m_y=v.getY();}
        void setVector(float x, float y){m_x=x;m_y=y;}
        void origin(){m_x=0.f;m_y=0.f;}
        void translate(Vector v){m_x=v.getX();m_y=v.getY();}
        void translate(float x, float y){m_x=x;m_y=y;}
        void addX(float a){m_x+=a;}
        void addY(float a){m_y+=a;}
        void setX(float x){m_x=x;}
        void setY(float y){m_y=y;}
    protected:
    private:
    float m_x, m_y;
};

#endif // VECTOR_H
