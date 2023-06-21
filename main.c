#include "main.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

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
