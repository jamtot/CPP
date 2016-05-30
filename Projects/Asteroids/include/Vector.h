#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

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
            angle=angle/360.f*2.f*M_PI;//convert to radians
            m_x = m_x*cos(angle)+m_y*sin(angle);
            m_y = m_x*sin(angle)+m_y*cos(angle);
        }
        float mag()
        {
            return float(sqrt((m_x*m_x)+(m_y*m_y)));
        }
        void normalise()
        {
            m_x = m_x/mag();
            m_y = m_x/mag();
        }
        void byScalar(double scalar){
            m_x*=scalar;
            m_y*=scalar;
        }

        void div(double scalar){
            m_x/=scalar;
            m_y/=scalar;
        }

        void limit(double vlimit){
            normalise();
            byScalar(vlimit);
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

        static float dist(Vector v1, Vector v2){
            return sqrt( ((v1.getX()-v2.getX())*(v1.getX()-v2.getX())) + ((v1.getY()-v2.getY())*(v1.getY()-v2.getY())));}

        static Vector sub(Vector v1, Vector v2){
            return Vector(v1.getX()-v2.getX(), v1.getY()-v2.getY());}

        static float dot(Vector v1, Vector v2){
            return (v1.getX()*v2.getX()) + (v1.getY()*v2.getY());}

        static float det(Vector v1, Vector v2){
            return (v1.getX()*v2.getY()) - (v1.getY()*v2.getX());}

        static float angleBetween(Vector v1, Vector v2){
            return atan2(det(v1,v2), dot(v1,v2));}

        Vector getPos(){return Vector(m_x, m_y);}
        void add(Vector v){m_x+=v.getX();m_y+=v.getY();}
        void sub(Vector v){m_x-=v.getX();m_y-=v.getY();}
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
