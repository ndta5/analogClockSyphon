// https://yoppa.org/iphone10/1284.html
//

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(24);
    //output.setName("clockSyphon");
    
    ofSetWindowTitle("analogClockSyphon");

    //バックグランドを透明色に設定
    ofBackground(64, 0);
    
    dial.load("dial.png");
    hourHand.load("hour.png");
    minutehHand.load("minute.png");
    secondhHand.load("second.png");
    
    // 画像のアンカー位置を中心にする
    dial.setAnchorPercent(0.5, 0.5);
    hourHand.setAnchorPercent(0.5, 0.5);
    minutehHand.setAnchorPercent(0.5, 0.5);
    secondhHand.setAnchorPercent(0.5, 0.5);

    // 縮小後の幅と高さを計算
    dialWidth = dial.getWidth();
    dialHeight = dial.getHeight();
    
    positionX = ofGetWidth()/2;
    positionY = ofGetHeight()/2;
    
    gui.setup();
    gui.add(size.setup("Size", 1, 0.1, 2));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    //時刻を取得
    //秒を取得
    float s = ofGetSeconds();
    //秒の影響を加えた、分の算出
    float m = ofGetMinutes() + (s/60.0);
    //分の影響を加えた、時の算出
    float h = ofGetHours()%12 + (m/60);
    
    //時計の大きさ
    float clockSize = ofGetWidth() / 2 - 20;
    
    //座標全体を中心に移動
    ofPushMatrix();
    ofTranslate(positionX, positionY);
    dial.draw(0, 0, dialWidth * size, dialHeight * size);
    
    ofSetColor(255, 255, 255);
    
    //時針
    ofPushMatrix();
    ofRotateZDeg(h*30.0);
    hourHand.draw(0, 0, dialWidth * size, dialHeight * size);
    ofPopMatrix();

    //分
    ofPushMatrix();
    ofRotateZDeg(m*6.0);
    minutehHand.draw(0, 0, dialWidth * size, dialHeight * size);
    ofPopMatrix();
    
    //秒針
    ofPushMatrix();
    ofRotateZDeg(s*6.0);
    secondhHand.draw(0, 0, dialWidth * size, dialHeight * size);
    ofPopMatrix();

    ofPopMatrix();
    
    output.publishScreen();

    gui.draw();
}

//--------------------------------------------------------------
void ofApp::exit(){

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
    positionX = x;
    positionY = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    positionX = x;
    positionY = y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
