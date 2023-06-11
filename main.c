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
		else if (menuCode == 2) {
			// 게임 종료
			return 0;
		}
		system("cls");
	}

	return 0;
}
