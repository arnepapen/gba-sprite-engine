//
// Created by Arne Papen on 20/12/2020.
//


#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "HomeScreenScene.h"
#include "sprites/chicken.h"
#include "sprites/sharedPalette.h"
#include "backgrounds/homeScreen.h"

//Getters voor de background
std::vector<Background *> HomeScreenScene::backgrounds() {
    return {
//        bgHomeScreen.get();
    };
}

//Getters voor de sprites
std::vector<Sprite *> HomeScreenScene::sprites() {
    return {
        chicken.get()
    };
}

//Loading HomeScreenScene
void HomeScreenScene::load() {
    //Set color palettes for Sprites and backgrounds
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPalette, sizeof(sharedPalette)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    //Making sprites for HomeScreenScene
    SpriteBuilder<Sprite> builder;
    chicken = builder
            .withData(chickenTiles, sizeof(chickenTiles))
            .withSize(SIZE_64_64)
            .withLocation(50,50)
            .buildPtr();

    //Making background for HomeScreenScene
//    bgHomeScreen = std::unique_ptr<Background>(new Background(1, background_data, sizeof(background_data), map, sizeof(map)));
//    bgHomeScreen.get()->useMapScreenBlock(13);
}

//do ... every tick (each engine)
void HomeScreenScene::tick(u16 keys) {
//    scrollX += 1;
//    bgHomeScreen.get()->scroll(scrollX, scrollY);
}