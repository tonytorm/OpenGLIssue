/*
  ==============================================================================

    openGLComponent.h
    Created: 15 Jun 2022 10:05:11pm
    Author:  Marc Specter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
using namespace juce;

class kWaveViewInterface;

//==============================================================================
/*
*/
class openGLComponent  : public juce::Component,  private OpenGLRenderer
{
public:
    openGLComponent();
    ~openGLComponent() override;
    
    void newOpenGLContextCreated() override;
    void renderOpenGL() override;
    void openGLContextClosing() override;

    OpenGLContext openGLContext;
private:
    float desktopScale=1.0;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (openGLComponent)
};
