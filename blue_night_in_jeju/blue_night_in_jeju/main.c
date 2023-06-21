<<<<<<< HEAD:main.c
﻿#include "main.h"
#include <windows.h>
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>;

int main() {
	init();
	while (1) {

		PlaySound(TEXT("gamemusic.wav"), NULL, SND_ASYNC | SND_LOOP);

		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			start();

		}
		else if (menuCode == 1) {
			infoDraw();
		}
		system("cls");
	}

	return 0;
}
=======
#include "main.h"


int main() {
	init();
	while (1) {
		
		PlaySound(TEXT("gamemusic.wav") , NULL, SND_ASYNC | SND_LOOP);	//반복재생
		
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			// °ÔÀÓ½ÃÀÛ
			start();

		}
		else if (menuCode == 1) {
			// °ÔÀÓÁ¤º¸
			infoDraw();
		}
		system("cls");
	}

	return 0;
}
>>>>>>> 5984a707824718d4751ea760a076aea13a9b6f43:blue_night_in_jeju/main.c
