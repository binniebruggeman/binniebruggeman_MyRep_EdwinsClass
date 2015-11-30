#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    
    ofBackground(30,30,30);
    
    drawGrid = false;
    drawLight = false;
    
    planet01.setup("planet 1");
    planetParams.add(planet01.planetParamGroup);
    
    planet02.setup("planet 2");
    planetParams.add(planet02.planetParamGroup);
    
    gui.setup(planetParams);
    
    // plaats een light in de 3d ruimte
    light.setPointLight();
    light.setPosition(200,200,200);
    
    image1.loadImage("bark.jpg");
    image2.loadImage("tripping.jpg");
    
}

void ofApp::update(){
    planet01.update();
    planet02.update();
}

void ofApp::draw(){
    
    light.enable();
    gui.draw();
    light.disable();
    
    // zorg ervoor dat OF rekening houdt met de 'diepte' (z-coord) van alle objecten
    ofEnableDepthTest();
    
    // dit zorgt er voor dat de texture passend gescaled wordt
    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    ofScale(image1.getWidth(),image1.getHeight());
    glMatrixMode(GL_MODELVIEW);
    
    // start de camera
    cam.begin();
    
    light.enable();
    
    // als je een camera gebruikt, hoef je geen translate te doen
    // om het 0-punt naar het midden van 't scherm te verplaatsen
    
    if (drawGrid) ofDrawGrid(200);
    if (drawLight) light.draw();
    
    // 'bind' 't image als een texture - dit maakt de texture ook meteen 'actief'
    // (is trouwens verkort voor image.getTextureRef().bind())
    image1.bind();
    // teken eerste planeet, gebruikmakend van de actieve texture
    planet01.draw();
    // texture weer uitzetten
    image1.unbind();
    
    // dit maakt de texture-schaal-instellingen van boven weer ongedaan
    glMatrixMode(GL_TEXTURE);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    
    // dit zorgt er voor dat de texture passend gescaled wordt
    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    ofScale(image2.getWidth(),image2.getHeight());
    glMatrixMode(GL_MODELVIEW);
    
    // verplaats het 0-punt naar de positie van de 1e planeet...
    ofTranslate(planet01.distance,0);
    // 'bind' 't image als een texture - dit maakt de texture ook meteen 'actief'
    // (is trouwens verkort voor image.getTextureRef().bind())
    image2.bind();
    // ... en teken de tweede planeet
    planet02.draw();
    // texture weer uitzetten
    image2.unbind();
    
    // dit maakt de texture-schaal-instellingen van boven weer ongedaan
    glMatrixMode(GL_TEXTURE);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    
    light.disable();
    
    // eindig het camera blok
    cam.end();
    
    // schakel de diepte-test weer uit
    ofDisableDepthTest();
}

void ofApp::keyPressed(int key) {
    if (key=='g') {
        drawGrid = !drawGrid;
    } else if (key=='l') {
        drawLight = !drawLight;
    }
}