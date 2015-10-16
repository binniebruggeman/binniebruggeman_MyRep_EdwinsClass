#include "Ball.h"

Ball::Ball() {
}

void Ball::setup() {
    // give some random positioning
    x = ofRandom(0, ofGetWidth());
    y = ofRandom(0, ofGetHeight());
    
    // and random speed
    speedX = ofRandom(-10, 10);
    speedY = ofRandom(-10, 10);
    
    radius = 20;
    
    // set random RGB color
    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
}


void Ball::update() {
    if(x < 0 ) {
        x = 0;
        speedX = -speedX;
    } else if(x > ofGetWidth()) {
        x = ofGetWidth();
        speedX *= -speedY;
    }
    
    if(y < 0 ) {
        y = 0;
        speedY = -speedY;
    } else if(y > ofGetHeight()) {
        y = ofGetHeight();
        speedY = -speedY;
    }
    
    x+=speedX;
    y+=speedY;
}

void Ball::draw() {
    ofSetColor(color);
    ofCircle(x, y, radius);
}