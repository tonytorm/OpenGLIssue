#include "MainComponent.h"

using namespace juce;

MainComponent::MainComponent(){
    setSize(600, 400);
    
    addAndMakeVisible(&dumComponent);
    addAndMakeVisible(&resizerBar);
    addAndMakeVisible(&concertinaR);
    addAndMakeVisible(&otherResizerBar);
    
    
    
    otherResizerBar.setResizerBarColours(Colours::black, Colours::grey);
    
    
    
    myLayout.setItemLayout (0, -0.2, -0.8,  -0.5);
    myLayout.setItemLayout(1, 3, 3, 3);
    myLayout.setItemLayout (2, -0.2, -0.8, -0.5);
    
    dumComponent.setBounds(0, 0, 100, 0);
    
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

//    dumComponent.setBounds(dumComponent.getBounds().withHeight(getHeight()));
//    otherResizerBar.setBounds(dumComponent.getRight(), 0, 5, getHeight());
//    concertinaR.setBounds(otherResizerBar.getRight(), 0, getWidth()-otherResizerBar.getRight(), getHeight());
    
    Component* comps[] = { &dumComponent, &resizerBar, &concertinaR };
    myLayout.layOutComponents (comps, 3, 0, 0, getWidth(), getHeight(), false, true);
    
    
}

