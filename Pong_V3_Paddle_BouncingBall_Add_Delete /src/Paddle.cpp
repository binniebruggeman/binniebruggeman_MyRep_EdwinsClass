#include "Paddle.h"

Paddle::Paddle(){
}

void Paddle::setup(){
    
    paddleWidth = 20;
    paddleHeight = 100;
    
    x = ofGetWidth() - paddleWidth;
    y = ofGetHeight()/2 - paddleHeight/2;
    
    
    
    color.set(0,0,0); // paddle color
}


void Paddle::update(){
    if(x < 0 ){
        x = 0;
    } else if(x > ofGetWidth()){
        x = ofGetWidth();
    }
    
    if(y < 0 ){
        y = 0;
    } else if(y > ofGetHeight()-paddleHeight){
        y = ofGetHeight()-paddleHeight;
    }
    
}

void Paddle::draw(){
    ofSetColor(color);
    ofRect(x,y,paddleWidth, paddleHeight);
    
}
