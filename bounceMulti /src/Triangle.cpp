#include "Triangle.h"
#include "Base.h"

//Triangle::Triangle(){
//}

void Triangle::draw(){
    ofSetColor(color);
    ofSetCircleResolution(3);
    ofCircle(x,y,radius);
}