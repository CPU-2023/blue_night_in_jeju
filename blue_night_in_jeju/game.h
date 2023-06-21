#include "main.h"

#ifndef KEY_CODE
#define KEY_CODE

//Ű���� ��
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define ENTER 13			//ENTER 

#endif
#define FIELD_WIDTH 50   //�ʵ尡�α���
#define FIELD_HEIGHT 25   //�ʵ弼�α���
#define LEFT 75         //Ű���� �� ȭ��ǥ�� char��
#define RIGHT 77      //Ű���� ��
#define UP 72         //Ű���� ��
#define DOWN 80         //������ �Ʒ�
#define ITEM_MAX 2      //ȭ�鿡 ǥ�õǴ� �����۰���
#define ITEM_GOLD 101   //��� ������ �ε�������
#define ITEM_EXP 102   //����ġ ������ �ε�������
#define LEFT_MARGIN 30   //ȭ����ʸ���(����)
#define TOP_MARGIN 3   //ȭ�� ��ܸ���(����)
#define DELAYTIME 200   //Sleep�Լ��� �� x/1000 ��


void gLoop(int);
int keyControl();
void titleDraw();
void init();
void infoDraw();
int menuDraw();
void gotoxy(int x, int y);
void textcolor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

enum ColorType {
	BLACK,  	//0
	darkBLUE,	//1
	DarkGreen,	//2
	darkSkyBlue,    //3
	DarkRed,  	//4
	DarkPurple,	//5
	DarkYellow,	//6
	GRAY,		//7
	DarkGray,	//8
	BLUE,		//9
	GREEN,		//10
	SkyBlue,	//11
	RED,		//12
	PURPLE,		//13
	YELLOW,		//14
	WHITE,//15
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
} COLOR;

