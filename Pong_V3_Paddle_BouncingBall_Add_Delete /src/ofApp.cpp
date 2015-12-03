#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
   
    paddle.setup();
}

//--------------------------------------------------------------
void ofApp::update() {
    for (int i=0; i<balls.size(); i++) {
        balls[i].update();
    }
    
    paddle.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
    for (int i=0; i<balls.size(); i++) {
        balls[i].draw();
    }
    
    paddle.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    if (key == ' '){
        Ball newBall;
        newBall.setup();
        balls.push_back(newBall);
    } else if (key == 'd'){
        balls.erase(balls.begin () );
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {
    paddle.y = mouseY;
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