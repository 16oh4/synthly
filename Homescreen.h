//
// Created by synthly on 10/4/19.
//

#ifndef SYNTHLYOS_HOMESCREEN_H
#define SYNTHLYOS_HOMESCREEN_H

#include "AppHeader.h"
#include "AppFooter.h"

class Homescreen : public Component
{
public:
    Homescreen() : header("HOME")
    {
        //Header
        addAndMakeVisible(header, 0);

        //Footer
        addAndMakeVisible(footer, 0);

        //ButtonText
        addAndMakeVisible(effects, 0);
        addAndMakeVisible(mixer, 0);
        addAndMakeVisible(midi, 0);
        addAndMakeVisible(waves, 0);
        addAndMakeVisible(tracks, 0);
        addAndMakeVisible(pattern, 0);
        addAndMakeVisible(sampler, 0);

        /*
        //DrawableText
        //effectsName.setColour(Colours::black);
        effectsName.setButtonText("Effects");
        addAndMakeVisible(effectsName, 0);

        //effectsName.setColour(Colours::black);
        effectsName.setButtonText("Mixer");
        addAndMakeVisible(mixerName, 0);

        //effectsName.setColour(Colours::black);
        effectsName.setButtonText("Midi");
        addAndMakeVisible(midiName, 0);
        */
    }

    void paint(Graphics& g) override
    {
        g.setColour(Colours::darkblue);
        g.fillRect(buttonArea);
    }

    void resized() override
    {
        auto area = getLocalBounds();

        //Constants
        auto headerHeight = getHeight()/16;
        auto footerHeight = getHeight()/12;

        header.setBounds(area.removeFromTop(headerHeight));
        footer.setBounds(area.removeFromBottom(footerHeight));


        /*
         //Gather information about main window
        auto appButtonWidth = area.getWidth()/3;
        auto appButtonHeight = area.getHeight()/3;
        auto appTextHeight = appButtonHeight/10;
        auto appButtonMargin = appButtonWidth/10;


         //SETUP FIRST DRAWER
        auto firstDrawer = area.removeFromTop(appButtonHeight+appTextHeight);

        //buttonArea = firstDrawer.removeFromLeft(appButtonWidth).reduced(appButtonMargin);
        effects.setBounds(firstDrawer.removeFromLeft(appButtonWidth).reduced(appButtonMargin));
        mixer.setBounds(firstDrawer.removeFromLeft(appButtonWidth).reduced(appButtonMargin));
        midi.setBounds(firstDrawer.removeFromLeft(appButtonWidth).reduced(appButtonMargin));


        auto firstTextBars = firstDrawer.removeFromBottom(appTextHeight);
        effectsName.setBounds(firstTextBars.removeFromLeft(appButtonWidth));
        mixerName.setBounds(firstTextBars.removeFromLeft(appButtonWidth));
        midiName.setBounds(firstTextBars.removeFromLeft(appButtonWidth))





        effectsName.setBoundsToFit(
                buttonArea,
                Justification::centred,
                false);

        */




    }

private:
    //Internal Components
    TextButton effects, mixer, midi, waves, tracks, pattern, sampler;
    TextButton effectsName, mixerName, midiName;
    Rectangle<int> buttonArea;

    //Child components
    AppHeader header;
    AppFooter footer;
};




#endif //SYNTHLYOS_HOMESCREEN_H
