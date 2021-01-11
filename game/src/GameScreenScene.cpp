//
// Created by Arne Papen on 11/01/2021.
//



#include <vector>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "GameScreenScene.h"
#include "sprites/bird.h"
#include "sprites/sharedPalette.h"
#include "backgrounds/gameScreen.h"
#include "backgrounds/sharedBgPalette.h"

//Getters voor de background
std::vector<Background *> GameScreenScene::backgrounds() {
    return {
            bgGameScreen.get()
    };
}

//Getters voor de sprites
std::vector<Sprite *> GameScreenScene::sprites() {
    return {
            bird.get()
    };
}

//Loading GameScreenScene
void GameScreenScene::load() {
    //Set color palettes for Sprites and backgrounds
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPalette, sizeof(sharedPalette)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(sharedBgPalette, sizeof(sharedBgPalette)));

    //Making sprites for GameScreenScene
    SpriteBuilder<Sprite> builder;
    bird = builder
            .withData(birdTiles, sizeof(birdTiles))
            .withSize(SIZE_16_16)
            .withAnimated(4, 8)
            .withLocation(107,60)
            .buildPtr();

    //Making background for GameScreenScene (screenblock 14 beste keuze)
    bgGameScreen = std::unique_ptr<Background>(new Background(1, background_data, sizeof(background_data), map, sizeof(map)));
    bgGameScreen.get()->useMapScreenBlock(14);

    //Disable other backgrounds to prevent glitching parts
    REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1;

}

//do ... every tick (each engine)
void GameScreenScene::tick(u16 keys) {
    scrollX += 1;
    bgGameScreen.get()->scroll(scrollX, scrollY);
}