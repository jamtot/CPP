#include "Grid.hpp"
#include <iostream>

Grid::Grid(float width, float height, float xSize, float ySize) {
    _width = width;
    _height = height;
    _x = xSize;
    _y = ySize;
    isAlive = true;
}

Grid::~Grid() {

}

void Grid::draw() {
    glColor3f(1.f, 1.f, 1.f);
    glBegin(GL_LINES);
    float xGap = ((_width / _x) / _width) * 2.f;
    for (float i = 1.f; i <= _x; i+=1.f){
        float newGap = -1.f + (xGap * i);
        glVertex2f(newGap, -1.f);
        glVertex2f(newGap, 1.f);
    }
    float yGap = ((_height / _y) / _height) * 2.f;
    for (float i = 1.f; i <= _y; i+=1.f){
        float newGap = -1.f + (yGap * i);
        glBegin(GL_LINES);
        glVertex2f(-1.f, newGap);
        glVertex2f(1.f, newGap);
    }
    glEnd();
}