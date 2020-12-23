//
// Created by Arne Papen on 20/12/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_HOMESCREENSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_HOMESCREENSCENE_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>

class HomeScreenScene : public Scene {
private:
    ////Object declaration background on the homeScreenScene
    std::unique_ptr<Background> bgHomeScreen;

    ////Object declaration sprites on the homeScreenScene
    std::unique_ptr<Sprite> chicken;
public:
    ////Constructor
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    ////Making scene for the home screen
    HomeScreenScene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    ////Default
    void load() override;
    void tick(u16 keys) override;
};

#endif //GBA_SPRITE_ENGINE_PROJECT_HOMESCREENSCENE_H
