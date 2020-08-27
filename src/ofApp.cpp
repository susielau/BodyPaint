#include "ofApp.h"
#include "ofxInkSim.h"
#include "ofxOpenCv.h"

using namespace ofxCv;
using namespace cv;

int secret_num;
int count_down;
int score = 0;
ofColor white(100,100,100);
const int kRange = 4;
const int kCountDown = 30;
const int kRank = 10;

void ofApp::setup() {
    ofSetWindowTitle("Body Paint");
    gamescreen_.load("screenshot.png");
    
    //font setup
    font_.load("HastagirlDemo.ttf", 100);
    header_font_.load("SurfingCapital.ttf", 30);
    result_font_.load("HastagirlDemo.ttf", 100);
    ofSetColor(0,0,0);
    
    ofDisableAntiAliasing();
    ofBackgroundHex(0xfdefc2);
    ofSetLogLevel(OF_LOG_NOTICE);
    ofSetVerticalSync(true);
    
    //ofxInkSim library setup
    ink_sim_.setup();
    board_.SetUp(ink_sim_.getUniformInfo());
    mood_machine_.setSpeed(1.0);
    ink_sim_.setDrawMode(ofxInkSim::INKFIX);
    
    //ofxcv library setup
    cam.setup(640, 480);
    contour_finder.setMinAreaRadius(10);
    contour_finder.setMaxAreaRadius(150);
    //contourFinder.setInvert(true); // find black instead of white
    
    //video recording setup
    ofSetFrameRate(60);
    ofSetLogLevel(OF_LOG_VERBOSE);
    cam.setDesiredFrameRate(30);
    cam.initGrabber(640, 480);
    
    vidRecorder_.setVideoCodec("mpeg4");
    vidRecorder_.setVideoBitrate("800k");
    vidRecorder_.setAudioCodec("mp3");
    vidRecorder_.setAudioBitrate("192k");
    
    fileName_ = "testMovie";
    fileExt_ = ".mov";
    bRecording_ = false;
    ofEnableAlphaBlending();
    
    //sound setup
    romance_.load("lalaland.mp3");
    romance_.play();
    romance_.setPaused(true);
    
    dark_.load("vengeance.mp3");
    dark_.play();
    dark_.setPaused(true);
    
    anime_.load("anime.mp3");
    anime_.play();
    anime_.setPaused(true);
    
    movie_.load("LostStars.mp3");
    movie_.play();
    movie_.setPaused(true);
}

void ofApp::update() {
    cam.update();
    ink_sim_.update();

    if(cam.isFrameNew() && bRecording_) {
        bool success = vidRecorder_.addFrame(cam.getPixels());
        if (!success) {
            ofLogWarning("This frame was not added!");
        }
        
        contour_finder.setTargetColor(target_color, trackHs ? TRACK_COLOR_HS : TRACK_COLOR_RGB);
        contour_finder.setThreshold(threshold);
        contour_finder.setFindHoles(holes);
        contour_finder.findContours(cam);
    }
    
    if (vidRecorder_.hasVideoError()) {
        ofLogWarning("The video recorder failed to write some frames!");
    }
}

void ofApp::draw() {
    
    if (current_state_ == DISPLAY) {
        DrawMenu();

    } else if (current_state_ == SCORE) {
        DrawTopTen();
        
    } else if (current_state_ == FINISHED) {
        gamescreen_.load("screenshot.png");
        gamescreen_.draw(0, 0, ofGetWidth(), ofGetHeight());
        ofDrawBitmapStringHighlight("Time is up!", 80, 250);
        
        score = CalculateScore();
        ofDrawBitmapStringHighlight("Coverage: " + to_string(score) + "%", 80, 300);
        
        if (should_update_) {
            score_vector_.push_back(score);
        }
        should_update_ = false;
        
        bRecording_ = false;
        vidRecorder_.close();
        StopMusic();
        
    } else if (current_state_ == IN_PROGRESS) {
        ofSetColor(255);
        glPushMatrix();
        glTranslated(640, 0, 0.0f);
        glScalef(-1, 1, 0);
        ink_sim_.draw();
        glPopMatrix();
        
        ofNoFill();
        int n = contour_finder.size();
        ofColor c = mood_machine_;
        
        switch (secret_num) {
            case 1:
                romance_.setPaused(false);
                break;
            case 2:
                dark_.setPaused(false);
                break;
            case 3:
                anime_.setPaused(false);
                break;
            case 4:
                movie_.setPaused(false);
                break;
            default:
                break;
        }
        
        for (int i = 0; i < n; ++i) {
            cv::Point2f point = contour_finder.getCenter(i);
            ink_sim_.stroke(&brush_, point.x, point.y, getInkColor(c.getHueAngle(), 255, 10));
        }
        CountDown();
        ink_sim_.stopStroke(&brush_);
        should_update_ = true;
    }
}

