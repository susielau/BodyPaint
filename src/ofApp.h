#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"
#include "ofxInkSim.h"
#include "SampleBrush.h"
#include "Board.h"
#include "ofxMoodMachine.h"
#include "ofxVideoRecorder.h"

enum GameState {
    IN_PROGRESS,
    SCORE,
    DISPLAY,
    FINISHED
};

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void DrawMenu();
    void DrawTopTen();
    std::vector<int> SortTopTen();
    void Reset();
    int GenerateRandomNumber(int);
    void CountDown();
    void StopMusic();
    int CalculateNumWhitePixel(ofImage);
    int CalculateScore();
    
    ofVideoGrabber cam;
    ofxCv::ContourFinder contour_finder;
    ofColor target_color;
    
    ofxPanel gui;
    
    // the contour threshold
    ofParameter<float> threshold;
    ofParameter<bool> trackHs;
    ofParameter<bool> holes;
    
    float hull_min_defect_depth = 10;
    
private:
    GameState current_state_ = DISPLAY;
    ofTrueTypeFont font_;
    ofTrueTypeFont header_font_;
    ofTrueTypeFont result_font_;
    
    ofxVideoRecorder vidRecorder_;
    string fileName_;
    string fileExt_;
    bool bRecording_;
    
    ofxInkSim ink_sim_;
    Board board_;
    SampleBrush brush_;
    ofxMoodMachine mood_machine_;

    ofSoundPlayer romance_;
    ofSoundPlayer dark_;
    ofSoundPlayer anime_;
    ofSoundPlayer movie_;
    
    std::vector<int> score_vector_;
    ofImage gamescreen_;
    bool should_update_ = false;
};
