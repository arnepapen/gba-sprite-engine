project(game)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/HomeScreenScene.h src/HomeScreenScene.cpp src/sprites/birdSprite.h src/sprites/sharedPalette.h src/backgrounds/homeScreen.h src/backgrounds/bgPaletteGameScreen.h src/GameScreenScene.cpp src/GameScreenScene.h src/backgrounds/gameScreen.h src/backgrounds/bgPaletteHomeScreen.h src/sprites/Tube.h src/Tube.h src/Tube.cpp)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )