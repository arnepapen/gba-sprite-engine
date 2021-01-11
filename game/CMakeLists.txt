project(game)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/HomeScreenScene.h src/HomeScreenScene.cpp src/sprites/bird.h src/sprites/sharedPalette.h src/backgrounds/homeScreen.h src/backgrounds/sharedBgPalette.h src/GameScreenScene.cpp src/GameScreenScene.h src/backgrounds/gameScreen.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )