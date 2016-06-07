#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    
    ofSetCircleResolution(100);
    
    ofSetFrameRate(60);
    
    radius = 10;
    color.setHsb(0,255,255);
    center.x = ofGetWidth()/2;
    center.y = ofGetHeight()/2;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    rand = ofRandom(-5, 5);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(0, 0, 0);
    
    for (int i = 0; i < 30; i++) {
        ofLine(ofGetWidth() / 30 * i, 0, ofGetWidth() / 30 * i, ofGetHeight());
    }
    for (int i = 0; i < 20; i++) {
        ofLine(0, ofGetHeight() / 20 * i, ofGetWidth(), ofGetHeight() / 20 * i);
    }
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    ofNoFill();
    ofSetColor(color);
    ofCircle(0, 0, radius + rand);
    ofSetLineWidth(2);
    ofFill();
    ofCircle(0, 0, radius/5 + rand);
    
    ofLine(0, 0, mouseX - ofGetWidth()/2, mouseY - ofGetHeight()/2);
    
    ofSetColor(0, 0, 0);
    
    ofLine(-ofGetWidth()/2, mouseY - ofGetHeight()/2, ofGetWidth()/2, mouseY - ofGetHeight()/2);
    ofLine(mouseX - ofGetWidth()/2, -ofGetHeight()/2, mouseX - ofGetWidth()/2, ofGetHeight()/2);
    
    if (detail) {
        ofDrawBitmapString("radius:" + ofToString(radius), mouseX - ofGetWidth()/2, mouseY - ofGetHeight()/2);
        ofDrawBitmapString("deg:" + ofToString(deg), mouseX - ofGetWidth()/2, mouseY + 20 - ofGetHeight()/2);
        
        ofSetColor(0, 0, 0, 100);
        ofFill();
        ofBeginShape();
        for (float i = 0; i < deg; i = i + 0.1) {
            ofVertex(cos(ofDegToRad(i)) * radius,
                     sin(ofDegToRad(i)) * radius * -1);
        }
        ofVertex(0, 0);
        ofEndShape();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' ') {
        detail = !detail;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    x = x - center.x;
    y = center.y - y;
    radius = sqrt(x*x + y*y);
    
    if(asin(y/radius) >= 0) {
        deg = acos(x/radius) * 180 / M_PI;
    }else{
        deg = 360 - acos(x/radius) * 180 / M_PI;
    }
    color.setHueAngle(deg);

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
