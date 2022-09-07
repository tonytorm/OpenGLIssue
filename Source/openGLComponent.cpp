/*
  ==============================================================================

    openGLComponent.cpp
    Created: 15 Jun 2022 10:05:11pm
    Author:  Marc Specter

  ==============================================================================
*/

#include <JuceHeader.h>
#include "openGLComponent.h"


using namespace juce;
using namespace ::juce::gl;

//==============================================================================
openGLComponent::openGLComponent()
{
    openGLContext.setRenderer (this);
    openGLContext.attachTo (*this);
    
//    openGLContext.setComponentPaintingEnabled(false);
}

openGLComponent::~openGLComponent()
{
    openGLContext.detach();
}

void openGLComponent::newOpenGLContextCreated(){
}
void openGLComponent::openGLContextClosing(){
};

void openGLComponent::renderOpenGL(){
    static int ffff;
    std::cout<<"paint renderOPENGL"<<++ffff<<" \n";

    desktopScale = (float) openGLContext.getRenderingScale();   //needed every frame

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1, 0, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);


    glClearColor(0.0, 0.0, 0.0, 0.5);
    glClear(GL_COLOR_BUFFER_BIT);

    glViewport (0, 0,
                roundToInt (desktopScale * (float)getWidth()),
                roundToInt (desktopScale * (float)getHeight()));

    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);
    glVertex2f(0.0,0.0);

    glColor3f(0,0,1);

    glVertex2f(1,0.0);
    glColor3f(0,1,0);

    glVertex2f(1,1);

    glEnd();
}

