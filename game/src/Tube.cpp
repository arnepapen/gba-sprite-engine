//
// Created by Arne Papen on 25/01/2021.
//

#include "Tube.h"
#include <libgba-sprite-engine/gba_engine.h>
#include <stdlib.h>

void Tube::setPosition(int x, int yPosC, int yPE) {
    xPos = x;
    yPosCap = yPosC;
    yPosExtension = yPE;
}

//Each engine tick move tube
void Tube::tick() {
    //Generate random height for the tube with a minimal of space between the tubes of 32px
    centerTubesY = rand() % (GBA_SCREEN_HEIGHT - marginTopBottom) + (0 + marginTopBottom);
    yPosCap = centerTubesY - (marginBetweenTubesY / 2);
    yPosExtension = yPosCap + 32;

    tubeCapSprite->moveTo(xPos, yPosCap);
    tubeExtensionSprite->moveTo(xPos, yPosExtension);
    xPos -= 1;
}
