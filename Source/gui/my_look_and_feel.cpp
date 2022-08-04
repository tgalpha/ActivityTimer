/*
  ==============================================================================

    MyLookAndFeel.cpp
    Created: 3 Aug 2022 4:23:54pm
    Author:  haoyu.zhou

  ==============================================================================
*/

#include "my_look_and_feel.h"

theme::MyLookAndFeel::MyLookAndFeel ()
{
    setColourScheme (colourScheme);

    setColour (AlertWindow::backgroundColourId, colourTheme.primaryDark);
    setColour (AlertWindow::outlineColourId, colourTheme.primaryDark);

    setColour (Slider::backgroundColourId, colourTheme.primary);
    setColour (Slider::thumbColourId, colourTheme.primaryLight);
    setColour (Slider::trackColourId, colourTheme.primaryDark.darker (0.5));
    setColour (Slider::textBoxHighlightColourId, colourTheme.primaryLight.withAlpha (0.2f));
    setColour (Slider::textBoxOutlineColourId, colourTheme.primaryAccent.withAlpha (0.2f));

    setColour (ProgressBar::backgroundColourId, colourTheme.primaryDark.darker (0.5));
    setColour (ProgressBar::foregroundColourId, colourTheme.primary);
}

juce::Path theme::MyLookAndFeel::getResetButtonPath ()
{
    static const unsigned char resetButtonPathData[] = { 110,109,205,204,190,65,0,0,40,66,113,52,51,131,65,0,0,40,66,52,51,51,65,102,230,18,66,113,0,0,192,64,152,153,251,65,0,0,192,64,154,153,191,65,108,0,0,16,65,154,153,191,65,113,0,0,16,65,154,153,241,65,205,204,84,65,102,102,10,66,113,205,204,140,65,255,
    255,27,66,205,204,190,65,0,0,28,66,113,154,153,241,65,0,0,28,66,102,102,10,66,51,51,10,66,113,255,255,27,66,204,204,240,65,0,0,28,66,0,0,190,65,113,0,0,28,66,102,102,140,65,51,51,10,66,102,102,84,65,113,205,204,240,65,0,0,16,65,205,204,190,65,0,0,16,
    65,113,154,153,163,65,0,0,16,65,205,204,139,65,205,204,40,65,113,0,0,104,65,154,153,65,65,205,204,68,65,102,102,106,65,108,102,102,140,65,102,102,106,65,108,102,102,140,65,51,51,141,65,108,51,51,227,64,51,51,141,65,108,51,51,227,64,0,0,232,64,108,154,
    153,33,65,0,0,232,64,108,154,153,33,65,205,204,72,65,113,52,51,75,65,0,0,24,65,52,51,130,65,0,0,248,64,113,205,204,158,65,0,0,192,64,205,204,190,65,0,0,192,64,113,205,204,220,65,0,0,192,64,52,51,247,65,205,204,236,64,113,206,204,8,66,205,204,12,65,52,
    179,18,66,154,153,51,65,113,154,153,28,66,103,102,90,65,206,76,34,66,52,51,135,65,113,0,0,40,66,51,51,161,65,0,0,40,66,51,51,191,65,113,0,0,40,66,51,51,221,65,205,76,34,66,154,153,247,65,113,154,153,28,66,0,0,9,66,51,179,18,66,205,204,18,66,113,205,204,
    8,66,154,153,28,66,51,51,247,65,205,76,34,66,113,205,204,220,65,0,0,40,66,205,204,190,65,0,0,40,66,99,109,0,0,242,65,154,153,0,66,108,102,102,180,65,103,102,196,65,108,102,102,180,65,155,153,93,65,108,102,102,204,65,155,153,93,65,108,102,102,204,65,103,
    102,186,65,108,154,153,1,66,0,0,240,65,99,101,0,0 };
    Path path;
    path.loadPathFromData (resetButtonPathData, sizeof (resetButtonPathData));
    return path;
}

