cmake_minimum_required(VERSION 3.9)
project(final_project_susielau)

set(CMAKE_CXX_STANDARD 11)

add_executable(final_project_susielau
        addons/ofxMoodMachine/example-moodmachine/src/ofApp.cpp
        addons/ofxMoodMachine/src/ofxMoodMachine.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/A/Headers/copy.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/A/Headers/extrude.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/A/Headers/glsmap.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/A/Headers/glsmapint.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/A/Headers/glut.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/A/Headers/glutbitmap.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/A/Headers/glutf90.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/A/Headers/glutstroke.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/A/Headers/gutil.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/A/Headers/intersect.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/A/Headers/port.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/A/Headers/rot.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/A/Headers/segment.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/A/Headers/tube.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/A/Headers/tube_gc.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/A/Headers/vvector.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/Current/Headers/copy.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/Current/Headers/extrude.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/Current/Headers/glsmap.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/Current/Headers/glsmapint.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/Current/Headers/glut.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/Current/Headers/glutbitmap.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/Current/Headers/glutf90.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/Current/Headers/glutstroke.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/Current/Headers/gutil.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/Current/Headers/intersect.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/Current/Headers/port.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/Current/Headers/rot.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/Current/Headers/segment.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/Current/Headers/tube.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/Current/Headers/tube_gc.h
        bin/final-project-susielauDebug.app/Contents/Frameworks/GLUT.framework/Versions/Current/Headers/vvector.h
        src/Board.cpp
        src/Board.h
        src/main.cpp
        src/ofApp.cpp
        src/ofApp.h)
