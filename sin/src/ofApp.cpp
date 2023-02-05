#include "ofApp.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup()
{
  //   ofSetFrameRate(120);
  center = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
  ofEnableSmoothing();
  x = y = 0;
  deltaTime = 3;
  fbo.allocate(ofGetWidth(), ofGetHeight());
  fbo.begin();
  ofBackground(255, 255, 255);
  fbo.end();
}

//--------------------------------------------------------------
void ofApp::update()
{
  x += deltaTime;
  if (x > ofGetWidth())
  {
    x = 0;
  }
}

//--------------------------------------------------------------
void ofApp::draw()
{

  fbo.begin();
  draw_sin();
  fbo.end();
  fbo.draw(0, 0);
}

void ofApp::draw_sin()
{

  ofBackground(255);
  ofSetColor(0);

  float amplitude = 100;
  float frequency = 0.001;
  float phase = ofGetElapsedTimef();
  float time = phase;
  ofSetLineWidth(10);
  y = amplitude * sin(2 * PI * frequency * x + phase);
  ofSetColor(255, 0, 0);
  ofDrawCircle(x, y + ofGetHeight() / 2, 15);
  x += 1;
  ofSetColor(191, 64, 191);

  ofBeginShape();
  ofNoFill();
  for (int i = 0; i <= ofGetWidth(); i += 1)
  {
    float x = i;
    float y = amplitude * sin(2 * PI * frequency * x + phase);
    ofVertex(x, y + ofGetHeight() / 2);
  }
  ofEndShape();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}