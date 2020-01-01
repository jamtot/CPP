#pragma once
#include <GL/glut.h>  

class Grid {
private:
    float _x;
    float _y;
    float _width; 
    float _height;
    bool isAlive;
public:
    Grid(float width, float height, float xSize = 16.f, float ySize = 16.f);
    ~Grid();
    void draw();

    //getter & setter methods
    bool getIsAlive(){
        return isAlive;
    }
    void setIsAlive(bool alive){
        isAlive = alive;
    }
};