#ifndef _BALL //zelfde als #pragma once, dit is oude methode
#define _BALL //zelfde als #pragma once, dit is oude methode

#include "ofMain.h"

class Ball {
    
public:
    
    Ball();
    
    void setup();
    void update();
    void draw();
    
    // variables
    float x;
    float y;
    float speedY;
    float speedX;
    int radius;
    ofColor color;
    
private:
    
};
#endif //zelfde als #pragma once, dit is oude methode