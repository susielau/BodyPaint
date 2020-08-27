#include "Board.h"

void Board::SetUp(ofPtr<UniformInfos> uniforms) {
    this->uniforms = uniforms;
    
    gui.setDefaultWidth(ofGetWidth() - 20);
    gui.setup(uniforms->parameters, "settings/uniforms.xml");
    gui.loadFromFile("settings/uniforms.xml");
}

void Board::ResetToDefault() {
    uniforms->resetToSystemDefault();
}



