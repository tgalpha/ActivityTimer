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

        static Path getResetButtonPath ();
        static Font getTimerFont(float height);

        void drawButtonBackground (Graphics& g,
                                   Button& button,
                                   const Colour& backgroundColour,
                                   bool shouldDrawButtonAsHighlighted,
                                   bool shouldDrawButtonAsDown) override;
        void drawLabel (Graphics&, Label&) override;
        void drawAlertBox (Graphics&, AlertWindow&, const Rectangle<int>& textArea, TextLayout&) override;

        // Personal alias.
        struct ColourTheme
        {
            Colour primaryDark = Colour (0xff2c3333);
            Colour primary = Colour (0xff395b64);
            Colour primaryLight = Colour (0xffa5c9ca);
            Colour primaryAccent = Colour (0xffe7f6f2);
            Colour contrast = Colour (0xffe16428);
        } colourTheme;

        private:
        ColourScheme colourScheme{
            0xff2c3333, 0xff395b64, 0xff2c3333,
            0xff395b64, 0xffe7f6f2, 0xff395b64,
            0xffe7f6f2, 0xff395b64, 0xffffffff
        };
    };
}
