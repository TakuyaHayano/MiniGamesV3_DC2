#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class SOUNDMNG :
        public GAME_OBJECT
    {
    public:
        enum SOUND_EFFECT {
            DROP,
            STICK,
            NUM_SOUND_EFFECT
        };
        struct DATA {
            int soundEffects[NUM_SOUND_EFFECT];
            int bgm;
        };
    private:
        DATA SoundMNG;
    public:
        SOUNDMNG(class GAME* game);
        ~SOUNDMNG();
        void create();

        void playSE(SOUND_EFFECT id);
        void loopBGM();
    };
}
