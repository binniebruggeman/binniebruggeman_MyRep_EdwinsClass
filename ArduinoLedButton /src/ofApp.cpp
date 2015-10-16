//https://books.google.nl/books?id=PNvI6rBrxncC&pg=PA48&lpg=PA48&dq=arduino+openframeworks+button+led&source=bl&ots=FBs8tkek84&sig=ctJfPWh9mLL_D1XUxJQzau6rHSc&hl=nl&sa=X&ved=0CEoQ6AEwBGoVChMIv4vpoMrFyAIVTLoaCh0m_wvo#v=onepage&q=arduino%20openframeworks%20button%20led&f=false
//online tutorial bestudeerd (p. 56 t/m 61) bruikbare code omgezet tot werkende code hieronder

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
    
    // set pin D8 to digital input
    arduino.sendDigitalPinMode(8, ARD_INPUT);
    // set pin D3 to digital output
    arduino.sendDigitalPinMode(3, ARD_OUTPUT);
    
    // set listeners for pin events
    ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::digitalPinChanged(const int& pinNum) {
    // get value with arduino.getDigital(pinNum)
    
    //do not run this code until arduino is operating
    if(isArduinoInitialized){
        pin8 = arduino.getDigital(8); //digital read pin 8
        pin3 = arduino.getDigital(3); //read pin 3 verifying state
    }
    arduino.update(); //get any changes that the arduino might have
    
    if(pin8 == ARD_HIGH){ // if button is pressed
            arduino.sendDigital(3, ARD_HIGH); // this will switch the LED on digital pin 3 on
    }else{
            arduino.sendDigital(3, ARD_LOW); // this will switch the LED on digital pin 3 off
    }
    arduino.update(); //get any changes that the arduino might have
}

void ofApp::analogPinChanged(const int& pinNum) {
    // get value with arduino.getAnalog(pinNum));
}


void ofApp::mousePressed(int x, int y, int button) {
    
}

void ofApp::mouseReleased(int x, int y, int button) {

}