#include "MainComponent.h"

using namespace juce;

MainComponent::MainComponent(){
    setSize(600, 400);
    
    addAndMakeVisible(&concertinaR);
    concertinaR.addPanel(-1, &opengl, false);
    concertinaR.addPanel(-1, &component, false);
    
    concertinaR.setPanelHeaderSize(&opengl, 15);
    concertinaR.setPanelSize(&opengl, 200, false);
    concertinaR.setPanelHeaderSize(&component, 15);
    concertinaR.setPanelSize(&component, 200, false);
}
MainComponent::~MainComponent(){
}
void MainComponent::paint (juce::Graphics& g){
    g.fillAll(Colours::red);
}
void MainComponent::resized(){
    concertinaR.setBounds(0, 0, getWidth(), getHeight());
}

