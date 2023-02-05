#include "ofApp.h"
#include <cmath>
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup()
{
  // ofSetWindowShape(1080, 720);
  ofSetFrameRate(60);
  ofSetBackgroundColor(255);
  ofSetColor(0);
  center = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
  ofEnableSmoothing();
  x = y = 0;
  m = 0.5;
  c = 0;
  m = 0;
  dt = -1.0;
  dt2 = 0;
  text = " An equation for me has no meaning \n\n unless it expresses a thought of Love.";
  // ofEnableAntiAliasing();
  font.load("arial.ttf", 30);
  font.setLineHeight(20);
  colorFade = 0;
  image.load("/home/omnipotent/open_framework/apps/myApps/heart/eqution/eqution.png");
}

//--------------------------------------------------------------
void ofApp::update()
{
  dt += 0.01;
  colorFade += 2;
  if (dt >= 1)
  {
    dt = -1;
  }
  if (colorFade >= 255)
  {
    colorFade = 255;
  }
}

//--------------------------------------------------------------
void ofApp::draw()
{
  ofPushMatrix();
  ofTranslate(center);
  ofRotate(-180);
  ofSetColor(255);
  ofSetLineWidth(3);
  ofSetColor(0);
  ofScale(100 * abs(sin(ofGetElapsedTimef())) + 100);
  ofNoFill();
  int k = 1;

  float res = 0.01;
  ofNoFill();
  float time = ofGetElapsedTimef();
  float value = sin(time * M_TWO_PI * 2);
  float v = ofMap(value, -1, 1, 0, 255);
  ofSetColor(v, 0, 0);

  ofBeginShape();
  for (float i = -k; i <= k; i += res)
  {
    x = i;
    y = (4.0 / 5.0) * (std::sqrt(k - x * x) + std::sqrt(std::abs(x)));
    ofVertex(x, y);
  }
  ofEndShape();

  ofBeginShape();
  for (float i = -k; i <= k; i += res)
  {
    x = i;
    y = (4.0 / 5.0) * (-1 * std::sqrt(k - x * x) + std::sqrt(std::abs(x)));
    ofVertex(x, y);
  }

  ofEndShape();

  // ofDrawLine(0, 0, dt, (4.0 / 5.0) * (-std::sqrt(k - dt * dt) + std::sqrt(std::abs(dt))));
  ofNoFill();
  ofDrawGrid(1, 100);

  ofFill();
  ofDrawCircle(-dt, (4.0 / 5.0) * (std::sqrt(k - dt * dt) + std::sqrt(std::abs(dt))), 0.05);
  ofDrawCircle(dt, (4.0 / 5.0) * (-std::sqrt(k - dt * dt) + std::sqrt(std::abs(dt))), 0.05);
  ofSetColor(0, 0, 0);
  // ofDrawBitmapString(text, 0, 0);
  ofPopMatrix();
  ofSetColor(0, 0, 0, colorFade);
  font.drawString(text, 100, 100);
  ofSetColor(255, 255, 255, colorFade);
  // image.resize(300,300);
  image.draw(100, ofGetHeight() / 2 + 200);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
  dt += 0.2;
}

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