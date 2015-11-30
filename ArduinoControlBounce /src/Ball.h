#pragma once

#include "ofMain.h"

class Ball {
    
public:
    
    Ball();
    
    void setup();
    void update(ofArduino* arduino);
    void draw();
    void setSpeed(float newSpeed);
    
    // variables
    float x;
    float y;
    float speedY;
    float speedX;
    int radius;
    ofColor color;
    
};