#pragma once

#include "ofMain.h"

class Paddle {
    
public:
    
    Paddle();
    
    void setup();
    void update();
    void draw();
    
    // variables
    float x;
    float y;
    int paddleWidth;
    int paddleHeight;
    ofColor color;
    
private:
    
};