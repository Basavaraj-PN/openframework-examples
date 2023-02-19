#include "ofApp.h"
#include "of3dPrimitives.h"
#define TAU 6.28318530718
//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetWindowShape(1080, 720);
    ofEnableAntiAliasing();
    ofSetCircleResolution(1000);
    ofSetVerticalSync(true);
    ofSetBackgroundColor(255);
    center = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2, 0);
    // ofEnableDepthTest();
    cam.setDistance(200);
    cam.lookAt(ofVec3f(500, 0, 2000));

    gui.setup();
    gui.add(radiusSlider.setup("radius", 1, 0, 50));
    gui.add(countSlider.setup("turns", 1, 0, 20));
    gui.add(heightSlider.setup("height", 1, 0, 20));
    // gui.setBorderColor(ofColor::purple);
    // gui.setPosition(300,300);
    // gui.setDefaultHeight(50);
    gui.setTextColor(ofColor::black);
    height = 10;
    radius = 50;
    turnCount = 10;
}

//--------------------------------------------------------------
void ofApp::update()
{
    // gui.draw();
    radius = radiusSlider;
    height = heightSlider;
    turnCount = countSlider;
}

//--------------------------------------------------------------
void ofApp::draw()
{

    ofColor blue(0, 0, 255); // create a blue color
    ofColor red(255, 0, 0);  // create a red color

    ofPushMatrix();
    ofTranslate(center);
    ofBackground(150);
    ofSetColor(ofColor::black);
    ofNoFill();
    ofSetLineWidth(4);
    cam.begin();

    ofPoint prev = getSpringPoint(0);
    float DETAIL = 500;
    for (size_t i = 1; i < DETAIL; i++)
    {
        double t = i / (DETAIL - 1);
        ofColor color = red.getLerped(blue, t);
        ofPoint pt = getSpringPoint(t);
        ofSetColor(color); // set the current color
        ofDrawLine(prev, pt);
        prev = pt;
    }
    cam.end();
    ofPopMatrix();
    ofDisableDepthTest();
    gui.draw();
    ofEnableDepthTest();
}

ofPoint ofApp::getSpringPoint(double t)
{
    float angle = t * TAU * turnCount;
    ofPoint xyVec = angleToDir(angle);
    return radius * ofPoint(xyVec.x, xyVec.y, t * height);
}

ofPoint ofApp::angleToDir(double angleRad)
{
    return ofPoint(cos(angleRad), sin(angleRad));
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    if (key == ' ')
    {
        cam.reset(); // reset the camera to its default position and orientation
    }
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