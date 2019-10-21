//
// Created by synthly on 10/4/19.
//

#ifndef SYNTHLYOS_APPFOOTER_H
#define SYNTHLYOS_APPFOOTER_H

#include "BinaryData.h"
#include "Helpers.h"

class AppFooter : public Component
{
public:
    AppFooter() :   labelFont(getHeight(), 0b001),
                    volumeLevel("GAIN", DrawableButton::ImageFitted)
    {

        //Setup ImageButtons with images
        Helpers::setupImageButton(backButton, "back_button_png");
        addAndMakeVisible(backButton,0);

        Helpers::setupImageButton(pauseButton, "pause_button_png");
        addAndMakeVisible(pauseButton,0);

        Helpers::setupImageButton(playButton, "play_button_png");
        addAndMakeVisible(playButton,0);

        Helpers::setupImageButton(cubeButton, "cube_button2_png");
        addAndMakeVisible(cubeButton,0);

        Helpers::setupImageButton(batteryButton, "battery_icon2_png");
        addAndMakeVisible(batteryButton, 0);


        //TODO: parametrically change channel name
        //volumeLabel.setFont(labelFont);
        volumeLabel.setText("MAIN",
                NotificationType::dontSendNotification);
        volumeLabel.setJustificationType(Justification::centred);
        addAndMakeVisible(volumeLabel, 0);

        addAndMakeVisible(volumeLevel);

        /*
        volumeButton.setButtonText("MAIN");
        volumeButton.setOpaque(false);
        volumeButton.setConnectedEdges(15); //all edges should be rigid, not rounded
        volumeButton.setState(ButtonState::)
         addAndMakeVisible(volumeButton, 0);
        */

        /*
        volumeText.setText("MAIN");
        volumeText.setColour(Colours::black);
        volumeText.setJustification(Justification::centred);
         addAndMakeVisible(volumeText, 0);
        */

    }
    void paint(Graphics& g) override
    {
        //Fill the background of the footer
        g.fillAll(Colours::ghostwhite);

    }

    void resized() override
    {
        auto area = getLocalBounds();

        auto sectionWidth = getWidth()/3;
        auto subSectionWidth = sectionWidth/2;
        auto subSubSectionWidth = subSectionWidth/2;
        auto margin = getHeight()/10;

        //Add Buttons!
        backButton.setBounds(area.removeFromLeft(subSectionWidth).reduced(margin));

        //Play and pause use subSubSectionWidth because they need to fit in half the width
        pauseButton.setBounds(area.removeFromLeft(subSubSectionWidth).reduced(margin));
        playButton.setBounds(area.removeFromLeft(subSubSectionWidth).reduced(margin));

        //Add home button!
        cubeButton.setBounds(area.removeFromLeft(sectionWidth).reduced(margin));

        //Add volume control Buttons (no margin no text to prevent rounding
        //volumeButton.setBounds(area.removeFromLeft(subSubSectionWidth));
        volumeLabel.setBounds(area.removeFromLeft(subSubSectionWidth).reduced(margin));
        //labelFont.setHeight(getHeight()-margin);

        //Add gain level of master channel
        volumeLevel.setBounds(area.removeFromLeft(subSubSectionWidth).reduced(margin));


    }
private:
    //TextButton volumeButton;
    //DrawableText volumeText;
    Font labelFont;
    Label volumeLabel;
    ImageButton backButton, playButton, pauseButton, cubeButton, batteryButton;
    DrawableButton volumeLevel;
    Image backIMG, playIMG, pauseIMG, cubeIMG, batteryIMG;




    //Deprecated
    void setupImages()
    {
        //File backPATH("../Icons/back_button.png");
        //backIMG2 = ImageCache::getFromFile(backPATH);

        //Create Image object to store image data
        backIMG = ImageCache::getFromMemory(BinaryData::back_button_png,
                                            BinaryData::back_button_pngSize);
        playIMG = ImageCache::getFromMemory(BinaryData::play_button_png,
                                            BinaryData::back_button_pngSize);
        pauseIMG = ImageCache::getFromMemory(BinaryData::pause_button_png,
                                            BinaryData::pause_button_pngSize);
        cubeIMG = ImageCache::getFromMemory(BinaryData::cube_button2_png,
                                             BinaryData::cube_button2_pngSize);
        batteryIMG = ImageCache::getFromMemory(BinaryData::battery_icon2_png,
                                            BinaryData::battery_icon2_pngSize);

        //Pass Image object to button
        backButton.setImages(
                true,
                true,
                true,
                //Normal
                backIMG,
                0.5f,
                Colours::transparentWhite,
                //Over
                backIMG,
                0.5f,
                Colours::transparentWhite,
                //Down
                backIMG,
                0.5f,
                Colours::transparentWhite
        );

        playButton.setImages(
            true,
            true,
            true,

            //Normal
            playIMG,
            0.5f,
            Colours::transparentWhite,

            //Over
            playIMG,
            0.5f,
            Colours::transparentWhite,

            //Down
            playIMG,
            0.5f,
            Colours::transparentWhite
        );

        pauseButton.setImages(
                true,
                true,
                true,

                //Normal
                pauseIMG,
                0.5f,
                Colours::transparentWhite,

                //Over
                pauseIMG,
                0.5f,
                Colours::transparentWhite,

                //Down
                pauseIMG,
                0.5f,
                Colours::transparentWhite
        );

        cubeButton.setImages(
                true,
                true,
                true,

                //Normal
                cubeIMG,
                0.5f,
                Colours::transparentWhite,

                //Over
                cubeIMG,
                0.5f,
                Colours::transparentWhite,

                //Down
                cubeIMG,
                0.5f,
                Colours::transparentWhite
        );

        batteryButton.setImages(
                true,
                true,
                true,

                //Normal
                batteryIMG,
                0.5f,
                Colours::transparentWhite,

                //Over
                batteryIMG,
                0.5f,
                Colours::transparentWhite,

                //Down
                batteryIMG,
                0.5f,
                Colours::transparentWhite
        );

    }

};





#endif //SYNTHLYOS_APPFOOTER_H
