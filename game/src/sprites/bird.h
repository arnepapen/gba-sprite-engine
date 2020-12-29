#ifndef GBA_SPRITE_ENGINE_PROJECT_BIRD_H
#define GBA_SPRITE_ENGINE_PROJECT_BIRD_H

const unsigned int birdTiles[256] __attribute__((aligned(4)))=
        {
                0x00000000,0x00000000,0x00000000,0x04040400,0x00000000,0x03030304,0x04040000,0x03030303,
                0x04040400,0x03030304,0x02020204,0x03030402,0x02020204,0x03030402,0x02020204,0x03030402,
                0x00000000,0x00000000,0x00040404,0x00000000,0x04020403,0x00000000,0x02020204,0x00000004,
                0x04020204,0x00000402,0x04020204,0x00000402,0x04020204,0x00000402,0x02020403,0x00000402,
                0x02020204,0x03030402,0x02020204,0x03030402,0x02020400,0x03030304,0x04040000,0x01010604,
                0x00000000,0x01010604,0x00000000,0x06060400,0x00000000,0x04040000,0x00000000,0x00000000,
                0x04040303,0x00040404,0x04040303,0x00040404,0x05050403,0x04050505,0x04040504,0x00040404,
                0x05050401,0x00040505,0x04040606,0x00040404,0x00000404,0x00000000,0x00000000,0x00000000,

                0x00000000,0x00000000,0x00000000,0x04040400,0x00000000,0x03030304,0x04040000,0x03030303,
                0x04040400,0x03030303,0x03030304,0x03030303,0x03030304,0x03030303,0x04040404,0x03030304,
                0x00000000,0x00000000,0x00040404,0x00000000,0x04020403,0x00000000,0x02020204,0x00000004,
                0x04020204,0x00000402,0x04020204,0x00000402,0x04020204,0x00000402,0x02020403,0x00000402,
                0x02020204,0x03030402,0x02020204,0x03030402,0x04040400,0x03030304,0x04040000,0x01010604,
                0x00000000,0x01010604,0x00000000,0x06060400,0x00000000,0x04040000,0x00000000,0x00000000,
                0x04040303,0x00040404,0x04040303,0x00040404,0x05050403,0x04050505,0x04040504,0x00040404,
                0x05050401,0x00040505,0x04040606,0x00040404,0x00000404,0x00000000,0x00000000,0x00000000,

                0x00000000,0x00000000,0x00000000,0x04040400,0x00000000,0x03030304,0x04040000,0x03030303,
                0x04040400,0x03030303,0x03030304,0x03030303,0x03030304,0x03030303,0x03030304,0x03030303,
                0x00000000,0x00000000,0x00040404,0x00000000,0x04020403,0x00000000,0x02020204,0x00000004,
                0x04020204,0x00000402,0x04020204,0x00000402,0x04020204,0x00000402,0x02020403,0x00000402,
                0x04040404,0x03030304,0x02020204,0x03030402,0x02020204,0x03030402,0x02020204,0x01010604,
                0x04040400,0x01010604,0x00000000,0x06060400,0x00000000,0x04040000,0x00000000,0x00000000,
                0x04040303,0x00040404,0x04040303,0x00040404,0x05050403,0x04050505,0x04040504,0x00040404,
                0x05050401,0x00040505,0x04040606,0x00040404,0x00000404,0x00000000,0x00000000,0x00000000,

                0x00000000,0x00000000,0x00000000,0x04040400,0x00000000,0x03030304,0x04040000,0x03030303,
                0x04040400,0x03030303,0x03030304,0x03030303,0x03030304,0x03030303,0x04040404,0x03030304,
                0x00000000,0x00000000,0x00040404,0x00000000,0x04020403,0x00000000,0x02020204,0x00000004,
                0x04020204,0x00000402,0x04020204,0x00000402,0x04020204,0x00000402,0x02020403,0x00000402,
                0x02020204,0x03030402,0x02020204,0x03030402,0x04040400,0x03030304,0x04040000,0x01010604,
                0x00000000,0x01010604,0x00000000,0x06060400,0x00000000,0x04040000,0x00000000,0x00000000,
                0x04040303,0x00040404,0x04040303,0x00040404,0x05050403,0x04050505,0x04040504,0x00040404,
                0x05050401,0x00040505,0x04040606,0x00040404,0x00000404,0x00000000,0x00000000,0x00000000,
        };


#endif