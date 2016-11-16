
#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    cam.setup(640, 480);
    contourFinder.setMinAreaRadius(10);
    contourFinder.setMaxAreaRadius(150);
    targetColor.set(255,0,0);
    contourFinder.setTargetColor(targetColor, TRACK_COLOR_RGB);
    //contourFinder.setInvert(true); // find black instead of white
    
    gui.setup();
    gui.add(threshold.set("Threshold", 90, 0, 255));
    gui.add(trackHs.set("Track Hue/Saturation", false));
}

void ofApp::update() {
    cam.update();
    if(cam.isFrameNew()) {
        contourFinder.setTargetColor(targetColor, trackHs ? TRACK_COLOR_HS : TRACK_COLOR_RGB);
        contourFinder.setThreshold(threshold);
        contourFinder.findContours(cam);
    }

}

void ofApp::draw() {
    ofSetColor(255);
    cam.draw(0, 0);
    
    ofSetLineWidth(2);
    contourFinder.draw();
    
    gui.draw();

}

void ofApp::mousePressed(int x, int y, int button) {
    //targetColor = cam.getPixels().getColor(x, y);
}
