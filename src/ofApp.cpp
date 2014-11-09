#include "ofApp.h"

Coordinate  coordinates[1000];

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    ofSetFrameRate(10);
    //ofSetBackgroundAuto(false);
    
    ifstream    myFile;
    string      bodyPart;
    double      x, y, z;
    int         i = 0, j = 0, k = 0;
    string      trash;
    
    myFile.open("/Users/hannahsimmons/Desktop/OF_ROOT/apps/myApps/danceFoo3/bin/data/motiveB.txt");
    if (myFile.fail()) {
        cout << "Input file opening failed.\n";
        return 0;
    }
    
    while (!myFile.eof()) {
        myFile >> trash >> bodyPart >> x >> y >> z
        >> trash >> trash >> trash >> trash >> trash
        >> trash >> trash >> trash >> trash >> trash >> trash;
        if (bodyPart == "l_hand") {
            coordinates[i].x = x;
            coordinates[i].y = y;
            coordinates[i].z = z;
            coordinates[i].count = i + 1;
            //cout << i+1 << ": (" << x << ", " << y << ", " << z << ")\n";
            i++;
        }
        else if (bodyPart == "r_hand") {
            coordinates[j].x2 = x;
            coordinates[j].y2 = y;
            coordinates[j].z2 = z;
            coordinates[j].count = j + 1;
            j++;
        }
        else if (bodyPart == "torso") {
            coordinates[k].x3 = x;
            coordinates[k].y3 = y;
            coordinates[k].z3 = z;
            coordinates[k].count = k + 1;
            k++;
            cout << k << ": (" << x << ", " << y << ", " << z << ")\n";
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 1; i < 346; i++) {
        coordinates[i].count++;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    int i=1;
    
    ofSetColor(255, 255, 255);
    ofCircle(coordinates[coordinates[i].count].x +400, coordinates[coordinates[i].count].y +400, coordinates[coordinates[i].count].z/650);
        
    ofSetColor(100,100,100);
    ofLine(coordinates[coordinates[i].count].x +400, coordinates[coordinates[i].count].y +400, coordinates[coordinates[i+1].count].x +400, coordinates[coordinates[i+1].count].y +400);
    
    
    int j=1;
    
    ofSetColor(255,255,255);
    ofCircle(coordinates[coordinates[j].count].x2 +400, coordinates[coordinates[j].count].y2 +400, coordinates[coordinates[j].count].z2/650);
    
    ofSetColor(100,100,100);
    ofLine(coordinates[coordinates[j].count].x2 +400, coordinates[coordinates[j].count].y2 +400, coordinates[coordinates[j+1].count].x2 +400, coordinates[coordinates[j+1].count].y2 +400);
    
    int k=1;
    ofSetColor(255,255,255);
    ofCircle(coordinates[coordinates[k].count].x3 +400, coordinates[coordinates[k].count].y3 +400, coordinates[coordinates[k].count].z3/650);
    
    ofSetColor(100,100,100);
    ofLine(coordinates[coordinates[k].count].x3 +400, coordinates[coordinates[k].count].y3 +400, coordinates[coordinates[k+1].count].x3 +400, coordinates[coordinates[k+1].count].y3 +400);
    
    /*ofSetColor(255,255,255);
    for (int i=1; i < 346; i++) {
        ofCircle(coordinates[coordinates[i].count].x +400, coordinates[coordinates[i].count].y +400, coordinates[coordinates[i].count].z/650);
        ofCircle(coordinates[coordinates[i].count].x2 +400, coordinates[coordinates[i].count].y2 +400, coordinates[coordinates[i].count].z2/650);
        ofCircle(coordinates[coordinates[i].count].x3 +400, coordinates[coordinates[i].count].y3 +400, coordinates[coordinates[i].count].z3/650);
        
        
        if (sqrt(pow(coordinates[coordinates[i].count].x - coordinates[coordinates[i].count].x2, 2) + pow(coordinates[coordinates[i].count].y - coordinates[coordinates[i].count].y2, 2)) < 50) {
            //ofSetColor(100,100,100);
            ofLine(coordinates[coordinates[i].count].x +400, coordinates[coordinates[i].count].y +400, coordinates[coordinates[i].count].x2 +400, coordinates[coordinates[i].count].y2 +400);
        }
        if (sqrt(pow(coordinates[coordinates[i].count].x - coordinates[coordinates[i].count].x3, 2) + pow(coordinates[coordinates[i].count].y - coordinates[coordinates[i].count].y3, 2)) < 50) {
            //ofSetColor(100,100,100);
            ofLine(coordinates[coordinates[i].count].x +400, coordinates[coordinates[i].count].y +400, coordinates[coordinates[i].count].x3 +400, coordinates[coordinates[i].count].y3 +400);
        }
        if (sqrt(pow(coordinates[coordinates[i].count].x3 - coordinates[coordinates[i].count].x2, 2) + pow(coordinates[coordinates[i].count].y3 - coordinates[coordinates[i].count].y2, 2)) < 50) {
            //ofSetColor(100,100,100);
            ofLine(coordinates[coordinates[i].count].x3 +400, coordinates[coordinates[i].count].y3 +400, coordinates[coordinates[i].count].x2 +400, coordinates[coordinates[i].count].y2 +400);
        }
        if (sqrt(pow(coordinates[coordinates[i].count].x2 - coordinates[coordinates[i].count].x2, 2) + pow(coordinates[coordinates[i].count].y2 - coordinates[coordinates[i].count].y2, 2)) < 100) {
            //ofSetColor(100,100,100);
            ofLine(coordinates[coordinates[i].count].x2 +400, coordinates[coordinates[i].count].y2 +400, coordinates[coordinates[i].count].x2 +400, coordinates[coordinates[i].count].y2 +400);
        }
    }*/
    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
