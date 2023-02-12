#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(10, 10, 10);

    camera.setPosition(ofVec3f(0, 2.f, -10.f));
    camera.lookAt(ofVec3f(0, 0, 0), ofVec3f(0, -1, 0));

    world.setup();
    world.enableGrabbing();
    world.enableDebugDraw();
    world.setCamera(&camera);
    world.setGravity(ofVec3f(0, 0.f, 0));
    sphere = new ofxBulletSphere();
    sphere->create(world.world, ofVec3f(0, 0, 0), 0.1, .25);
    sphere->add();
    ground.create(world.world, ofVec3f(0., 5.5, 0.), 0., 100.f, 1.f, 100.f);
    ground.setProperties(.25, .95);
    ground.add();
}

//--------------------------------------------------------------
void ofApp::update()
{
    world.update();
    ofSetWindowTitle("FPS " + ofToString(ofGetFrameRate(), 0));
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofEnableDepthTest();
    camera.begin();
    ofSetLineWidth(1.f);
    ofSetColor(255, 0, 0);
    world.drawDebug();
    ofSetColor(0,255,255);
    ground.draw();
    ofSetColor(255);
    sphere->draw();
    camera.end();
    btVector3 velocity(1, 0, 0);
    sphere->getRigidBody()->setLinearVelocity(velocity);

    auto t = sphere->getRigidBody()->getLinearVelocity();
    std::cout << t.getX() << std::endl;
    std::cout << t.getY() << std::endl;
    std::cout << t.getZ() << std::endl;
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
