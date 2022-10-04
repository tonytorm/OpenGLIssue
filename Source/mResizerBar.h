/*
  ==============================================================================

    mResizerBar.h
    Created: 4 Oct 2022 12:38:06pm
    Author:  Giulio Iacomino

  ==============================================================================
*/

#include <JuceHeader.h>

#include "openGLComponent.h"

#include <vector>
#include <string>
//==============================================================================
/*
*/


class mResizerBar : public Component
{
public:
    
    mResizerBar(Component* componentToResize);
    
    void mouseDown (const MouseEvent&) override;
    void mouseDrag (const MouseEvent& e) override;
    void mouseUp (const MouseEvent&) override;
    void hasBeenMoved();
    void paint(Graphics& g) override;
    void setMinMax(int minimum, int maximum);
    void setResizerBarColours(Colour baseColour, Colour HighlightedColour);
    MouseCursor getMouseCursor() override;
    bool shouldBeActive();
    
    bool isBeingDragged = false;
private:
    Component* tBox;
    Rectangle<int> originalBounds;
    Colour baseColour_, highlightColour;
    int minimumWidth = 20;
    int maximumWidth = 500;
    bool useLookAndFeel = true;
    
};
