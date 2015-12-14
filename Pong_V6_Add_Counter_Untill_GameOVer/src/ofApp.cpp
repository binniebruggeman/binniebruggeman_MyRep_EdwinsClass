#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
    
    for (int i=0; i<1; i++) {
        Ball newBall;
        newBall.setup();
        balls.push_back(newBall);
    }
    
    paddle.setup();
    
    paddleHit = false;
    wallHit = false;
    gameOver = false;
    
    counter = 0;
}

//--------------------------------------------------------------
void ofApp::update() {
    for (int i=0; i<balls.size(); i++) {
        if(gameOver) return false; //When gameOver it won't do this entire update
        
        balls[i].update();
        
        if ( (balls[i].x+(balls[i].radius/2)) >= paddle.x
            && balls[i].y+(balls[i].radius/2) >= paddle.y
            && balls[i].y <= (paddle.y+paddle.paddleHeight)) {
            paddleHit=true;
        } else {
            paddleHit=false;
        }
        
        //if ball hits right side of screen delete it and create new ball
        if (balls[i].x>=ofGetWidth() && paddleHit!=true) {
            wallHit = true;
            balls.erase(balls.begin () );
            Ball newBall;
            newBall.setup();
            balls.push_back(newBall);
        } else {
            wallHit = false;
        }
        
        //for (int c=0; c<5; c++) {
            if (wallHit==true) {
                counter++;
            }
            
            if (counter>=5) {
                gameOver=true;
                ofBackground(0);
                balls.erase(balls.begin ());
            } else{
                gameOver=false;
            }
        
       
            
        //}
        
        
        
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