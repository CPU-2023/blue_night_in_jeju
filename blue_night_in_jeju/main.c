#include "main.h"


int main() {
	init();
	while (1) {
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			// ���ӽ���
			start();

		}
		else if (menuCode == 1) {
			// ��������
			infoDraw();
		}
		system("cls");
	}

	return 0;
}
