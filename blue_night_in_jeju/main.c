#include "main.h"


int main() {
	init();
	while (1) {
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			// 게임시작
			start();

		}
		else if (menuCode == 1) {
			// 게임정보
			infoDraw();
		}
		system("cls");
	}

	return 0;
}
