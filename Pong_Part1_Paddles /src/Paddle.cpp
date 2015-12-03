#include "Paddle.h"

Paddle::Paddle(){
}

void Paddle::setup(){
    
    paddleLeftX = 0;
    paddleLeftY = ofGetHeight()/2;
    paddleRightX = ofGetWidth()-paddleWidth;
    paddleRightY = ofGetHeight()/2;
    
    paddleSpeedY = 10;
    paddleWidth = 30;
    paddleHeight = 75;
    
    color.set(0,0,0); // one way of defining digital color is by adddressing its 3 components individually (Red, Green, Blue) in a value from 0-255. Black is 0,0,0.
    
}


void Paddle::update(){
        
    if(paddleRightY < 0 ){
       paddleRightY = 0;
    } else if(paddleRightY > ofGetHeight()){
        paddleRightY = ofGetHeight();
    }
    
    if(paddleLeftY < 0 ){
        paddleLeftY = 0;
    } else if(paddleLeftY > ofGetHeight()){
        paddleLeftY = ofGetHeight();
    }
    
    //x+=speedX;
    //y+=speedY;
    
}

void Paddle::draw(){
    ofSetColor(color);
    ofRectangle(paddleLeftX, paddleLeftY, paddleWidth, paddleHeight);
    ofRectangle(paddleRightX, paddleRightY, paddleWidth, paddleHeight);
    
}
