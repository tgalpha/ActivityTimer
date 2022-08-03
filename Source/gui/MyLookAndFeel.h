/*
  ==============================================================================

    MyLookAndFeel.h
    Created: 2 Aug 2022 7:10:52pm
    Author:  haoyu.zhou

  ==============================================================================
*/

#pragma once


#include <JuceHeader.h>

namespace theme
{
    using namespace juce;
    class MyLookAndFeel : public LookAndFeel_V4
    {
        public:
        MyLookAndFeel ();

        void drawButtonBackground (Graphics& g,
                                   Button& button,
                                   const Colour& backgroundColour,
                                   bool shouldDrawButtonAsHighlighted,
                                   bool shouldDrawButtonAsDown) override;
    };
}
