#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  ofSetVerticalSync(true);
  ofSetWindowShape(1080, 720);
  ofSetFrameRate(60);
  ofSetBackgroundColor(255);
  ofSetColor(0);
  angle = PI / 4;
  aVelocity = 0.0;
  aAcceleration = 10;
  length = 250;
  damping = 0.98;
  mass = 200;
  gravity = 9.8;
  key_hit = false;
  delta = 1;
  center = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
  clearButton.addListener(this, &ofApp::clearButtonPressed);
  gui.setup();
  gui.add(clearButton.setup("clear"));
  gui.add(forceSlider.setup("force", 1, -10, 10));
}

//--------------------------------------------------------------
void ofApp::update()
{

  aAcceleration = (-1 * gravity / length) * sin(angle) + forceSlider / mass;
  aVelocity += aAcceleration;
  aVelocity *= damping;
  angle += aVelocity;
  delta++;
  if (delta > ofGetWidth())
  {
    delta = 0;
  }
  // forceSlider = 0;
}

//--------------------------------------------------------------
void ofApp::draw()
{

  gui.draw();

  ofSetColor(0);
  ofPushMatrix();
  ofSetLineWidth(5);
  ofTranslate(ofGetWidth() / 2, 20);
  ofDrawLine(0, 0, length * sin(angle), length * cos(angle));
  ofDrawLine(-20, 0, 20, 0);
  ofCircle(length * sin(angle), length * cos(angle), 20);
  points.push_back(ofVec2f(length * sin(angle), length * cos(angle)));
  ofSetLineWidth(4);
  ofBeginShape();
  ofNoFill();
  ofDrawGrid(100);
  // ofDrawAxis(100);
  for (ofVec2f p : points)
  {
    ofVertex(p);
  }
  ofEndShape();

  ofPopMatrix();

  ofTranslate(ofPoint(10, ofGetHeight() / 2 + 100));
  ofBeginShape();
  int k = 0;
  for (int i = 0; i < points.size(); i += 1)
  {
    ofVertex(k, (points[i].x));
    if (k > ofGetWidth())
    {
      k = 0;
      points.clear();
    }
    k++;
  }
  ofEndShape();
  ofFill();
}

void ofApp::clearButtonPressed(){
        // k = 0;
      points.clear();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
  // force = forceSlider;
  // key_hit = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
  key_hit = false;
  force = 0.0;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
  forceSlider = 0;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

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
