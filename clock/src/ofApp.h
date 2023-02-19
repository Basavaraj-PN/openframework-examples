#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include <boost/date_time.hpp>
class ofApp : public ofBaseApp
{
public:
  void setup();
  void update();
  void draw();

  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
  void drawTick(ofVec2f dir, float length, float thickness);
  ofVec2f angleToDir(float angleRad);
  ofVec2f secondsOrMinutesToDir(float seconds);
  ofVec2f hoursToDir(float hours);
  ofVec2f fractionToClockDir(float t);
  ofVec2f valueToAngle(float value, float valueMax);
  void drawClockHands(ofVec2f dir, float length, float thickness, ofColor color);
  void clockUpdate();
  void smoothButtonClicked();
  ofPoint center;
  float currentSeconds, currentMinutes, currentHours; // current date time modules.
  float seconds;
  double currentInMilliseconds;
  float circleScale; // radius of circle.
  bool smoothSeconds; // smooth second hand.


  ofxFloatSlider secondsHandSlider;
  ofxPanel gui;
  ofxButton smoothClock;
};
