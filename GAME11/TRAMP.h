#pragma once
namespace GAME11 {
    struct TRAMP {
        int num;
        char suit;
        int img;
    };
    typedef struct {
        struct TRAMP Deck[52];
    }TrampSync;
}