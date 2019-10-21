//
// Created by synthly on 10/4/19.
//

#ifndef SYNTHLYOS_PALETTE_H
#define SYNTHLYOS_PALETTE_H

/*
 * Class for maintaining SynthlyOS branding colors
 *
 *
 */
class Palette : public LookAndFeel_V4
{
public:
    Palette()
    {
        setTextButton();
        setLabel();
    }



private:

    //Defines the look and feel of TextButtons
    void setTextButton()
    {
        //Button color
        setColour(TextButton::buttonColourId, Colours::ghostwhite);
        //Text color
        setColour(TextButton::textColourOffId, Colours::black);


        //Doesnt' do anything, maybe when listener added?
        //setColour(TextButton::textColourOnId, Colours::yellow);
        //Doesn't do anything
        //setColour(TextButton::buttonNormal, Colours::red);
        //setColour(TextButton::buttonOnColourId, Colours::red);
        //setColour(TextButton::buttonOver, Colours::blue);
    }

    void setDrawableText()
    {
        //setColour(DrawableText::)
    }

    //Defines the look and feel of Labels
    void setLabel()
    {
        setColour(Label::backgroundColourId, Colours::transparentWhite);
        setColour(Label::textColourId, Colours::black);
    }

    void setDrawableButton()
    {
        setColour(DrawableButton::backgroundColourId, Colours::blue);
    }


};



#endif //SYNTHLYOS_PALETTE_H
