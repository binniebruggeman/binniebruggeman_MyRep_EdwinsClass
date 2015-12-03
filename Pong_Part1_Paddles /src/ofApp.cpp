#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    for (int i=0; i<MAXPADDLES; i++) {
        paddle[i].setup();
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    for (int i=0; i<MAXPADDLES; i++) {
        paddle[i].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int i=0; i<MAXPADDLES; i++) {
        paddle[i].draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
