#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    ofSetFrameRate(60);
    //ofSetVerticalSunc(true);
    
    video.loadMovie("fingers.mov");
    video.play();
    video.setLoopState(OF_LOOP_NORMAL);
    
    rotate = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    rotate++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(ofColor::white); //anders wordt het filmpje in het blauw gekleurd vanwege het laatste blauwe filmpje, door wit in te stellen is hij weer standaard
    video.draw(0,0);
    
    ofSetColor(ofColor::red);
    
    ofScale(0.7,0.7,0.7);
    ofTranslate(400, 200);
    ofRotateX(rotate);
    ofRotateY(rotate);
    video.draw(0,0);
    
    ofSetColor(ofColor::green);

    
    ofScale(0.7,0.7,0.7);
    ofTranslate(400, 200);
    ofRotateX(rotate);
    ofRotateY(rotate);
    video.draw(0,0);
    
    ofSetColor(ofColor::blue);
    
    ofScale(0.7,0.7,0.7);
    ofTranslate(400, 200);
    ofRotateX(rotate);
    ofRotateY(rotate);
    video.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

