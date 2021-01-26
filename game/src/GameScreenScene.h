//
// Created by Arne Papen on 11/01/2021.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GAMESCREENSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_GAMESCREENSCENE_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include "Tube.h"

class GameScreenScene : public Scene {
private:
    //Object declaration background on the GameScreenScene
    std::unique_ptr<Background> bgGameScreen;

    //Object declaration sprites on the GameScreenScene
    std::unique_ptr<AffineSprite> bird;

    //Tube sprites and methods
    std::unique_ptr<Sprite> aTubeExtTopSprite;
    std::unique_ptr<Sprite> aTubeCapTopSprite;
    std::unique_ptr<Sprite> aTubeExtBotSprite;
    std::unique_ptr<Sprite> aTubeCapBotSprite;
    std::vector<std::unique_ptr<Tube>> tubes;

    //Create a spriteBuilder to create tubes
    SpriteBuilder<Sprite> spriteBuilder;

    //Used variables
    bool holdJumpBtn = false;
    int birdX, birdY;
    bool firstJump = false;
    int scrollX, scrollY;
    int timer = 0;
    int tubeSpawnTimer = 0;
    int score = 0;
    int highScore;
public:
    //Constructor
    GameScreenScene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    //Getters
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    //Default
    void load() override;
    void tick(u16 keys) override;

    //Game related methods
    std::unique_ptr<Tube> createTube(int xPos);
    void scoreCounter();
    void tubeEndOfScreenDetection();
    void collisionDetection();
    void gameOver();
};

#endif //GBA_SPRITE_ENGINE_PROJECT_GAMESCREENSCENE_H
