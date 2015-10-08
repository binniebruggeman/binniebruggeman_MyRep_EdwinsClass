#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    // kies random start coordinaten
    x = ofRandom(0, ofGetWidth());
    y = ofRandom(0, ofGetHeight());
    
    // kies random start coordinaten 2e cirkel
    x_cirkel2 = ofRandom(0, ofGetWidth());
    y_cirkel2 = ofRandom(0, ofGetHeight());
    
    
    // random snelheid
    speedX = ofRandom(-10, 10);
    speedY = ofRandom(-10, 10);
    
    // random snelheid 2e cirkel
    speedX_cirkel2 = ofRandom(-20, 20);
    speedY_cirkel2 = ofRandom(-20, 20);
    
    // grootte van cirkel
    radius = 40;
    
    // grootte van 2e cirkel
    radius_cirkel2 = 80;

    
    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
}

//--------------------------------------------------------------
void ofApp::update() {
    
    // links/ rechts tegen de rand aan? keer om!
    if(x < 0 ) {
        x = 0;
        speedX = -speedX;
    } else if(x > ofGetWidth()) {
        x = ofGetWidth();
        speedX = -speedX;
    }
    
    // boven/onder tegen de rand aan? keer om!
    if(y < 0 ) {
        y = 0;
        speedY = -speedY;
    } else if(y > ofGetHeight()) {
        y = ofGetHeight();
        speedY = -speedY;
    }
    
    // bereken nieuwe coordinaten
    x+=speedX;
    y+=speedY;
    
    // Cirkel 2 links/ rechts tegen de rand aan? keer om!
    if(x_cirkel2 < 0 ) {
        x_cirkel2 = 0;
        speedX_cirkel2 = -speedX_cirkel2;
    } else if(x_cirkel2 > ofGetWidth()) {
        x_cirkel2 = ofGetWidth();
        speedX_cirkel2 = -speedX_cirkel2;
    }
    
    // Cirkel 2 boven/onder tegen de rand aan? keer om!
    if(y_cirkel2 < 0 ) {
        y_cirkel2 = 0;
        speedY_cirkel2 = -speedY_cirkel2;
    } else if(y_cirkel2 > ofGetHeight()) {
        y_cirkel2 = ofGetHeight();
        speedY_cirkel2 = -speedY_cirkel2;
    }
    
    // Cirkel 2 bereken nieuwe coordinaten
    x_cirkel2+=speedX_cirkel2;
    y_cirkel2+=speedY_cirkel2;
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(color);
    ofCircle(x, y, radius);
    ofCircle(x_cirkel2, y_cirkel2, radius_cirkel2);
    
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

