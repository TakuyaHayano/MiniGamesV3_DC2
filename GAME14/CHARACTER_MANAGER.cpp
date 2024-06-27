#include"GAME14.h"
#include"CONTAINER.h"
#include"CHARACTER.h"
#include"PLAYER.h"
#include"SALMON.h"
#include "CHARACTER_MANAGER.h"
namespace GAME14 {
    CHARACTER_MANAGER::CHARACTER_MANAGER(class GAME* game):
        GAME_OBJECT(game){

    }
    CHARACTER_MANAGER::~CHARACTER_MANAGER(){
        Player->deleteFanc();
        for (int i = 0; i < Total; i++) {
            delete Characters[i];
        }
        delete[] Characters;
    }
    void CHARACTER_MANAGER::create(){
        CharaMng = game()->container()->data().charaMng;
        Total = 0;
        Total += CharaMng.numPlayers;
        Total += CharaMng.numSalmons;
        Characters = new CHARACTER * [Total];

        Player = new PLAYER(game());
        Salmon = new SALMON(game());
        int i= 0;
        int j = 0;
        for (i = 0; i < CharaMng.numPlayers; i++) { 
            Characters[j] = Player;
            j++;
        }
        for (i = 0; i < CharaMng.numSalmons; i++) {
            Characters[j] = Salmon;
            j++;
        }
    
        for (int i = 0; i < Total; i++) {
            Characters[i]->create();
        }
    }
    void CHARACTER_MANAGER::init(){
        for (int i = 0; i < Total; i++) {
            Characters[i]->init();
        }
    }
    void CHARACTER_MANAGER::apperar(char charaId,float wx,float wy){
        for (int i = 0; i < Total; i++) {
            if (Characters[i]->charaId() == charaId) {
                if (Characters[i]->hp() <= 0) {
                    Characters[i]->appear(wx, wy);
                    break;
                }
            }
        }
    }
    void CHARACTER_MANAGER::update(){
        for (int i = 0; i < Total; i++) {
            if (Characters[i]->hp() > 0) {
                Characters[i]->update();
            }
        }
    }
    void CHARACTER_MANAGER::draw(){
        for (int i = 0; i < Total; i++) {
            if (Characters[i]->hp() > 0) {
                Characters[i]->draw();
            }
        }
    }

}