void theme::MyLookAndFeel::drawButtonBackground (Graphics& g, Button& button, const Colour& backgroundColour,
                                                 bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{
    auto cornerSize = 4.0f;
    auto bounds = button.getLocalBounds().toFloat().reduced (0.5f, 0.5f);

    auto baseColour = backgroundColour.withMultipliedAlpha (button.isEnabled() ? 1.0f : 0.5f);

    if (shouldDrawButtonAsDown)
    {
        baseColour = baseColour.darker (0.3f);
    }
    else if (shouldDrawButtonAsHighlighted)
    {
        baseColour = baseColour.contrasting (0.05f);
    }

    g.setColour (baseColour);

    auto flatOnLeft = button.isConnectedOnLeft();
    auto flatOnRight = button.isConnectedOnRight();
    auto flatOnTop = button.isConnectedOnTop();
    auto flatOnBottom = button.isConnectedOnBottom();

    if (flatOnLeft || flatOnRight || flatOnTop || flatOnBottom)
    {
        Path path;
        path.addRoundedRectangle (bounds.getX(), bounds.getY(),
                                  bounds.getWidth(), bounds.getHeight(),
                                  cornerSize, cornerSize,
                                  ! (flatOnLeft || flatOnTop),
                                  ! (flatOnRight || flatOnTop),
                                  ! (flatOnLeft || flatOnBottom),
                                  ! (flatOnRight || flatOnBottom));

        g.fillPath (path);
    }
    else
    {
        g.fillRoundedRectangle (bounds, cornerSize);
    }
}

void theme::MyLookAndFeel::drawLabel (Graphics& g, Label& label)
{
    g.fillAll (label.findColour (Label::backgroundColourId));

    if (! label.isBeingEdited())
    {
        auto alpha = label.isEnabled() ? 1.0f : 0.5f;
        const Font font (getLabelFont (label));

        g.setColour (label.findColour (Label::textColourId).withMultipliedAlpha (alpha));
        g.setFont (font);

        auto textArea = getLabelBorderSize (label).subtractedFrom (label.getLocalBounds());

        g.drawFittedText (label.getText(), textArea, label.getJustificationType(),
                          jmax (1, (int)((float)textArea.getHeight() / font.getHeight())),
                          label.getMinimumHorizontalScale());

        g.setColour (label.findColour (Label::outlineColourId).withMultipliedAlpha (alpha));
    }
    else if (label.isEnabled())
    {
        g.setColour (label.findColour (Label::outlineColourId));
    }

    auto bounds = label.getLocalBounds().toFloat();
    g.drawRoundedRectangle (bounds, bounds.getHeight() / 2, 1.0f);
}

void theme::MyLookAndFeel::drawAlertBox (Graphics& g, AlertWindow& alert, const Rectangle<int>& textArea,
                                         TextLayout& textLayout)
{
    auto cornerSize = 4.0f;

    g.setColour (alert.findColour (AlertWindow::outlineColourId));
    g.drawRoundedRectangle (alert.getLocalBounds().toFloat(), cornerSize, 2.0f);

    auto bounds = alert.getLocalBounds().reduced (1);
    g.reduceClipRegion (bounds);

    auto floatBounds = bounds.toFloat();

    g.setColour (alert.findColour (AlertWindow::backgroundColourId));
    g.fillRoundedRectangle (floatBounds, cornerSize);
    g.setGradientFill (ColourGradient (colourTheme.primary.withAlpha (0.5f),
                                       floatBounds.getWidth() / 2,
                                       floatBounds.getHeight() / 2,
                                       colourTheme.primaryDark,
                                       0,
                                       0,
                                       true));
    g.fillRoundedRectangle (floatBounds, cornerSize);


    auto iconSpaceUsed = 0;

    auto iconWidth = 80;
    auto iconSize = jmin (iconWidth + 50, bounds.getHeight() + 20);

    if (alert.containsAnyExtraComponents() || alert.getNumButtons() > 2)
        iconSize = jmin (iconSize, textArea.getHeight() + 50);

    Rectangle<int> iconRect (iconSize / -10, iconSize / -10,
                             iconSize, iconSize);

    if (alert.getAlertType() != MessageBoxIconType::NoIcon)
    {
        Path icon;
        char character;
        uint32 colour;

        if (alert.getAlertType() == MessageBoxIconType::WarningIcon)
        {
            character = '!';

            icon.addTriangle ((float)iconRect.getX() + (float)iconRect.getWidth() * 0.5f, (float)iconRect.getY(),
                              static_cast<float> (iconRect.getRight()), static_cast<float> (iconRect.getBottom()),
                              static_cast<float> (iconRect.getX()), static_cast<float> (iconRect.getBottom()));

            icon = icon.createPathWithRoundedCorners (5.0f);
            colour = 0x66ff2a00;
        }
        else
        {
            colour = Colour (0xff00b0b9).withAlpha (0.4f).getARGB();
            character = alert.getAlertType() == MessageBoxIconType::InfoIcon ? 'i' : '?';

            icon.addEllipse (iconRect.toFloat());
        }

        GlyphArrangement ga;
        ga.addFittedText ({(float)iconRect.getHeight() * 0.9f, Font::bold},
                          String::charToString ((juce_wchar)(uint8)character),
                          static_cast<float> (iconRect.getX()), static_cast<float> (iconRect.getY()),
                          static_cast<float> (iconRect.getWidth()), static_cast<float> (iconRect.getHeight()),
                          Justification::centred, false);
        ga.createPath (icon);

        icon.setUsingNonZeroWinding (false);
        g.setColour (Colour (colour));
        g.fillPath (icon);

        iconSpaceUsed = iconWidth;
    }

    g.setColour (alert.findColour (AlertWindow::textColourId));

    Rectangle<int> alertBounds (bounds.getX() + iconSpaceUsed, 30,
                                bounds.getWidth(), bounds.getHeight() - getAlertWindowButtonHeight() - 20);

    textLayout.draw (g, alertBounds.toFloat());
}
