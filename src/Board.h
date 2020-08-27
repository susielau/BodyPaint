#ifndef __emptyExample__GUI__
#define __emptyExample__GUI__

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxInkSim.h"

class Board {
public:
    void SetUp(ofPtr<UniformInfos> uniforms);
    void ResetToDefault();
    
private:
    ofxPanel gui;
    ofXml settings;
    ofPtr<UniformInfos> uniforms;
};

#endif /* defined(__emptyExample__GUI__) */
