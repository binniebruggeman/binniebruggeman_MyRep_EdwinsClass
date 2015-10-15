#include "ofApp.h"

void ofApp::setup() {
    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
    isArduinoInitialized = false;
    
    arduino.connect("/dev/cu.usbmodemfd131", 57600); // the same device name used in the Arduino IDE
}

void ofApp::update() {
    arduino.update();
}

void ofApp::draw() {
}

void ofApp::setupArduino(const int& version) {
    // remove listener because we don't need it anymore
    ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);
    
    // set flag: Arduino now ready for use
    isArduinoInitialized = true;
    
    
      // !!!!! Got error, so used code below instead !!!!!
//    // print firmware name and version to the console
//    ofLog(OF_LOG_NOTICE,"Arduino found: %s", arduino.getFirmwareName());
//    ofLog(OF_LOG_NOTICE,"Firmata v%s.%s", arduino.getMajorFirmwareVersion(), arduino.getMinorFirmwareVersion());
    
    
    // !!!!! Used this code, because above code gave error !!!!!
    // print firmware name and version to the console
    ofLogNotice() << arduino.getFirmwareName();
    ofLogNotice() << "firmata v" << arduino.getMajorFirmwareVersion() << "." << arduino.getMinorFirmwareVersion();
    
    arduino.sendDigitalPinMode(13, ARD_OUTPUT);
    
    // set listeners for pin events
    ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::digitalPinChanged(const int& pinNum) {
    // get value with arduino.getDigital(pinNum)
}

void ofApp::analogPinChanged(const int& pinNum) {
    // get value with arduino.getAnalog(pinNum));
}


void ofApp::mousePressed(int x, int y, int button) {
    arduino.sendDigital(13, ARD_HIGH); // this will switch the on-board Arduino LED on
}

void ofApp::mouseReleased(int x, int y, int button) {
    arduino.sendDigital(13, ARD_LOW); // this will switch the on-board Arduino LED off
}