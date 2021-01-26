//
// Created by Arne Papen on 25/01/2021.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_TUBE_H
#define GBA_SPRITE_ENGINE_PROJECT_TUBE_H

#include <libgba-sprite-engine/sprites/sprite.h>

class Tube {
private:
    std::unique_ptr<Sprite> tubeCapSprite;
    std::unique_ptr<Sprite> tubeExtensionSprite;

public:
    //Constructor for the tubes
    Tube(std::unique_ptr<Sprite> tubeCapSprite, std::unique_ptr<Sprite> tubeExtensionSprite) :
        tubeCapSprite(std::move(tubeCapSprite)), tubeExtensionSprite(std::move(tubeExtensionSprite)) {}

    //Parameters for the tubes
    int xPos;
    int yPosCap;
    int yPosExtension;
    int marginBetweenTubesY = 32;
    int marginTopBottom = 20;
    int centerTubesY;

    //Related methods for the tubes
    Sprite* getTubeCapSprite() {return tubeCapSprite.get();}
    Sprite* getTubeExtensionSprite() {return tubeExtensionSprite.get();}
    void tick();
    void setPosition(int x, int yPosC, int yPosE);
};

#endif //GBA_SPRITE_ENGINE_PROJECT_TUBE_H
