//
// Created by Arne Papen on 20/11/2020.
//

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/scene.h>

#include "HomeScreenScene.h"

int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    //call the starting scene
    HomeScreenScene* startScene = new HomeScreenScene(engine);
    engine->setScene(startScene);

    //Running the game without ending
    while (true) {
        engine->update();
        engine->delay(1000);
    }

    return 0;
}