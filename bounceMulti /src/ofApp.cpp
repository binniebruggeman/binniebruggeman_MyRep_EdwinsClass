#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
    for (int i=0; i<50; i++) {
        
        Ball newBall;
        newBall.setup();
        balls.push_back(newBall);
        
        Rectangle newRectangle;
        newRectangle.setup();
        rectangles.push_back(newRectangle);
        
        Triangle newTriangle;
        newTriangle.setup();
        triangles.push_back(newTriangle);

    }
    
//    for (int i=0; i<50; i++) {
//        Rectangle newRectangle;
//        newRectangle.setup();
//        rectangles.push_back(newRectangle);
//    }
//    
//    for (int i=0; i<50; i++) {
//        Triangle newTriangle;
//        newTriangle.setup();
//        triangles.push_back(newTriangle);
//    }
}

//--------------------------------------------------------------
void ofApp::update() {
    for (int i=0; i<balls.size(); i++) {
        balls[i].update();
    }
    
    for (int i=0; i<rectangles.size(); i++) {
        rectangles[i].update();
    }
    
    for (int i=0; i<triangles.size(); i++) {
        triangles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    for (int i=0; i<balls.size(); i++) {
        balls[i].draw();
    }
    
    for (int i=0; i<rectangles.size(); i++) {
        rectangles[i].draw();
    }
    
    for (int i=0; i<triangles.size(); i++) {
        triangles[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
    
}