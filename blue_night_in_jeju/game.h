#include "main.h"

#ifndef KEY_CODE
#define KEY_CODE

//키보드 값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define ENTER 13			//ENTER 

#endif
#define FIELD_WIDTH 50   //필드가로길이
#define FIELD_HEIGHT 25   //필드세로길이
#define LEFT 75         //키보드 좌 화살표의 char값
#define RIGHT 77      //키보드 우
#define UP 72         //키보드 위
#define DOWN 80         //지보드 아래
#define ITEM_MAX 2      //화면에 표시되는 아이템개수
#define ITEM_GOLD 101   //골드 아이템 인디케이터
#define ITEM_EXP 102   //경험치 아이템 인디케이터
#define LEFT_MARGIN 30   //화면왼쪽마진(공백)
#define TOP_MARGIN 3   //화면 상단마진(공백)
#define DELAYTIME 200   //Sleep함수에 들어갈 x/1000 초


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

