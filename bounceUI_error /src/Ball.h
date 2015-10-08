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
    ofColor color;
    
    //float speedY;
    //float speedX;
    //int radius;
    
    ofParameterGroup ballParameters;
    ofParameter<float> speedX;
    ofParameter<float> speedY;
    ofParameter<int> radius;
    
private:
    
};
#endif //zelfde als #pragma once, dit is oude methode