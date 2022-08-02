/*
  ==============================================================================

    MyLookAndFeel.h
    Created: 2 Aug 2022 7:10:52pm
    Author:  haoyu.zhou

  ==============================================================================
*/

#pragma once


#include <JuceHeader.h>
using namespace juce;


class MyLookAndFeel : public LookAndFeel_V4
{
public:
    MyLookAndFeel()
    {
        setColour (AlertWindow::backgroundColourId, Colour(0xff2c3333));
        setColour (AlertWindow::textColourId, Colour(0xffe7f6f2));
        setColour (AlertWindow::outlineColourId, Colour(0xff395b64));

        setColour (TextButton::buttonColourId, Colour(0xff395b64));
        setColour (TextButton::textColourOffId, Colour(0xffe7f6f2));
        setColour (TextButton::textColourOnId, Colour(0xffe7f6f2));

        setColour (Slider::backgroundColourId, Colour(0xff395b64));
        setColour (Slider::thumbColourId, Colour(0xffa5c9ca));
        setColour (Slider::textBoxHighlightColourId, Colour(0x66a5c9ca));
        setColour (Slider::textBoxOutlineColourId, Colour(0x44e7f6f2));
    }

    void drawButtonBackground (Graphics& g,
                                           Button& button,
                                           const Colour& backgroundColour,
                                           bool shouldDrawButtonAsHighlighted,
                                           bool shouldDrawButtonAsDown) override
    {
        auto cornerSize = 4.0f;
        auto bounds = button.getLocalBounds().toFloat().reduced (0.5f, 0.5f);

        auto baseColour = backgroundColour.withMultipliedSaturation (button.hasKeyboardFocus (true) ? 1.3f : 0.9f)
                                          .withMultipliedAlpha (button.isEnabled() ? 1.0f : 0.5f);

        if (shouldDrawButtonAsDown || shouldDrawButtonAsHighlighted)
            baseColour = baseColour.contrasting (shouldDrawButtonAsDown ? 0.2f : 0.05f);

        g.setColour (baseColour);

        auto flatOnLeft   = button.isConnectedOnLeft();
        auto flatOnRight  = button.isConnectedOnRight();
        auto flatOnTop    = button.isConnectedOnTop();
        auto flatOnBottom = button.isConnectedOnBottom();

        if (flatOnLeft || flatOnRight || flatOnTop || flatOnBottom)
        {
            Path path;
            path.addRoundedRectangle (bounds.getX(), bounds.getY(),
                                      bounds.getWidth(), bounds.getHeight(),
                                      cornerSize, cornerSize,
                                      ! (flatOnLeft  || flatOnTop),
                                      ! (flatOnRight || flatOnTop),
                                      ! (flatOnLeft  || flatOnBottom),
                                      ! (flatOnRight || flatOnBottom));

            g.fillPath (path);

            g.setColour (button.findColour (TextButton::buttonColourId));
            g.strokePath (path, PathStrokeType (1.0f));
        }
        else
        {
            g.fillRoundedRectangle (bounds, cornerSize);

            g.setColour (button.findColour (TextButton::buttonColourId));
            g.drawRoundedRectangle (bounds, cornerSize, 1.0f);
        }
    }
};