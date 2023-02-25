#include "ofApp.h"

void MyLine::setup(ofVec2f start, ofVec2f end, float duration)
{
    this->start = start;
    this->end = end;
    this->duration = duration;
    elapsedTime = 0;
    bFinishedDrawing = false;
}

void MyLine::update()
{
    if (elapsedTime < duration)
    {
        elapsedTime += ofGetLastFrameTime();
        float t = ofClamp(elapsedTime / duration, 0, 1);
        current = start.getInterpolated(end, t);
    }
    else
    {
        current = end;
        bFinishedDrawing = true;
    }
}

void MyLine::draw()
{
    ofSetColor(0, 255, 9);
    ofSetLineWidth(5);
    ofDrawLine(start, current);
}

//--------------------------------------------------------------

void ofApp::drawVector(ofVec2f pt1, ofVec2f pt2, double lerpResolution = 0.08)
{
    ofSetColor(0, 255, 0);
    ofSetLineWidth(2);
    lerpValue += lerpResolution;
    lerpValue = ofClamp(lerpValue, 0.0, 1.0);
    ofVec2f current = pt1.getInterpolated(pt2, lerpValue);
    ofDrawLine(pt1, current);
}

void ofApp::setup()
{
    ofBackground(255);                       // Set background color to white
    ofSetFrameRate(60);                      // Set the frame rate to 60 fps
    ofSetWindowTitle("Slowly Drawing Line"); // Set window title

    // Initialize start and end points
    start.set(100, 100);
    end.set(400, 400);

    // center
    center = ofPoint(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 0);
    image.load("/home/omnipotent/open_framework/apps/myApps/fit_fest/image/car-top-view.png");
    image.resize(100, 100);

    auto p1 = ofVec2f(0, 0);
    auto p2 = ofVec2f(200, 200);
    auto p3 = ofVec2f(0, 200);
    auto p4 = ofVec2f(200, 200);
    // lines.push_back(std::make_pair(p1, p2));
    // lines.push_back(std::make_pair(p1, p3));
    // lines.push_back(std::make_pair(p4, p3));
    // count = 0;
    line1.setup(ofVec2f(0, 0), ofVec2f(100, 100), 2.0);
    line2.setup(ofVec2f(0, 0), ofVec2f(100, -100), 2.0);
}

//--------------------------------------------------------------
void ofApp::update()
{

    line1.update();
    line2.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofTranslate(center);
    image.draw(-image.getWidth() / 2, -image.getHeight() / 2);
    auto x = ofVec2f(0, 0);
    auto y = ofVec2f(300, 300);

    line1.draw();
    line2.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
