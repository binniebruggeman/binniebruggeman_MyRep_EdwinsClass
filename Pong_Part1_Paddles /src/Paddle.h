
#pragma once

#include "ofMain.h"

#define Paddle_h

class Paddle {

public:
    
    Paddle();
    
    void setup();
    void update();
    void draw();
    
    // variables
    float paddleLeftX;
    float paddleLeftY;
    float paddleRightX;
    float paddleRightY;
    float paddleSpeedY;
    int paddleWidth;
    int paddleHeight;
    ofColor color;
    
private:
    
};


