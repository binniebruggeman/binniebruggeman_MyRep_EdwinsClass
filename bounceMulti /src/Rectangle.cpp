#include "Rectangle.h"

//Rectangle::Rectangle(){
//}


void Rectangle::draw(){
    ofSetColor(color);
    ofRectangle(x, y, 50, 50);
}
