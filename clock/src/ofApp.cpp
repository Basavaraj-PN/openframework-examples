#include "ofApp.h"

#define TAU 6.28318530718

ofVec2f ofApp::angleToDir(float angleRad)
{
  return ofVec2f(cos(angleRad), sin(angleRad));
}

ofVec2f ofApp::secondsOrMinutesToDir(float secOrMin)
{
  return valueToAngle(secOrMin, 60);
}
ofVec2f ofApp::hoursToDir(float hours)
{
  return valueToAngle(hours, 12);
}
ofVec2f ofApp::valueToAngle(float value, float valueMax)
{
  float t = value / valueMax;
  return fractionToClockDir(t);
}

ofVec2f ofApp::fractionToClockDir(float t)
{
  float angleRad = (t - 0.25f) * TAU; // 12'O clock ,t * TAU - TAU / 4
  return angleToDir(angleRad);
}

void ofApp::drawTick(ofVec2f dir, float length, float thickness)
{
  ofSetLineWidth(thickness);
  ofDrawLine(circleScale * ofPoint(dir), circleScale * ofPoint(dir * (1 - length)));
  ofSetLineWidth(1);
}
void ofApp::drawClockHands(ofVec2f dir, float length, float thickness, ofColor color)
{
  ofSetLineWidth(thickness);
  ofSetColor(color);
  ofDrawLine(ofPoint(0, 0), circleScale * ofPoint(dir) * length);
  ofSetLineWidth(1);
  ofSetColor(255);
}

void ofApp::clockUpdate()
{
  boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();
  boost::posix_time::ptime now_ms = boost::posix_time::microsec_clock::local_time();

  currentSeconds = now.time_of_day().seconds();
  currentInMilliseconds = now_ms.time_of_day().total_milliseconds();
  currentMinutes = now.time_of_day().minutes();
  currentHours = now.time_of_day().hours();
}

void ofApp::smoothButtonClicked()
{
  smoothSeconds = !smoothSeconds;
}
//--------------------------------------------------------------
void ofApp::setup()
{
  ofSetVerticalSync(true);
  ofSetWindowShape(1080, 720);
  ofSetCircleResolution(200);
  center = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
  gui.setup();
  gui.add(secondsHandSlider.setup("secondHandSlider", 0, 0, 60));
  ofSetLineWidth(2);
  circleScale = 250;
  smoothSeconds = true;
  smoothClock.setup("toggle clock type", 175, 30);
  smoothClock.addListener(this, &ofApp::smoothButtonClicked);
}

//--------------------------------------------------------------
void ofApp::update()
{
  clockUpdate();
}

//--------------------------------------------------------------
void ofApp::draw()
{
  // gui.draw();
  smoothClock.draw();
  ofNoFill();
  ofTranslate(center);
  ofFill();
  ofSetColor(ofColor::black);
  ofDrawCircle(0, 0, 10);
  ofNoFill();
  ofSetColor(ofColor::white);
  ofDrawCircle(0, 0, circleScale);

  for (int i = 0; i < 60; i++)
  {
    ofVec2f dir = secondsOrMinutesToDir(i);
    drawTick(dir, 0.08f, 1);
  }
  // ticks (hours)
  for (int i = 0; i < 12; i++)
  {
    ofVec2f dir = hoursToDir(i);
    drawTick(dir, 0.2f, 4);
  }

  seconds = currentSeconds;
  if (smoothSeconds)
  {
    seconds = currentInMilliseconds / 1000;
  }
  // hands
  drawClockHands(secondsOrMinutesToDir(seconds), 0.9f, 2, ofColor::red);
  drawClockHands(secondsOrMinutesToDir(currentMinutes), 0.7f, 3, ofColor::white);
  drawClockHands(hoursToDir(currentHours), 0.5f, 5, ofColor::white);
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