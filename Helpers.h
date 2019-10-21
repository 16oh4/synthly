//
// Created by synthly on 10/5/19.
//

#ifndef SYNTHLYOS_HELPERS_H
#define SYNTHLYOS_HELPERS_H

//Static class to provide reusable methods for components
class Helpers : public Component
{
public:
    //Returns the reference button with embedded image
    static void setupImageButton(ImageButton& imgButton, const char* name)
    {

        int imgSize;

        auto imgData = BinaryData::getNamedResource(name, imgSize);

        Image img = ImageCache::getFromMemory(imgData, imgSize);

        imgButton.setImages(
                true,
                true,
                true,
                //Normal
                img,
                1.0f,
                Colours::transparentWhite,
                //Over
                img,
                1.0f,
                Colours::transparentWhite,
                //Down
                img,
                1.0f,
                Colours::transparentWhite
        );

    }

private:

};






#endif //SYNTHLYOS_HELPERS_H
