//
// Created by Arne Papen on 26/01/2021.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ENDSCREENSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_ENDSCREENSCENE_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>

class EndScreenScene : public Scene {
private:
    //Object declaration background on the EndScreenScene
    std::unique_ptr<Background> bgEndScreen;

    //Used variables
    int endScore;
    int endHighScore;
public:
    //Constructor and making scene for the end screen
    EndScreenScene(std::shared_ptr<GBAEngine> engine, int score, int highScore) : Scene(engine) {endScore = score; endHighScore = highScore;}
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    //Default methods
    void load() override;
    void tick(u16 keys) override;
};

#endif //GBA_SPRITE_ENGINE_PROJECT_ENDSCREENSCENE_H
