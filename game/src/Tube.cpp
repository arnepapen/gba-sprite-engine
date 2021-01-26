//
// Created by Arne Papen on 25/01/2021.
//

#include "Tube.h"
#include <libgba-sprite-engine/gba_engine.h>
#include <stdlib.h>


void Tube::randomHeightTube() {
    //Generate random Y coordinates for the middle of the tube
    centerTubesY = rand() % (GBA_SCREEN_HEIGHT - (marginTopBottom * 2)) + marginTopBottom;
    //Calculate coordinates with the set values for the margins and the random generated value
    yPosCapBot = centerTubesY + (marginBetweenTubesY / 2);
    yPosExtBot = yPosCapBot + 32;
    yPosCapTop = centerTubesY - 32 - (marginBetweenTubesY / 2);
    yPosExtTop = yPosCapTop - 64;

    onceExecuted = true;
}

//Each engine tick move tube
void Tube::tick() {
    if (onceExecuted != true){
        randomHeightTube();
    }

    //Flip the top sprites
    tubeCapTopSprite->flipVertically(true);
    tubeExtTopSprite->flipVertically(true);

    //Move all the parts at same time
    tubeCapTopSprite->moveTo(xPos, yPosCapTop);
    tubeExtTopSprite->moveTo(xPos, yPosExtTop);
    tubeCapBotSprite->moveTo(xPos, yPosCapBot);
    tubeExtBotSprite->moveTo(xPos, yPosExtBot);

    xPos -= 1;
}