void ofApp::keyPressed(int key) {
    
    int upper_key = toupper(key);

    if (current_state_ == DISPLAY) {
        
        switch (upper_key) {
            case 'S':
                current_state_ = IN_PROGRESS;
                count_down = ofGetElapsedTimef();
                Reset();
                
                bRecording_ = !bRecording_;
                if(bRecording_ && !vidRecorder_.isInitialized()) {
                    vidRecorder_.setup(fileName_+ofGetTimestampString()+fileExt_, cam.getWidth(), cam.getHeight(), 30);
                    
                    //start recording
                    vidRecorder_.start();
                }
                break;
            case 'A':
                current_state_ = SCORE;
                break;
            default:
                break;
        }
        secret_num = GenerateRandomNumber(kRange);
        
    } else if (current_state_ == IN_PROGRESS) {
        
        switch (upper_key) {
            case 'R':
                Reset();
                break;
            case 'M':
                current_state_ = DISPLAY;
                StopMusic();
                break;
            default:
                break;
        }
    } else if (current_state_ == FINISHED) {
        
        switch (upper_key) {
            case 'M':
                current_state_ = DISPLAY;
                break;
            default:
                break;
        }
    } else if (current_state_ == SCORE) {
        
        switch (upper_key) {
            case 'M':
                current_state_ = DISPLAY;
                break;
            default:
                break;
        }
    }
}

int ofApp::CalculateNumWhitePixel(ofImage gamescreen) {
    unsigned char * pixels = gamescreen.getPixels().getData();
    int white_pixel = 0;
    int width = gamescreen.getWidth();
    int height = gamescreen.getHeight();
    int total_pixel = (int) gamescreen.getWidth() * gamescreen.getHeight();
    
    for(int i = 0; i < width; i++){
        for (int j = 0; j < height; j++) {
            float cRed = pixels[(j * width + i) * 3 + 0];
            float cGreen = pixels[(j*width + i) * 3 + 1];
            float cBlue = pixels[(j * width + i) * 3 + 2];
            if (cRed == 255 && cGreen == 255 && cBlue == 255){
                    white_pixel ++;
            }
        }
    }
    return white_pixel;
}

int ofApp::CalculateScore() {
    int total_pixel = gamescreen_.getWidth() * gamescreen_.getHeight();
    int white_pixel = CalculateNumWhitePixel(gamescreen_);
    return 100*(total_pixel - white_pixel) / total_pixel;
}

void ofApp::Reset() {
    ink_sim_.clear();
    board_.ResetToDefault();
    
    romance_.play();
    romance_.setPaused(true);
    dark_.play();
    dark_.setPaused(true);
    anime_.play();
    anime_.setPaused(true);
    movie_.play();
    movie_.setPaused(true);
    
    current_state_ = IN_PROGRESS;
}

void ofApp::DrawMenu() {
    ofSetBackgroundColor(139, 71, 93);
    string title = "body paint";
    string option = "S. Start";
    string option_one = "A. Ranking";
    
    ofSetColor(0,0,0);
    font_.drawString(title, 60, 150);
    
    ofSetColor(250,250,250);
    header_font_.drawString(option, 60, 350);
    header_font_.drawString(option_one, 60, 300);
}

void ofApp::DrawTopTen() {
    string top_ten_message = "Top Ten Scores:";
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(top_ten_message, ofGetWindowWidth() / 4, ofGetWindowHeight() / 4);
    
    std::vector<int> top_ten = SortTopTen();
    if (top_ten.size() == 0) {
        string warning_message = "No Scores Available";
        ofSetColor(0, 0, 0);
        ofDrawBitmapString(warning_message, ofGetWindowWidth() / 4, ofGetWindowHeight() / 4 + 20);
        
    } else {
        
        for (int i = 1; i <= top_ten.size(); i++) {
            string rank = to_string(i) + ": " + to_string(top_ten.at(i-1));
            ofSetColor(0, 0, 0);
            ofDrawBitmapString(rank, ofGetWindowWidth() / 4, ofGetWindowHeight()/ 4 + 20 * i);
        }
    }
}

std::vector<int> ofApp::SortTopTen() {
    std::vector<int> top_ten;
    
    if (score_vector_.size() == 0) {
        return top_ten;
        
    } else if (score_vector_.size() > 0 && score_vector_.size() < kRank) {
        std::sort(score_vector_.begin(), score_vector_.end(), std::greater<int>());
        
        for (int i = 0; i < score_vector_.size(); ++i) {
            top_ten.push_back(score_vector_.at(i));
        }
    } else {
        std::sort(score_vector_.begin(), score_vector_.end(), std::greater<int>());
        
        for (int i = 0; i < kRank; ++i) {
            top_ten.push_back(score_vector_.at(i));
        }
    }
    return top_ten;
}

int ofApp::GenerateRandomNumber(int num) {
    return (rand() % num) + 1;
}

void ofApp::CountDown() {
    
    int time_elapsed = (int)round(ofGetElapsedTimef() - count_down);
    
    if (time_elapsed <= kCountDown) {
        string remain = to_string(kCountDown - (int)round(ofGetElapsedTimef() - count_down));
        ofSetColor(0, 0, 0);
        ofDrawBitmapString(remain, 60, 100);
        
        if (time_elapsed == kCountDown) {
            ofImage screenshot;
            screenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
            screenshot.save("screenshot.png");
        }

    } else {
        current_state_ = FINISHED;
    }
}

void ofApp::StopMusic() {
    romance_.setPaused(true);
    dark_.setPaused(true);
    anime_.setPaused(true);
    movie_.setPaused(true);
}

