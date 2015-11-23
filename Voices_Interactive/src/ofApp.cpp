#include "ofApp.h"

void ofApp::setup() {
    ofSetLogLevel(OF_LOG_VERBOSE);
    //    ofSetLogLevel(OF_LOG_NOTICE);
    //    ofSetLogLevel(OF_LOG_SILENT);
    
    for (int i=0; i<VOICES; i++) {
        voicePaused[i] = true;
        
        ofLogNotice() << "Loading voice " << i << endl;
        voicePlayer[i].loadSound("vox"+ofToString(i+1)+".wav");
        voicePlayer[i].setLoop(true);
        
        //voicePlayer[i].setVolume(1);
        voicePlayer[i].play();
        voicePlayer[i].setPaused(true);
    }
    
    ofSoundSetVolume(0.2);
}

void ofApp::update() {

    
//This piece of code controls the volume, it continuesly goes gradually louder and then softer again
//    float time = ofGetElapsedTimef();       //ofGetElapsedTimef returns the elapsed time since the application started in seconds as a float
//    
//    float x = time*0.1 + 30;
//    for (int i=0; i<VOICES; i++) {
//        float y = i * 0.02;
//        float volume = ofNoise(x,y);        //ofNoise(x,y) calculates a two dimensional Perlin noise value between 0.0...1.0.
//        voicePlayer[i].setVolume(volume);
//    }
    
    //Updates sound engine. This should be called every frame.
    ofSoundUpdate();
}

void ofApp::draw() {
    
    
    // draw the background colors, window devided in 3 equal sized columns:
    float widthDiv = ofGetWidth() / 3.0f;
    ofSetHexColor(0xeeeeee);
    ofRect(0,0,widthDiv,ofGetHeight());
    ofSetHexColor(0xffffff);
    ofRect(widthDiv,0,widthDiv,ofGetHeight());
    ofSetHexColor(0xdddddd);
    ofRect(widthDiv*2,0,widthDiv,ofGetHeight());
    
    //if voice is not played, draw a rectangle
    for (int i=0;i<2;i++) {
        if (!voicePaused[i]) {
            
            // calculate color
            ofSetColor(i*20+128, i*80, i*10+60);
            
            // draw a rectangle for each voice, with the volume as it's length, 5 px high
            ofRect(50, i*30+200, voicePlayer[i].getVolume()*100, 5);
        }
    }
    
    for (int i=2;i<4;i++) {
        if (!voicePaused[i]) {
            
            // calculate color
            ofSetColor(i*20+128, i*80, i*10+60);
            
            // draw a rectangle for each voice, with the volume as it's length, 5 px high
            ofRect(widthDiv+50, i*30+200, voicePlayer[i].getVolume()*100, 5);
        }
    }
    
    for (int i=4;i<VOICES;i++) {
        if (!voicePaused[i]) {
            
            // calculate color
            ofSetColor(i*20+128, i*80, i*10+60);
            
            // draw a rectangle for each voice, with the volume as it's length, 5 px high
            ofRect(widthDiv*2+50, i*30+200, voicePlayer[i].getVolume()*100, 5);
        }
    }
    
}

void ofApp::keyPressed(int key) {
    
    //turn a voice on or off with a key
    if (key=='1') {
        voicePaused[0] = !voicePaused[0];
        voicePlayer[0].setPaused(voicePaused[0]);
    } else if (key=='2') {
        voicePaused[1] = !voicePaused[1];
        voicePlayer[1].setPaused(voicePaused[1]);
    } else if (key=='3') {
        voicePaused[2] = !voicePaused[2];
        voicePlayer[2].setPaused(voicePaused[2]);
    } else if (key=='4') {
        voicePaused[3] = !voicePaused[3];
        voicePlayer[3].setPaused(voicePaused[3]);
    } else if (key=='5') {
        voicePaused[4] = !voicePaused[4];
        voicePlayer[4].setPaused(voicePaused[4]);
    } else if (key=='6') {
        voicePaused[5] = !voicePaused[5];
        voicePlayer[5].setPaused(voicePaused[5]);
    }
    
    if (key>='1' && key <='6') {
        int voice = key-49;
        ofLogNotice() << voice << endl;
        
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    //devide window in 3 equal parts
    float widthStep = ofGetWidth() / 3.0f;
    
    //set volume for voice 1 and 2 by moving the mouse up and down, between the first column of the window
    for (int i=0;i<2;i++) {
        if (x >= 0 && x <= widthStep){
            voicePlayer[i].setVolume(0.2f + ((float)(ofGetHeight() - y) / (float)ofGetHeight())*1.0f);
        }
    }
    
    //set volume for voice 3 and 4 by moving the mouse up and down, between the second column of the window
    for (int i=2;i<4;i++) {
        if (x >= widthStep && x <= widthStep*2){
            voicePlayer[i].setVolume(0.2f + ((float)(ofGetHeight() - y) / (float)ofGetHeight())*1.0f);
        }
    }
    
    //set volume for voice 5 and 6 by moving the mouse up and down, between the third column of the window
    for (int i=4;i<VOICES;i++) {
        if (x >= widthStep*2 && x <=ofGetWidth()){
            voicePlayer[i].setVolume(0.2f + ((float)(ofGetHeight() - y) / (float)ofGetHeight())*1.0f);
        }
    }
    
    
    //set the volume for all voices at once by moving the mouse from right to left
    //    for (int i=0; i<VOICES; i++){
    //        if (x >= 0 && x <= ofGetWidth()){
    //        voicePlayer[i].setVolume(0.2f + ((float)(ofGetWidth() - x) / (float)ofGetWidth())*1.0f);
    //        }
    //    }
    
    }

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    //devide window in 3 equal parts
    float widthStep = ofGetWidth() / 3.0f;
    
    //sets stereo pan left when mouse's x is within 1st column, to centre if within 2nd column and to right if within 3rd
    for (int i=0; i<VOICES; i++){
        if (x < widthStep){
            voicePlayer[i].setPan(-1.0f);
        } else if (x >= widthStep && x < widthStep*2){
            voicePlayer[i].setPan(0.0f);
        } else {
            voicePlayer[i].setPan(1.0f);
        }
    }
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
