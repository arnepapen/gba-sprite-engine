//
// Created by Arne Papen on 25/01/2021.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_TUBESPRITE_H
#define GBA_SPRITE_ENGINE_PROJECT_TUBESPRITE_H

const unsigned int tubeCapTiles[256] __attribute__((aligned(4)))=
        {
                0x29626200,0x6C103570,0x18311953,0x1818183F,0x201F6453,0x18181818,0x201F6453,0x18181818,
                0x181F6453,0x18181818,0x201F1953,0x18181818,0x181F1953,0x18181818,0x181F1953,0x18181818,
                0x4F5E5E6C,0x2155676F,0x4B3A0F43,0x48382C15,0x263A3A43,0x48382C15,0x263A3A43,0x48382C15,
                0x263A3A43,0x48382C15,0x263A3A43,0x48382C15,0x263A3A43,0x48382C15,0x263A3A43,0x48382C15,
                0x66061A11,0x6B6B3456,0x092F444D,0x1D1D1D2A,0x094A5D4D,0x686A4E2A,0x094A5D4D,0x686A4E2A,
                0x094A444D,0x1D6A332A,0x092F444D,0x1D6A2A2A,0x091B444D,0x1D6A2A2A,0x091B444D,0x1D6A2A2A,
                0x5F063013,0x002F092A,0x5A2F1228,0x1C3E1C0E,0x033B1228,0x1C3E1C0E,0x032F1228,0x1C3E1C0E,
                0x032F1228,0x1C3E1C0E,0x032F1228,0x1C3E1C0E,0x5A2F1228,0x1C3E1C0E,0x5A2F1228,0x1C3E1C0E,

                0x181F1953,0x18181818,0x181F1953,0x18181818,0x52185059,0x520C5160,0x49250000,0x0B0B0B5B,
                0x470D0000,0x39023949,0x50620000,0x24396052,0x1F2D0000,0x51515220,0x1F690000,0x52521820,
                0x263A3A43,0x48382C15,0x263A3A43,0x48382C15,0x3107183F,0x4B423A3A,0x3902025B,0x18520C51,
                0x52512439,0x31501818,0x18520C51,0x3A314307,0x4318180C,0x41153A31,0x3A071818,0x48011526,
                0x091B444D,0x1D6A2A2A,0x091B444D,0x1D6A2A2A,0x3C544C40,0x466F2B2B,0x61646350,0x37272727,
                0x1E454263,0x6E4C5757,0x4A145E45,0x092A2A2A,0x09211405,0x092A2A2A,0x094A5D4D,0x092A2A2A,
                0x5A2F1228,0x1C3E1C0E,0x5A2F1228,0x1C3E1C0E,0x4865052B,0x01383817,0x31313A04,0x00003704,
                0x4B0A4540,0x0000450A,0x082E232F,0x00001C1C,0x080E232F,0x00001C1C,0x3E0E5A2F,0x00001C1C,

                0x1F690000,0x3F3F1832,0x22690000,0x3F3F1832,0x5C690000,0x18181832,0x63690000,0x18181832,
                0x63690000,0x18181832,0x63690000,0x18181832,0x63690000,0x18181832,0x63690000,0x18181832,
                0x36160718,0x4801150A,0x36160718,0x4801150A,0x6D314318,0x4858150A,0x6D311618,0x48581515,
                0x6D311618,0x48581515,0x6D311618,0x4858150A,0x6D311618,0x4858150A,0x6D311618,0x4858150A,
                0x094A5D4D,0x3D2A2A2A,0x094A5D4D,0x092A2A2A,0x094A5D4D,0x092A2A2A,0x094A5D4D,0x092A2A2A,
                0x094A5D4D,0x092A2A2A,0x094A5D4D,0x092A2A2A,0x094A5D4D,0x122A2A2A,0x094A5D4D,0x122A2A2A,
                0x3E0E5A2F,0x00001C1C,0x3E0E5A2F,0x00001C2E,0x3E0E032F,0x00001C1C,0x3E0E032F,0x00001C2E,
                0x3E0E032F,0x00001C2E,0x3E0E032F,0x00001C1C,0x3E0E5A2F,0x00001C1C,0x080E5A2F,0x00001C1C,

                0x63690000,0x18181832,0x63690000,0x18181832,0x63690000,0x18181832,0x63690000,0x18181832,
                0x63690000,0x18181832,0x63690000,0x18181832,0x63690000,0x18181832,0x63690000,0x18181832,
                0x6D311618,0x4858150A,0x6D311618,0x4858150A,0x6D311618,0x4858150A,0x6D311618,0x4801150A,
                0x6D311618,0x4801150A,0x6D311618,0x4801150A,0x6D311618,0x4801150A,0x6D311607,0x4801150A,
                0x094A444D,0x122A2A2A,0x094A444D,0x12282A2A,0x094A444D,0x12282A2A,0x094A444D,0x12282A2A,
                0x094A444D,0x12282A2A,0x092F444D,0x12282A2A,0x091B444D,0x12282A2A,0x091B144D,0x12282A2A,
                0x080E232F,0x00001C1C,0x080E232F,0x00001C1C,0x080E232F,0x00001C1C,0x080E232F,0x00001C1C,
                0x080E232F,0x00001C1C,0x082E232F,0x00001C1C,0x082E232F,0x00001C1C,0x082E232F,0x00001C1C,
        };


