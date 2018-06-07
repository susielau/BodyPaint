# Body Paint
Body Paint is an interactive game inspired by [Memo Akten](http://www.memo.tv/bodypaint/). The program is responsive of user movements and paint on the screen correspondingly. It will then calculate coverage by user, and a video and screenshot will be saved under the project bin folder. High scores will be recorded in the top ten score column. Have fun painting!



## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.


### Prerequisites
What things you need to install the software and how to install them.
* XCode
* Openframeworks folder
* Project Generator


### Installing
A step by step series of examples that help you get a development environment running.
1. Search for ofxInkSim, ofxCv, ofxVideoRecorder online.
2. Download the version from branch stable if given a choice. Put them into the addons folder of openframeworks, and delete "-master" from their names.
3. Click on Clone or download in this repository, and download zip into the of_v0.9.8_osx_release/apps/myApps folder.
4. Use Project Generator to regenerate xcodeproj file.
5. Click on final-project-susielau.xcodeproj, and it will be opened in XCode.
6. Make sure to select final-project-susielau Debug mode, and click build. When build is finished, the Body Paint will start working!

## Running the tests
Explain how to run the automated tests for this system.
### Switch to testing branch
1. Download the zip file and open it in openframeworks.
2. Remember to select testing mode (instead of final-project-susielau Debug/Release).
3. Click Run and wait until the console shows up the number of tests passed.


## Built With
* Openframeworks - open source C++ toolkit for creative coding
    * Libraries:
        * ofxOpenCv
        * ofxCv
        * ofxInkSim
        * ofxVideoRecorder
        * ofxMoodMachine
        * ofxGui


## Author
* Yutong Liu - @susielau

## Acknowledgements
* Memo Akten for inspiration
* Code review peers and moderator for amazing suggestions on improvements

