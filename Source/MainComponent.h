#pragma once

#include <JuceHeader.h>
#include "openGLComponent.h"
#include "mResizerBar.h"

class DummyComp : public Component
{
public:
    DummyComp() {};
    ~DummyComp() override {};
    
    void paint(Graphics& g) override{
        g.fillAll(Colours::white);
        
        for (int i = 0 ; i < 5000; i++){       // simulating a busy UI
            g.setColour(Colours::red);
            g.drawText("SIMULATE UI", 0, 0, getWidth(), getRight(), Justification::left);
        }
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
    DummyComp component, dumComponent;
    openGLComponent opengl;
    StretchableLayoutManager myLayout;
    StretchableLayoutResizerBar resizerBar { &myLayout, 1, true };
    //mResizerBar otherResizerBar { &dumComponent };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