const unsigned int tubeExtensionTiles[512] __attribute__((aligned(4)))=
        {
                0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,
                0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,
                0x74811672,0x7B588079,0x74811672,0x7B588079,0x74811672,0x7B588079,0x74811672,0x7B588079,
                0x74811672,0x7B588079,0x74811672,0x7B588079,0x74811672,0x7B588079,0x74811672,0x7B588079,
                0x83845D75,0x76858585,0x83845D75,0x76858585,0x83845D75,0x76858585,0x83845D75,0x76858585,
                0x83845D75,0x76858585,0x83845D75,0x76858585,0x83845D75,0x76858585,0x83844475,0x76858585,
                0x08775A86,0x00001C1C,0x08775A86,0x00001C1C,0x08775A86,0x00001C1C,0x08775A86,0x00001C1C,
                0x08775A86,0x00001C1C,0x08775A86,0x00001C1C,0x08775A86,0x00001C1C,0x08772386,0x00001C1C,

                0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,
                0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,
                0x74811672,0x7B588079,0x74811672,0x7B588079,0x74811672,0x7B588079,0x74811672,0x7B588079,
                0x74811672,0x7B588079,0x74811672,0x7B588079,0x74811672,0x7B588079,0x74811672,0x7B588079,
                0x83844475,0x76858585,0x83844475,0x76858585,0x83844475,0x76858585,0x83844475,0x76858585,
                0x83844475,0x76858585,0x83844475,0x76858585,0x83844475,0x767A8585,0x83844475,0x767A8585,
                0x08772386,0x00001C1C,0x08772386,0x00001C1C,0x08772386,0x00001C1C,0x08772386,0x00001C1C,
                0x08772386,0x00001C1C,0x08772386,0x00001C1C,0x08772386,0x00001C1C,0x08772386,0x00001C1C,

                0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,
                0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,
                0x74811672,0x7B588079,0x74811672,0x7B588079,0x74811672,0x7B588079,0x74811672,0x7B588079,
                0x74811672,0x7B588079,0x74811672,0x7B588079,0x74811672,0x7B588079,0x74811672,0x7B588079,
                0x83844475,0x767A8585,0x83844475,0x767A8585,0x83844475,0x767A8585,0x83844475,0x767A8585,
                0x83844475,0x767A8585,0x83844475,0x767A8585,0x83844475,0x767A8585,0x83844475,0x767A8585,
                0x08772386,0x00001C1C,0x08772386,0x00001C1C,0x08772386,0x00001C1C,0x08772386,0x00001C1C,
                0x08772386,0x00001C1C,0x08772386,0x00001C1C,0x08772386,0x00001C1C,0x08772386,0x00001C1C,

                0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,
                0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,
                0x74811672,0x7B588079,0x74811672,0x7B588079,0x74811672,0x7B588079,0x74811672,0x7B588079,
                0x74811672,0x7B718079,0x74811672,0x7B718079,0x74811672,0x7B718079,0x74811672,0x7B718079,
                0x83844475,0x767A8585,0x83844475,0x767A8585,0x83844475,0x767A8585,0x83844475,0x767A8585,
                0x83844475,0x767A8585,0x83844475,0x767A8585,0x83844475,0x767A8585,0x83844475,0x767A8585,
                0x08772386,0x00001C1C,0x08772386,0x00001C1C,0x08772386,0x00001C1C,0x08772386,0x00001C1C,
                0x08772386,0x00001C1C,0x08772386,0x00001C1C,0x08772386,0x00001C1C,0x08772386,0x00001C1C,

                0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,
                0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,
                0x74811672,0x7B718079,0x74811672,0x7B718079,0x74811672,0x7B718079,0x74811672,0x7B718079,
                0x74811672,0x7B718079,0x74811672,0x7B718079,0x74811672,0x7B718079,0x74811672,0x7B718079,
                0x83844475,0x767A8585,0x83844475,0x767A8585,0x83844475,0x767A8585,0x83844475,0x767A8585,
                0x83844475,0x767A8585,0x83844475,0x767A8585,0x83844475,0x767A8585,0x83844475,0x767A8585,
                0x08772386,0x00001C1C,0x08772386,0x00001C1C,0x08772386,0x00001C1C,0x08772386,0x00001C1C,
                0x08772386,0x00001C1C,0x08772386,0x00001C1C,0x08772386,0x00001C1C,0x08772386,0x00001C1C,

                0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,
                0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,
                0x74811672,0x7B718079,0x74811672,0x7B718079,0x74811672,0x7B718079,0x74811672,0x7B718079,
                0x74811672,0x7B718079,0x74811672,0x7B718079,0x74811672,0x7B718079,0x74811672,0x7B718079,
                0x83844475,0x767A8585,0x83844475,0x767A8585,0x83844475,0x767A8585,0x83864475,0x767A8585,
                0x83864475,0x767A8585,0x83864475,0x767A8585,0x83864475,0x767A8585,0x83864475,0x767A8585,
                0x08772386,0x00001C1C,0x08772386,0x00001C1C,0x08772386,0x00001C1C,0x08822386,0x00001C1C,
                0x08822386,0x00001C1C,0x08822386,0x00001C1C,0x08822386,0x00001C1C,0x08822386,0x00001C1C,

                0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,
                0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,
                0x74811672,0x7B718079,0x74811672,0x7B718079,0x74811672,0x7B718079,0x74811672,0x7B718079,
                0x74811672,0x7B718079,0x74811672,0x7B718079,0x74811672,0x7B718079,0x74811672,0x7B718079,
                0x83864475,0x767A8585,0x83864475,0x767A8585,0x83734475,0x767A8585,0x83734475,0x767A8585,
                0x83734475,0x767A8585,0x83734475,0x767A8585,0x83734475,0x767A8585,0x83734475,0x767A8585,
                0x08822386,0x00001C1C,0x08822386,0x00001C1C,0x08822386,0x00001C1C,0x08822386,0x00001C1C,
                0x08822386,0x00001C1C,0x08822386,0x00001C1C,0x08822386,0x00001C1C,0x08822386,0x00001C1C,

                0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,
                0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,0x7C780000,0x7272727D,
                0x74811672,0x7B718079,0x7481167F,0x7B718079,0x7481167F,0x7B718079,0x7481167F,0x7B718079,
                0x7481167F,0x7B718079,0x7481167F,0x7B718079,0x7481167F,0x7B718079,0x7481167F,0x7B718079,
                0x83734475,0x767A8585,0x83737E75,0x767A8585,0x83737E75,0x767A8585,0x83737E75,0x767A8585,
                0x83737E75,0x767A8585,0x83737E75,0x767A8585,0x83737E75,0x767A8585,0x83737E75,0x767A8585,
                0x08822386,0x00001C1C,0x08822386,0x00001C1C,0x08822386,0x00001C1C,0x08822386,0x00001C1C,
                0x08822386,0x00001C1C,0x08822386,0x00001C1C,0x08822386,0x00001C1C,0x08822386,0x00001C1C,
        };

#endif //GBA_SPRITE_ENGINE_PROJECT_TUBE_H
