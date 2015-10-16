#pragma once

#include "ofMain.h"
#include "ofEvents.h"

class ofApp : public ofBaseApp {
    
public:
    
    void setup();
    void update();
    void draw();
    
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    ofArduino	arduino;
    bool		isArduinoInitialized;
    
    bool pin3;
    bool pin8;
    
private:
    
    void setupArduino(const int & version);
    void digitalPinChanged(const int & pinNum);
    void analogPinChanged(const int & pinNum);
    
};
