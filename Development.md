# Week One



* ### Merging sound with piano tiles game?
```
I tried several ways and cannot figure out how to sync movement of tiles with music — and a plain game without sound is just way too boring. So I came across the idea of an interactive software called "BodyPaint".
```



* ### Tracking movements of user? 
```
After some research I learned that ofxCV (and possibly ofxOpenCV) library can help me achieve this result. But in trying to make use of the library I went through a whole lot of troubles. I reinstalled everything related to OpenFrameworks and eventually the example projects related to movement tracking are working!
```










# Week Two



## Apr 18th
* ### Painting effect realization?
```
With the help of the ofxInkSim library, I get the painting to work.
```



## Apr 19th
* ### Synchronize movements with painting effect?
![corner](/images/corner.png)
Somehow the painting effect keeps showing up at the left upper corner of the window. I need to understand how ContourFinder in opencv works in order to proceed.
Found [this website](http://openframeworks.cc/ofBook/chapters/image_processing_computer_vision.html#acompleteworkflowbackgroundsubtraction) that may be of help in computer vision. Problem solved tracking the painting using contour_finder.getCenter(i).



## Apr 20th
* ### Adding complexity to the project?
```
Sound library comes to my mind when deciding my next step for my final project. A webcam instrument that draws at the same time sounds fun! I will give it a try.
```



## Apr 21st
* ### Flip the mirrored camera?
```
It is against intuition to have the painting in opposite direction from where we are waving hands. Solved with glPushMatrix(), glPopMatrix(), glTranslated(640,0,0), glScalef(-1,1,0) to flip the drawing and contour_finder.
```



## Apr 22nd
* ### Variable names?
```
Fixed variable names that were not following google c++ style guide to make them more uniform. Still trying to figure out the sound part of this project.
```



## Apr 24th
* ### Ableton Live library cannot be connected?
```
The libraries are out of date and can no longer be used, so I decided to create my own piano notes through enum.
```



## Apr 25th
* ### Better looking GUI?
I downloaded a font and it is now in use!
![font](/images/font.png)









# Week Three



## Apr 26th
* ### Video recording of motion/screen?
```
During code review, Kayla suggested me to have a video recording feature. It sounds great! I did some research and found out the library ofxVideoRecorder can help me in recording user motion.
```



## Apr 27th
* ### If statements changed to switch statements



## Apr 28th
* ### Piano notes?
```
I searched online and found piano notes on piazza recorded by another student in CS126.
```



## Apr 29th
* ### Piano notes played at the same time due to lagging?
```
Due to lagging in program, many piano notes were played at the same time instead of consecutively to form a complete song. I tried to come up with a backup plan to handle this situation -- a body paint game that tells you the amount of coverage in a certain amount of time.
```


* ### ofxBox2d not working?
```
I planned on having balls fall down the screen and erase part of the ink. I would try to develop some other features first and then come back to fix it.
```


* ### Pause without switching to another screen?
```
I can achieve pause by switching current_state_ to PAUSE from IN_PROGRESS. But after a search online I found no other way to stop the program with everything on screen staying still.
```



## Apr 30th
* ### Coverage of board by ink?
```
I solved this by taking a screenshot, and do pixel calculation on the picture. It is working well!
```


* ### Background music played at random


* ### Count down timer using ofGetElapsedTimef()



## May 1st
* ### Top ten scores list?
```
draw() in ofApp seemed to be called way too many times, hence the size of the score array kept increasing non-stop. A solution was found using a boolean should_update_ to control the time list is updated.
```


* ### Tests?
Working on them! Problems associated with openframeworks were solved with [this link](http://wucollective.com/?p=561)
First create a target, then add the missing lib to bin folder.



## May 2nd
* ### README.md

* ### Variable names following Google Style Guide?

* ### Algorithm for counting number of white pixels failing?
```
Instead of pixel[i] == 255, I split them up into red, green and blue components. Along with some estimation, the algorithm started working (though not particularly accurate, but much more accurate than the previous one!)
```

