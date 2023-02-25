#pragma once

#include "ofMain.h"
#include <map>

class MyLine
{
public:
	void setup(ofVec2f start, ofVec2f end, float duration);
	void update();
	void draw();

private:
	ofVec2f start, end, current;
	float duration, elapsedTime;
	bool bFinishedDrawing;
};
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

	// custom calls
	void drawVector(ofVec2f, ofVec2f, double);
	ofVec2f start;
	ofVec2f end;
	float lerpValue;
	ofImage image;
	ofPoint center, prev, current;

	// vector<std::pair<ofVec2f, ofVec2f>> lines;
	int i = 0;
	ofFbo fbo;
	vector<ofVec2f> points;

	int delay, index;
	MyLine line1, line2;
	MyLine *myLine;

	vector<MyLine> lines;
	// MyLine line1, line2;
};
