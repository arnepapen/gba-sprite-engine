//
// Created by Arne Papen on 11/01/2021.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GAMESCREENSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_GAMESCREENSCENE_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>

class GameScreenScene : public Scene {
private:
    //Object declaration background on the GameScreenScene
    std::unique_ptr<Background> bgGameScreen;

    //Object declaration sprites on the GameScreenScene
    std::unique_ptr<AffineSprite> bird;

    //Used variables
    int scrollX, scrollY;
    int timer;
    bool holdJumpBtn;
    int timer2;
    int birdX, birdY;
    bool firstJump = false;
    int score, highscore;
public:
    //Constructor
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    //Making scene for the game screen
    GameScreenScene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    //Default
    void load() override;
    void tick(u16 keys) override;

    //Game related methods
    void gameOver();
};

#endif //GBA_SPRITE_ENGINE_PROJECT_GAMESCREENSCENE_H
