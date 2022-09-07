#pragma once

#include <JuceHeader.h>
#include "openGLComponent.h"

class DummyComp : public Component
{
public:
    DummyComp() {};
    ~DummyComp() override {};
    
    void paint(Graphics& g) override{
        g.fillAll(Colours::white);
    }
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DummyComp)
};

//==============================================================================
//==============================================================================

class MainComponent  : public juce::Component
                      
{
public:

    MainComponent();
    ~MainComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

   
private:
    ConcertinaPanel concertinaR;
    DummyComp component;
    openGLComponent opengl;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
