#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    grabber.listDevices(); //als je meerdere camera's hebt kun je uitvinden welke welke is en wat voor resolutaie en beeldformaat ze aankunnen
    
    grabber.setDeviceID(0); //welke videograb device wil je hebben
    grabber.setDesiredFrameRate(30);    //aantal frames per seconden
    grabber.initGrabber(320,240);       //resolutie
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    grabber.draw(0,0);
    
    ofTranslate(100,100);
    ofRotateX(20);
    grabber.draw(0,0);
}

