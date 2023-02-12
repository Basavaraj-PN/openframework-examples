#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetWindowShape(1080, 720);
    ofSetVerticalSync(true);
    ofEnableAntiAliasing();
    center = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
    velocity = ofVec3f(100, 0, 0);
    position = ofVec3f(center.x, center.y);
    ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update()
{
    deltaTime = ofGetLastFrameTime();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofTranslate(center);
    ofNoFill();
    position =  100 * positionX(deltaTime);
    ofSetColor(255);
    ofCircle(position, 20);
    ofDrawArrow(position, (position + velocity), 5);
    ofLog(OF_LOG_NOTICE, "postion " + ofToString(position));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

    switch (key)
    {
    case ofKey::OF_KEY_LEFT:
        velocity = velocity + ofVec3f(-10, 0, 0);
        break;
    case ofKey::OF_KEY_RIGHT:
        velocity = velocity + ofVec3f(10, 0, 0);
        break;
    case ofKey::OF_KEY_UP:
        velocity = velocity + ofVec3f(0, -10, 0);
        break;
    case ofKey::OF_KEY_DOWN:
        velocity = velocity + ofVec3f(0, 10, 0);
        break;
    default:
        break;
    }
    ofLog(OF_LOG_NOTICE, "Velocity: " + ofToString(velocity));
}

ofVec3f ofApp::positionX(float t)
{
    float s = velocity.x * deltaTime + 0.5F  * deltaTime * deltaTime;
    return ofVec3f(t, 0, 0);
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
    // float t = x - ofGetWidth() / 2;

    // std::cout << x << " " << center.x << std::endl;
    // if (x <= center.x)
    // {
    //     velocity = -1 * velocity;
    // }
    // else
    // {
    //     velocity = velocity;
    // }
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
