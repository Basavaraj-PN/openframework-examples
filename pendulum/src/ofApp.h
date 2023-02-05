#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include <iostream>

class ofApp : public ofBaseApp
{
public:
  void setup();
  void update();
  void draw();
  float angle;
  float aVelocity;
  double aAcceleration;
  float length;
  float damping;
  float x, y;
  float force;
  bool key_hit;
  std::vector<ofVec2f> points;
  float mass;
  float gravity;
  vector<ofVec2f> positions;
  double curr_time;
  int delta;
  ofPoint center;
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
  void clearButtonPressed();

  ofxFloatSlider forceSlider;
  ofxPanel gui;
  ofxButton clearButton;
};
