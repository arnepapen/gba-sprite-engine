//
// Created by Arne Papen on 26/01/2021.
//

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "sprites/birdSprite.h"
#include "backgrounds/homeScreen.h"
#include "backgrounds/bgPaletteHomeScreen.h"
#include "sprites/sharedPalette.h"
//#include "GameScreenScene.h"
#include "EndScreenScene.h"

//Getters background
std::vector<Background *> EndScreenScene::backgrounds() {
    return {
            bgEndScreen.get()
    };
}

////Getters voor de sprites
//std::vector<Sprite *> EndScreenScene::sprites() {
//    return {
//            bird.get()
//    };
//}

//Loading EndScreenScene
void EndScreenScene::load() {
    //Set color palettes for Sprites and backgrounds
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPalette, sizeof(sharedPalette)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(bgPaletteHomeScreen, sizeof(bgPaletteHomeScreen)));

//    //Making sprites for HomeScreenScene
//    SpriteBuilder<Sprite> builder;
//    bird = builder
//            .withData(birdTiles, sizeof(birdTiles))
//            .withSize(SIZE_16_16)
//            .withAnimated(4, 8)
//            .withLocation(107,60)
//            .buildPtr();

    //Making background for HomeScreenScene (screenblock 14 beste keuze)
    bgEndScreen = std::unique_ptr<Background>(new Background(1, background_data, sizeof(background_data), map, sizeof(map)));
    bgEndScreen.get()->useMapScreenBlock(14);

    //Disable other backgrounds to prevent glitching parts
    REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1;

    //Enable text function in the scene
    engine.get()->enableText();

    //Show the score and the highscore
    //TextStream::instance().setFontColor();
    TextStream::instance().setText("PRESS START TO LAUNCH THE GAME", 4, 0);
}

//do ... every tick (each engine)
void EndScreenScene::tick(u16 keys) {
    //If the start button is pressed, going to the gamescreen again
    if(keys & KEY_START) {
        //engine->transitionIntoScene(new GameScreenScene(engine), new FadeOutScene(3));
    }
}