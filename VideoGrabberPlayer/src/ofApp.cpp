#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255,255,255);
    ofSetFrameRate(60);
    //ofSetVerticalSunc(true);
    
    camWidth 		= 320;	// try to grab at this size.
    camHeight 		= 240;
    
    video.loadMovie("fingers.mov");
    video.play();
    video.setLoopState(OF_LOOP_NORMAL);
    
    rotate = 0;
    
    grabber.listDevices(); //als je meerdere camera's hebt kun je uitvinden welke welke is en wat voor resolutaie en beeldformaat ze aankunnen
    
    grabber.setDeviceID(0); //welke videograb device wil je hebben
    grabber.setDesiredFrameRate(30);    //aantal frames per seconden
    grabber.initGrabber(camWidth,camHeight);       //resolutie
    
    videoInverted 	= new unsigned char[camWidth*camHeight*3];
    videoTexture.allocate(camWidth,camHeight, GL_RGB);
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    rotate++;
    
    grabber.update();
    if (grabber.isFrameNew()){
        int totalPixels = camWidth*camHeight*3;
        unsigned char * pixels = grabber.getPixels();
        for (int i = 0; i < totalPixels; i++){
            videoInverted[i] = 255 - pixels[i];
        }
        videoTexture.loadData(videoInverted, camWidth,camHeight, GL_RGB);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofSetColor(ofColor::white); //anders wordt het filmpje in het blauw gekleurd vanwege het laatste blauwe filmpje, door wit in te stellen is hij weer standaard
    grabber.draw(20,20);
    videoTexture.draw(20+camWidth,20,camWidth,camHeight);

    
//    ofTranslate(100,100);
//    ofRotateX(20);
//    grabber.draw(0,0);
    
    ofSetColor(ofColor::white); //anders wordt het filmpje in het blauw gekleurd vanwege het laatste blauwe filmpje, door wit in te stellen is hij weer standaard
    video.draw(20,20+camHeight);
    
//    ofSetColor(ofColor::red);
//    
//    ofScale(0.7,0.7,0.7);
//    ofTranslate(400, 200);
//    ofRotateX(rotate);
//    ofRotateY(rotate);
//    video.draw(0,0);
//    
//    ofSetColor(ofColor::green);
//    
//    ofScale(0.7,0.7,0.7);
//    ofTranslate(400, 200);
//    ofRotateX(rotate);
//    ofRotateY(rotate);
//    video.draw(0,0);
//    
//    ofSetColor(ofColor::blue);
//    
//    ofScale(0.7,0.7,0.7);
//    ofTranslate(400, 200);
//    ofRotateX(rotate);
//    ofRotateY(rotate);
//    video.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}