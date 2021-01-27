
## Flappy Bird GBA Game - by Arne Papen


#### Things to know 

This Game Boy Advance game is based on an already created engine written in C++ 11 forked from [wgroeneveld](https://github.com/wgroeneveld/gba-sprite-engine). This project is part of the course [Software design with C/C++](https://www.uhasselt.be/studyguide?n=4&t=01&a=2020&i=3433) of the bridging programme Electronics and ICT Engineering Technology at UHasselt Belgium. 

#### Project information

The original widely known flappy bird game is back for the one and only Game Boy Advance! It's very simple, start the game with the start button and if you are ready to go, you can launch the bird with the "A" "B" or "ARROW_UP" buttons. Try to dodge the green tubes without falling on the ground, and maybe you could beat your own highScore. 

Flappy Bird is not yet tested on the real GBA hardware, I have used the [mGBA](https://mgba.io/) emulator to test and debug during the design phase.  

The source code of the Flappy Bird game can be found in `game/src/`.
All of the used images can be found in `game/img/`.

Enjoy it!

##### Known issues
- Tubes passing in front of the score & highscore
- Relaunching the game after a game over, not always working very well, a reset always works
- Highscore & Score are not displayed after a game over
- Sound effects are not played simultaneously (therefore the 'jump' effect is not always played if a tube is passed)
