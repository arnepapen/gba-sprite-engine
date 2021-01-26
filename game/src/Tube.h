//
// Created by Arne Papen on 25/01/2021.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_TUBE_H
#define GBA_SPRITE_ENGINE_PROJECT_TUBE_H

#include <libgba-sprite-engine/sprites/sprite.h>

class Tube {
private:
    //Ext stands for extension, bot for bottom
    std::unique_ptr<Sprite> tubeCapTopSprite;
    std::unique_ptr<Sprite> tubeExtTopSprite;
    std::unique_ptr<Sprite> tubeCapBotSprite;
    std::unique_ptr<Sprite> tubeExtBotSprite;

public:
    //Constructor for the tubes
    Tube(std::unique_ptr<Sprite> tubeCapTopSprite, std::unique_ptr<Sprite> tubeExtTopSprite, std::unique_ptr<Sprite> tubeCapBotSprite, std::unique_ptr<Sprite> tubeExtBotSprite) :
        tubeCapTopSprite(std::move(tubeCapTopSprite)), tubeExtTopSprite(std::move(tubeExtTopSprite)), tubeCapBotSprite(std::move(tubeCapBotSprite)), tubeExtBotSprite(std::move(tubeExtBotSprite)) {}

    //Parameters for the tubes
    int xPos = 272;
    int yPosCapTop;
    int yPosCapBot;
    int yPosExtTop;
    int yPosExtBot;
    //45 = perfect difficulty
    int marginBetweenTubesY = 45;
    //50 = perfect to avoid spaces between the roof or the ground
    int marginTopBottom = 50;
    int centerTubesY;
    //One time tube generation
    bool onceExecuted = false;

    //Related methods for the tubes
    Sprite* getTubeCapTopSprite() {return tubeCapTopSprite.get();}
    Sprite* getTubeExtTopSprite() {return tubeExtTopSprite.get();}
    Sprite* getTubeCapBotSprite() {return tubeCapBotSprite.get();}
    Sprite* getTubeExtBotSprite() {return tubeExtBotSprite.get();}
    void tick();
    void randomHeightTube();
    bool isOffScreen() {return tubeCapBotSprite->isOffScreen();}
    //void setPosition(int x, int yPosC, int yPosE);
};

#endif //GBA_SPRITE_ENGINE_PROJECT_TUBE_H
