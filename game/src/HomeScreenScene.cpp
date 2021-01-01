//
// Created by Arne Papen on 20/12/2020.
//


#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "HomeScreenScene.h"
#include "sprites/bird.h"
#include "sprites/sharedPalette.h"
#include "backgrounds/homeScreen.h"
#include "backgrounds/sharedBgPalette.h"
#include "backgrounds/homeScreen.h"

//Getters voor de background
std::vector<Background *> HomeScreenScene::backgrounds() {
    return {
        bgHomeScreen.get()
    };
}

//Getters voor de sprites
std::vector<Sprite *> HomeScreenScene::sprites() {
    return {
        bird.get()
    };
}

//Loading HomeScreenScene
void HomeScreenScene::load() {
    //Set color palettes for Sprites and backgrounds
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPalette, sizeof(sharedPalette)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(sharedBgPalette, sizeof(sharedBgPalette)));

    //Making sprites for HomeScreenScene
    SpriteBuilder<Sprite> builder;
    bird = builder
            .withData(birdTiles, sizeof(birdTiles))
            .withSize(SIZE_16_16)
            .withAnimated(4, 8)
            .withLocation(107,60)
            .buildPtr();

    //Making background for HomeScreenScene (screenblock 14 beste keuze)
    bgHomeScreen = std::unique_ptr<Background>(new Background(1, background_data, sizeof(background_data), map, sizeof(map)));
    bgHomeScreen.get()->useMapScreenBlock(14);

    //Disable other backgrounds to prevent glitching parts
    REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1;

    //Enable text function in the scene
    engine.get()->enableText();

    //Show text on the main menu to start the game by pressing the start button and change the color to black
    //TextStream::instance().setFontColor();
    TextStream::instance().setText("PRESS START TO LAUNCH THE GAME", 4, 0);
}

//do ... every tick (each engine)
void HomeScreenScene::tick(u16 keys) {
//    scrollX += 1;
//    bgHomeScreen.get()->scroll(scrollX, scrollY);
}