//
// Created by Arne Papen on 11/01/2021.
//



#include <vector>
#include <libgba-sprite-engine/sprites/affine_sprite.h>
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
    //Vector with all sprites inside
    std::vector<Sprite*> sprites;

    //Bird sprite into the vector
    sprites.push_back(bird.get());

    //Pipes into the vector

    return sprites;
}

//Loading GameScreenScene
void GameScreenScene::load() {
    //Set color palettes for Sprites and backgrounds
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPalette, sizeof(sharedPalette)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(sharedBgPalette, sizeof(sharedBgPalette)));

    //Making sprites for GameScreenScene
    SpriteBuilder<AffineSprite> affineBuilder;
    bird = affineBuilder
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
    timer++;

    //Reduce background scrolling speed by 2 and reset timer
    if(timer >= 2){
        scrollX += 1;
        bgGameScreen.get()->scroll(scrollX, scrollY);
        timer = 0;
    }


    //Pressing A, B or arrow up let's the bird jump only ONCE, otherwise 'gravity' will pull down the bird
    if((keys & KEY_UP || keys & KEY_A || keys & KEY_B) && holdJumpBtn == false){
        for (int v = -20; v < 0 ; v++) {
            bird->setVelocity(0,-6);
        }
        bird.get()->rotate(8000);
        holdJumpBtn = true;
    }
    //If jump buttons are not active, reset the holdJumpBtn indicator
    else if(!(keys & KEY_UP || keys & KEY_A || keys & KEY_B) && holdJumpBtn == true){
        holdJumpBtn = false;
    }
    //If you didn't jump or hold the button, the bird will taken down by 'gravity'
    else {
        timer2++;
        if (timer2 >= 4) {
            bird->setVelocity(0,+1);
            bird.get()->rotate(-8000);
            timer2 = 0;
        }
    }

}