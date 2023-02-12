#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetWindowShape(1080, 729);
  cam.setDistance(500);
  cam.lookAt(ofVec3f(0, 0, 0));
  ofEnableAntiAliasing();
  ofSetCircleResolution(200);

  x_center = 0;
  y_center = 0;
  z_center = 0;
  radius = 200;
  ofSetVerticalSync(true);
  for (float theta = 0; theta <= 360; theta += 1) {
    float x = x_center + radius * cos(ofDegToRad(theta));
    float y = y_center + radius * sin(ofDegToRad(theta));
    points.push_back(ofVec3f(x, y, z_center));
    // ofDrawSphere(x, y, z_center, 10);
  }
  points_size = points.size();
  i = 0;
}

//--------------------------------------------------------------
void ofApp::update() {
  i++;
  if (i < points_size) {
    i++;
  } else {
    i = 0;
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  // Clear the window
  ofClear(0);
  cam.begin();
  auto pt = points[i];

  ofDrawSphere(pt, 10);
  ofVec3f tangent = ofVec3f(-pt.y, pt.x, 1);
  ofVec3f normalisedTangent = tangent.getNormalized();
  ofVec3f tangentVector = pt + 100 * normalisedTangent;

  ofVec3f normal = ofVec3f(-pt.x, -pt.y, 1);
  ofVec3f normalisedNormal = normal.getNormalized();
  ofVec3f normalVector = pt + 100 * normalisedNormal;
  ofVec3f biNormal = pt + 100 * normalisedTangent.cross(normalisedNormal);



  ofColor(ofColor::red);
  ofDrawArrow(pt, normalVector, 5);
  ofColor(ofColor::blue);
  ofDrawArrow(pt, tangentVector, 5);
  ofColor(ofColor::green);
  ofDrawArrow(pt, biNormal, 5);


  ofBeginShape();
  ofNoFill();
  for (auto p : points) {
    ofVertex(p);
  }
  ofEndShape();
  cam.end();
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