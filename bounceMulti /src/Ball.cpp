#include "Ball.h"

//Ball::Ball(){
//}

void Ball::draw(){
    ofSetColor(color);
    ofCircle(x, y, radius);
}