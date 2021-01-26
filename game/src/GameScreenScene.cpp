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
#include <string>
#include <sstream>

#include "GameScreenScene.h"
#include "sprites/birdSprite.h"
#include "sprites/Tube.h"
#include "sprites/sharedPalette.h"
#include "backgrounds/gameScreen.h"
#include "backgrounds/bgPaletteGameScreen.h"

//Create multiple tubes from the template
std::unique_ptr<Tube> GameScreenScene::createTube(int xPos) {
    return std::unique_ptr<Tube>(   new Tube(
            spriteBuilder
                .withSize(SIZE_32_32)
                .withLocation(xPos,0)
                .buildWithDataOf(*aTubeCapSprite.get()),
            spriteBuilder
                .withSize(SIZE_32_64)
                .withLocation(xPos,0)
                .buildWithDataOf(*aTubeExtensionSprite.get())));
}

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

    //More Tube sprites into the vector
    for (auto& tube : tubes) {
        sprites.push_back((tube->getTubeCapSprite()));
        sprites.push_back((tube->getTubeExtensionSprite()));
    }

    sprites.push_back(aTubeCapSprite.get());
    sprites.push_back(aTubeExtensionSprite.get());
    
    return sprites;
}

//Loading GameScreenScene
void GameScreenScene::load() {
    //Set color palettes for Sprites and backgrounds
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPalette, sizeof(sharedPalette)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(bgPaletteGameScreen, sizeof(bgPaletteGameScreen)));

    //Making sprites for GameScreenScene
    aTubeCapSprite = spriteBuilder
            .withData(tubeCapTiles, sizeof(tubeCapTiles))
            .withSize(SIZE_32_32)
            .withLocation(GBA_SCREEN_WIDTH + 30, GBA_SCREEN_HEIGHT + 30)
            .buildPtr();

    aTubeExtensionSprite = spriteBuilder
            .withData(tubeExtensionTiles, sizeof(tubeExtensionTiles))
            .withSize(SIZE_32_64)
            .withLocation(GBA_SCREEN_WIDTH + 30, GBA_SCREEN_HEIGHT + 30)
            .buildPtr();

    SpriteBuilder<AffineSprite> affineBuilder;
    bird = affineBuilder
            .withData(birdTiles, sizeof(birdTiles))
            .withSize(SIZE_16_16)
            .withAnimated(4, 8)
            .withLocation(107,60)
            .withinBounds()
            .buildPtr();

    //Making background for GameScreenScene (screenblock 14 beste keuze)
    bgGameScreen = std::unique_ptr<Background>(new Background(1, background_data, sizeof(background_data), map, sizeof(map)));
    bgGameScreen.get()->useMapScreenBlock(14);

    //Enabling textstreams
    engine.get()->enableText();

    //Disable other backgrounds to prevent glitching parts
    REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1;
}

//do ... every tick (each engine)
void GameScreenScene::tick(u16 keys) {
    //TEXT FOR DEBUGGING ONLY
    //TextStream::instance().setText(std::to_string(birdY), 4, 0);
    if (timer2 != 10) {
        tubes.push_back(createTube(200));
        engine.get()->updateSpritesInScene();
        timer2 = 10;
    }

    for(auto &tube : tubes){
        tube->tick();
    }


    //Reduce background scrolling speed by 2 and reset self made timer
    timer++;
    if(timer >= 2){
        scrollX += 1;
        bgGameScreen.get()->scroll(scrollX, scrollY);
        timer = 0;
    }


    //Pressing A, B or arrow up let's the bird jump only ONCE, otherwise 'gravity' will pull down the bird
    if((keys & KEY_UP || keys & KEY_A || keys & KEY_B) && holdJumpBtn == false){
        //(Re)start timer
        engine->getTimer()->reset();
        engine->getTimer()->start();

        //Let tha game begin
        firstJump = true;
        holdJumpBtn = true;
    }
    else if (!(keys & KEY_UP || keys & KEY_A || keys & KEY_B)){
        holdJumpBtn = false;
    }

    //Depending of the acceleration in the Y position, rotating the bird a bit
    //Bird muzzle straight ahead
    if(birdY >= -1 && birdY <= 0){
        bird.get()->rotate(0);
    }
    //Rotate bird with muzzle upwards
    else if(birdY < 0){
        bird.get()->rotate(8000);
    }
    //Rotate bird with muzzle the most downwards
    else if(birdY > 2){
        bird.get()->rotate(-10000);
    }
    //Rotate bird with muzzle more upwards
    else if(birdY > 0 && birdY < 2){
        bird.get()->rotate(-6000);
    }



    //The first jump let the game begin
    if(firstJump == true) {
        //'Gravity' is created by a certain Y velocity upwards that is slowed down by a factor of the time that the jump key is pressed
        //This will first slow down the bird, next the bird moves with a rising speed downwards according to the time elapsed after jump
        birdY = -2 + (engine->getTimer()->getTotalMsecs() / 110);
        bird->setVelocity(0,birdY);
    }


    //Print text in the upper left corner with the current score and highscore
    TextStream::instance().setText("Highscore:" + std::to_string(highscore), 0, 0);
    TextStream::instance().setText("Score:" + std::to_string(score), 1, 0);
}

//Once the bird collides with a pipe or the ground the game over method will execute
void GameScreenScene::gameOver() {

}