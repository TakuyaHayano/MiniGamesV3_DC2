#include "CONTAINER.h"
#include <stdlib.h>

void CONTAINER::load() {
	setData();
    loadGraphic();
}
void CONTAINER::setData() {
	Data.title.backColor = COLOR(255, 192, 203);
	Data.title.textColor = COLOR(255, 255, 255);
	Data.title.textSize0 = 200;
	Data.title.pos[0].x = 330;
	Data.title.pos[0].y = 500;
	Data.title.textSize1 = 50;
	Data.title.pos[1].x = 250;
	Data.title.pos[1].y = 800;
	strcpy_s(Data.title.str0, "Who Is This?");
	strcpy_s(Data.title.str1, "Press Enter to start the game or press Space to return");

	Data.play.pos.x = width / 2;
	Data.play.pos.y = height / 2;
    Data.play.angle = 0;
    Data.play.scale = 4;
    Data.play.t_pos.x = 400;
    Data.play.t_pos.y = 1000;
    Data.play.textColor = COLOR(255, 255, 255);
    Data.play.textSize = 50;
    strcpy_s(Data.play.str, "A:谷口愛李　B:遠藤理子　C:上村莉奈　D:澤部佑");
    
    Data.play.rectColor = COLOR(0, 0, 0);
    Data.play.r_pos.x = 775;
    Data.play.r_pos.y = 0;
    Data.play.range = 1400;
    Data.play.elevation = 1850;
    Data.play.decSpeed = 100;
}
void CONTAINER::loadGraphic() {
    Data.play.img[0] = loadImage("..\\main\\assets\\game07\\Photo\\AiriTaniguchi1.jpg");
    Data.play.img[1] = loadImage("..\\MAIN\\assets\\game07\\Photo\\AkihoOnuma1.jpg");
    Data.play.img[2] = loadImage("..\\MAIN\\assets\\game07\\Photo\\FuyukaSaito1.jpg");
    Data.play.img[3] = loadImage("..\\MAIN\\assets\\game07\\Photo\\HikariEndo1.jpg");
    Data.play.img[4] = loadImage("..\\MAIN\\assets\\game07\\Photo\\HikaruMorita1.jpg");
    Data.play.img[5] = loadImage("..\\MAIN\\assets\\game07\\Photo\\HonoTamura1.jpg");
    Data.play.img[6] = loadImage("..\\MAIN\\assets\\game07\\Photo\\ItohaMukai1.jpg");
    Data.play.img[7] = loadImage("..\\MAIN\\assets\\game07\\Photo\\KarinFujiyoshi1.jpg");
    Data.play.img[8] = loadImage("..\\MAIN\\assets\\game07\\Photo\\KiraMasumoto1.jpg");
    Data.play.img[9] = loadImage("..\\MAIN\\assets\\game07\\Photo\\MarinoKosaka1.jpg");
    Data.play.img[10] = loadImage("..\\MAIN\\assets\\game07\\Photo\\MinamiKoike1.jpg");
    Data.play.img[11] = loadImage("..\\MAIN\\assets\\game07\\Photo\\MioMatono1.jpg");
    Data.play.img[12] = loadImage("..\\MAIN\\assets\\game07\\Photo\\MiuMurayama1.jpg");
    Data.play.img[13] = loadImage("..\\MAIN\\assets\\game07\\Photo\\NagisaKojima1.jpg");
    Data.play.img[14] = loadImage("..\\MAIN\\assets\\game07\\Photo\\ReinaOdakura1.jpg");
    Data.play.img[15] = loadImage("..\\MAIN\\assets\\game07\\Photo\\ReiOsono1.jpg");
    Data.play.img[16] = loadImage("..\\MAIN\\assets\\game07\\Photo\\RenaMoriya1.jpg");
    Data.play.img[17] = loadImage("..\\MAIN\\assets\\game07\\Photo\\RikaIshimori1.jpg");
    Data.play.img[18] = loadImage("..\\MAIN\\assets\\game07\\Photo\\RikoEndo1.jpg");
    Data.play.img[19] = loadImage("..\\MAIN\\assets\\game07\\Photo\\RinaInoue1.jpg");
    Data.play.img[20] = loadImage("..\\MAIN\\assets\\game07\\Photo\\RinaMatsuda1.jpg");
    Data.play.img[21] = loadImage("..\\MAIN\\assets\\game07\\Photo\\RinaUemura1.jpg");
    Data.play.img[22] = loadImage("..\\MAIN\\assets\\game07\\Photo\\ShizukiYamashita1.jpg");
    Data.play.img[23] = loadImage("..\\MAIN\\assets\\game07\\Photo\\TenYamasaki1.jpg");
    Data.play.img[24] = loadImage("..\\MAIN\\assets\\game07\\Photo\\YuiKobayashi1.jpg");
    Data.play.img[25] = loadImage("..\\MAIN\\assets\\game07\\Photo\\YuiTakemoto1.jpg");
    Data.play.img[26] = loadImage("..\\MAIN\\assets\\game07\\Photo\\YuMurai1.jpg");
    Data.play.img[27] = loadImage("..\\MAIN\\assets\\game07\\Photo\\YuzukiNakashima1.jpg");
}
void CONTAINER::init() {
       //配列の末尾
    
    k = NUM - 1;

    while (k > 0) {
    	//シャッフル対象をランダムに決定
    	srand(time(NULL));
    	l = rand() % k;
    	//ランダムに決めた位置と末尾を交換
    	if (l == 0) {
    		 Data.play.img[l] = Data.play.img[l];
    	}
    	else {
            tmp = Data.play.img[l];
            Data.play.img[l] = Data.play.img[k];
            Data.play.img[k] = tmp;
    	}
    	k--;
    }
}