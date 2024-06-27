#pragma once
#include "GAME_OBJECT.h"
namespace GAME14 {
    class CHARACTER_MANAGER :
        public GAME_OBJECT{
    public:
        struct DATA {
            int numPlayers = 0;
            int numSalmons = 0;
        };
    private:
        int Total = 0;
        DATA CharaMng ;
        class CHARACTER** Characters = nullptr;
        class PLAYER* Player = nullptr;
        class SALMON* Salmon = nullptr;
    public:
        CHARACTER_MANAGER(class GAME* game);
        ~CHARACTER_MANAGER();
        void create();
        void init();
        void apperar(char charaId,float wx,float wy);
        void update();
        void draw();
        class PLAYER* player() { return Player; }
        class SALMON* salmon() { return Salmon; }
    };
}

