#pragma once

#include "ofMain.h"

#include <iostream>

class ofApp : public ofBaseApp
{
public:
  void setup();
  void update();
  void draw();
  ofPoint center;
  float x, y, m, c, prevY, g, h, dt, dt2;
  std::string text;
  std::vector<ofVec2f> positive_points;
  std::vector<ofVec2f> negative_points;
  ofTrueTypeFont font;
  ofImage image;
  float colorFade;
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
};
