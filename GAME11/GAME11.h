#pragma once
#include "../MAIN/GAME_BASE.h"
#include"TRAMP.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#ifndef TRAMP_H
#define TRAMP_H

#define TRAMP_NUM (ONETYPE_NUM  * TRAMP_TYPE)
#define ONETYPE_NUM 13
#define TRAMP_TYPE 4

namespace GAME11
{
    class GAME :
        public GAME_BASE
    {
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void destroy();
        void Init();
        void proc();
    private:
        enum STATE { TITLE, OPERATION ,LEVEL ,PLAY, CLEAR, OVER  };
        STATE State = TITLE;

        void Title();
        void Operation();
        void Level();
        void initializeDeck(TrampSync *sync);
        void shuffleDeck(TrampSync *sync);
        void Play(TrampSync *sync);
        void Clear();
        void Over();

        //struct TrampSync* T = 0;
        
        int TitleImg = 0, BackImg = 0, DeleteImg = 0, GameclearImg = 0 ,GameOverImg = 0, RitireImg = 0, LfieldImg = 0, RfieldImg = 0, EasyImg =0,NormalImg = 0,HardImg = 0,ExpertImg = 0,
            LfieldNum = 0, RfieldNum = 0, LfieldClearCnt = 0, RfieldClearCnt = 0,
            setImg1 = 0, setImg2 = 0, setImg3 = 0, setImg4 = 0,  PickCnt = 0,DeckPrintCnt = 0, PickImage = 0, nextImage = 0,
            TrampCnt = 0, PickNum = 0, setNextImgNum = 0, FieldCheckCnt = 0, CountDownCnt = 0, FreamCnt = 0,LevelFlag = 0, RitireFlag = 0, FieldFlag = 0,
            HImg[ONETYPE_NUM] = { 0 }, DImg[ONETYPE_NUM] = { 0 }, 
            SImg[ONETYPE_NUM] = { 0 }, CImg[ONETYPE_NUM] = { 0 };
        

        float LfieldPx = 0.0f, RfieldPx = 0.0f, fieldPy = 0.0f,
            setPx1 = 0.0f, setPx2 = 0.0f, setPx3 = 0.0f, setPx4 = 0.0f, setPx = 0.0f, setPy=0.0f,
            setPy1 = 0.0f, setPy2 = 0.0f, setPy3 = 0.0f, setPy4 = 0.0f, ofstPy = 0.0f,
            setCnt[4] = { 0.0f }, setImg[4] = { 0.0f }, ArraysetPy[4] = { 0.0f }, setImgNum[4] = { 0.0f }, 
            cX = 0.0f, cY = 0.0f, cPx = 0.0f, cPy = 0.0f,
            PickPx1 = 0.0f, PickPx2 = 0.0f, PickPx3 = 0.0f, PickPx4 = 0.0f, PickPy = 0.0f, deckPx = 0.0f;
        
        TrampSync* sync = 0;
    };


}
#endif /* TRAMP_H */
