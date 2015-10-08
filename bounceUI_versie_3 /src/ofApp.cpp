#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
    
    parameterGroup.add(ballGroup.ballParameters);
    
    gui.setup("Instellingen", "settings.xml");
    gui.add(radius.setup("count",50,0,200));
    gui.add(speedX.setup("speedX",20,0,200));
    gui.add(speedY.setup("speedY",20,0,200));
    gui.loadFromFile("settings.xml");
}

//--------------------------------------------------------------
void ofApp::update() {
    for (int i=0; i<balls.size(); i++) {
        balls[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    for (int i=0; i<balls.size(); i++) {
        balls[i].draw();
    }
    
    gui.draw();
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
void ofApp::exit() {
    gui.saveToFile("settings.xml");
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