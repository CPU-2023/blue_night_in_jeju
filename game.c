#include "game.h"


int keyControl() {
    char temp = _getch();

    if (temp == 'w' || temp == 'W') {
        return UP;
    }
    else if (temp == 'a' || temp == 'A') {
        return LEFT;
    }
    else if (temp == 's' || temp == 'S') {
        return DOWN;
    }
    else if (temp == 'd' || temp == 'D') {
        return RIGHT;
    }
    else if (temp == ' ') {
        return SUBMIT;
    }
}

void titleDraw() {
    int x = 17, y = 3;


    gotoxy(x, y++); printf(" _______  ___      __   __  _______    __    _  ___   _______  __   __  _______");
    gotoxy(x, y++); printf("|  _    ||   |    |  | |  ||       |  |  |  | ||   | |       ||  | |  ||       |");
    gotoxy(x, y++); printf("| |_|   ||   |    |  | |  ||    ___|  |   |_| ||   | |    ___||  |_|  ||_     _|");
    gotoxy(x, y++); printf("|       ||   |    |  |_|  ||   |___   |       ||   | |   | __ |       |  |   |");
    gotoxy(x, y++); printf("|  _   | |   |___ |       ||    ___|  |  _    ||   | |   ||  ||       |  |   |");
    gotoxy(x, y++); printf("| |_|   ||       ||       ||   |___   | | |   ||   | |   |_| ||   _   |  |   | ");
    gotoxy(x, y++); printf("|_______||_______||_______||_______|  |_|  |__||___| |_______||__| |__|  |___| ");

    gotoxy(x, y++); printf("		 ___   __    _        ___  _______      ___  __   __             ");
    gotoxy(x, y++); printf("		|   | |  |  | |      |   ||       |    |   ||  | |  |      ");
    gotoxy(x, y++); printf("		|   | |   |_| |      |   ||    ___|    |   ||  | |  |          ");
    gotoxy(x, y++); printf("		|   | |       |      |   ||   |___     |   ||  |_|  |       ");
    gotoxy(x, y++); printf("		|   | |  _    |   ___|   ||    ___| ___|   ||       |     ");
    gotoxy(x, y++); printf("		|   | | | |   |  |       ||   |___ |       ||       |     ");
    gotoxy(x, y++); printf("		|___| |_|  |__|  |_______||_______||_______||_______|   ");




    x = 17, y = 17;
    gotoxy(x, y);

}

void init() {
    system("mode con:cols=120 lines=30 | title Snake Game");

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);

}

void infoDraw() {
    int x = 25, y = 5;
    system("cls");
    printf("\n\n");


    gotoxy(x, y++); printf("========================= [�����۹���]=========================");
    // gotoxy(x, y++); printf("|															  |");
    gotoxy(x, y++);
    gotoxy(x, y++); printf("            �̵� : W, S, A, D(��, �Ʒ�, ����, ������)         ");
    gotoxy(x, y++); printf("			���� : �����̽���                                 ");
    gotoxy(x, y++); printf("	    �����̽��ٸ� ������ ����ȭ������ �̵��մϴ�.		  ");
    gotoxy(x, y++);
    gotoxy(x, y++); printf("===============================================================");
    gotoxy(x, y++);

    gotoxy(x, y++); printf("========================[ ������ �����]=======================");
    // gotoxy(x, y++); printf("|															   |");
    gotoxy(x, y++);
    gotoxy(x, y++); printf("   		        ���� ������ �׾��!   		   	              ");
    gotoxy(x, y++); printf("	             ���� 5������ ������ ����!                     ");
    gotoxy(x, y++); printf("	  �����̽��ٸ� ������ ����ȭ������ �̵��մϴ�.	    	  ");
    gotoxy(x, y++);
    gotoxy(x, y++); printf("===============================================================");
    gotoxy(x, y++);
    // gotoxy(x, y++); printf("		    [ Developed by : ��μ� / ���� / �輭�� ]		   ");



    while (1) {
        if (keyControl() == SUBMIT) {
            break;
        }
    }
}

int menuDraw() {
    int x = 53, y = 20;
    gotoxy(x - 2, y); printf("> �� �� �� ��");
    gotoxy(x, y + 1); printf("�� �� �� ��");
    gotoxy(x, y + 2); printf("�� �� �� ��");

    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 20) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }

        case DOWN: {
            if (y < 22) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            return y - 20;
        }
        }
    }


}

void gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}






//�����̸� ������ ���߿��Ḯ��Ʈ ����ü
#pragma pack(push,1)
typedef struct _WORM
{
    int x;   //x��ǥ
    int y;   //y��ǥ
    char direction;   //�������
    struct _WORM* next;   //��������ּ�
    struct _WORM* before;//��������ּ�
}WORM, * pWORM;

//�������� ������ ���Ͽ��Ḯ��Ʈ ����ü
typedef struct _ITEM
{
    int x;
    int y;
    int itemType;
    int itemNo;
    struct _ITEM* next;
}ITEM, * pITEM;
#pragma pack(pop)

//Ŀ���� ���� ��ǥ�� �̵�
/*
void gotoxy(int x, int y)
{
    COORD Pos;
    Pos.X = x + LEFT_MARGIN;//���μ��� ������ ���߱� ���ؼ� ������ ��ǥ�� 2��
    Pos.Y = y + TOP_MARGIN;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
*/

//���ӿ������
void PrintField()
{
    for (int i = 1; i < FIELD_WIDTH; i++)
    {
        gotoxy(i, 0);
        printf("��");
        gotoxy(i, FIELD_HEIGHT);
        printf("��");
    }

    for (int i = 1; i < FIELD_HEIGHT; i++)
    {
        gotoxy(0, i);
        printf("��");
        gotoxy(FIELD_WIDTH, i);
        printf("��");
    }
    gotoxy(0, 0);
    printf("��");
    gotoxy(0, FIELD_HEIGHT);
    printf("��");
    gotoxy(FIELD_WIDTH, 0);
    printf("��");
    gotoxy(FIELD_WIDTH, FIELD_HEIGHT);
    printf("��");
}

//�����̸� �ø��� �Լ�(���߿��Ḯ��Ʈ�� �����ʿ� ��� �߰�)
void AddWorm(pWORM wormTailNode)
{
    pWORM newNode = malloc(sizeof(WORM));
    pWORM temp = wormTailNode->next;

    //�� ����� �ּڰ� �̾��ֱ�;
    newNode->before = wormTailNode;
    newNode->next = wormTailNode->next;
    wormTailNode->next = newNode;
    newNode->next->before = newNode;
    newNode->direction = temp->direction;
    newNode->x = temp->x;
    newNode->y = temp->y;
    switch (temp->direction)
    {
    case LEFT:
        newNode->x = newNode->x + 1;
        break;
    case RIGHT:
        newNode->x = newNode->x - 1;
        break;
    case UP:
        newNode->y = newNode->y + 1;
        break;
    case DOWN:
        newNode->y = newNode->y - 1;
        break;
    default:
        break;
    }


}

//���Ḯ��Ʈ�� �޾Ƽ� ������ ���
void PrintWorm(pWORM wormTailNode, pWORM wormHeadNode)
{
    pWORM curr = wormTailNode->next;
    while (curr != wormHeadNode)
    {
        gotoxy(curr->x, curr->y);
        printf("O");
        curr = curr->next;
    }
}

//�������� ���
void PrintScore(int score)
{
    gotoxy(FIELD_WIDTH + 3, 3);
    printf("Score : %d��", score);
    gotoxy(FIELD_WIDTH + 3, 5);
    printf("�����Ϸ��� Q�� ��������");
    gotoxy(FIELD_WIDTH + 3, 7);
    printf("������ ȭ��ǥŰ��");
}

//���� ������ �ڸ� �����
void ClearWorm(int x, int y)
{
    gotoxy(x, y);
    printf(" ");
}

//�� �����̱� 
void MoveSnake(pWORM wormTailNode, pWORM wormHeadNode)
{
    pWORM curr;

    curr = wormTailNode->next;
    while (curr != NULL && curr != wormHeadNode->before)
    {
        curr->x = curr->next->x;
        curr->y = curr->next->y;
        curr = curr->next;
    }
    curr = wormHeadNode->before;
    if (curr->direction == LEFT)
    {
        curr->x--;
    }
    else if (curr->direction == RIGHT)
    {
        curr->x++;
    }
    else if (curr->direction == UP)
    {
        curr->y--;
    }
    else if (curr->direction == DOWN)
    {
        curr->y++;
    }
}


//�� ����Ʈ�� �Ҵ�� �޸𸮸� ������ ����
void FreeWormList(pWORM wormTailNode)
{
    pWORM curr;
    pWORM temp;
    curr = wormTailNode;
    while (curr != NULL)
    {
        temp = curr->next;
        free(curr);
        curr = temp;
    }
}

//item �߻���Ű��
void CreateItem(pITEM itemNode, int* itemNo) {

    pITEM newItem = malloc(sizeof(ITEM));

    newItem->next = itemNode->next;
    newItem->itemNo = (*itemNo)++;
    itemNode->next = newItem;
    newItem->x = 3 + rand() % (FIELD_WIDTH - 3);
    newItem->y = 3 + rand() % (FIELD_HEIGHT - 3);
    newItem->itemType = ITEM_EXP;
}

//������ ȭ�鿡 ���
void PrintItem(pITEM itemNode)
{
    pITEM curr = itemNode->next;
    while (curr != NULL)
    {
        gotoxy(curr->x, curr->y);
        printf("@");
        curr = curr->next;
    }
}

//����Ʈ���� itemNo�� ��ġ�� ã�Ƽ� ī���͸� ����
int findItemNoInList(pITEM itemNode, int itemNo)
{
    int numberOfNode = 0;   //����ȣ�� ������ ����

    pITEM curr;      //�����̸� ������ ������
    curr = itemNode->next;      //ù��° �����͸� ����Ű�� �ּҸ� curr�� �Ҵ�

    while (curr != NULL)   //�ݺ����� �����鼭 ã�� �����͸� �߰��ϸ� ����ȣ�� ����
    {
        numberOfNode++;
        if (itemNo == curr->itemNo)
        {
            return numberOfNode;
        }
        curr = curr->next;
    }

    return numberOfNode;
}


//�������� ����ȣ�� �޾� �� ��ȣ�� ��带 ����
void delItemFromList(pITEM itemNode, int targetNodeNumber)
{
    pITEM beforeTarget;      //������ ����� �ճ��
    pITEM target;      //������ ���

    int counter = 0;

    beforeTarget = itemNode;

    if (targetNodeNumber < 0)   // 0�� �ԷµǸ� FirstNode�� �����ϱ� ������ �������� �ʰ� ����
        return 0;

    //��带 targetNodeNumber-1 ��ŭ �̵����Ѽ� beforeTarget�� ������ ��� ������ �̵���Ŵ
    while (counter < targetNodeNumber - 1)
    {
        beforeTarget = beforeTarget->next;
        counter = counter + 1;
    }

    //��带 ����Ʈ���� ����
    target = beforeTarget->next;
    beforeTarget->next = target->next;
    free(target);
}

//������(�����)�� ���� ��尡 �������� �˻�, 
//delItemNo�� ���� �������� ����� �Լ��� �Ѱ��� ����
int CheckItemHit(pWORM wormHeadPointer, pITEM itemNode, int* delItemNo)
{
    pITEM curr;
    int nodeNo = 0;
    curr = itemNode->next;
    while (curr != NULL)
    {
        if (wormHeadPointer->x == curr->x && wormHeadPointer->y == curr->y)
        {
            if (curr->itemType == ITEM_EXP)
            {
                *delItemNo = curr->itemNo;
                return 1; //������ ������ 1����
            }
        }
        nodeNo++;
        curr = curr->next;
    }
    return 0;//�������� �ȸ����� 0
}

//�������� ��ũ�� ����Ʈ �޸� ����
void FreeItemList(pITEM itemNode)
{
    pITEM curr;
    pITEM temp;
    curr = itemNode;
    while (curr != NULL)
    {
        temp = curr->next;
        free(curr);
        curr = temp;
    }
}

//����� �׽�Ʈ������ ����� ���� ������ ���� ����Ʈ ����Լ�
/*
void PrintItemList(pITEM itemNode)
{
   pITEM curr;
   curr = itemNode->next;
   gotoxy( -LEFT_MARGIN, 2);
   while (curr != NULL)
   {
      printf("�����۹�ȣ : %d\n", curr->itemNo);
      curr = curr->next;
   }
}
*/
int start()
{
    pWORM wormHeadNode = malloc(sizeof(WORM));//���߿��Ḯ��Ʈ �����
    pWORM wormTailNode = malloc(sizeof(WORM));//���߿��Ḯ��Ʈ ���ϳ��
    pWORM addWorm = malloc(sizeof(WORM));//ù��° ������
    pITEM itemNode = malloc(sizeof(ITEM));//�����ۿ� ���� ���Ḯ��Ʈ


    wormHeadNode->next = NULL;
    wormHeadNode->before = addWorm;
    addWorm->next = wormHeadNode;
    addWorm->before = wormTailNode;
    addWorm->x = FIELD_WIDTH / 2;
    addWorm->y = FIELD_HEIGHT / 2;
    addWorm->direction = RIGHT;
    wormTailNode->next = addWorm;
    wormTailNode->before = NULL;

    itemNode->next = NULL;
    itemNode->itemNo = -1;

    //������ ���ӽ��� ������ ����
    for (int i = 9; i > 0; i--)
        AddWorm(wormTailNode);

    //���� �Ӹ��� ����Ű�� ������
    pWORM wormHeadPointer = addWorm;

    int score = 0;         //��������
    int itemCounter = 0;   //������ ���� �ѵ� ī����
    char key;            //Ű�Է¹��� ����
    int delItemNo = 0;      //��������۳ѹ��� ���� �����ʱ�ȭ
    int itemNo = 10000;//�������� ���ʹ�ȣ

    //������ ���� ��ġ ���� �õ�
    srand((unsigned int)time(NULL));

    system("cls");   //ȭ�������
    PrintField();   //�ʵ� ���


    while (1)
    {
        //�׽�Ʈ�� ��ºκ�
        //gotoxy(-LEFT_MARGIN, 0);
        //printf("���� ������ : %d\n",delItemNo);
        //PrintItemList(itemNode);

        if (_kbhit() != 0)
        {

            key = _getch();
            if (key == 'q' || key == 'Q')
            {
                printf("%c", key);
                break;
            }
            if (key == LEFT && wormHeadPointer->direction != RIGHT)
            {
                wormHeadPointer->direction = LEFT;
            }
            else if (key == RIGHT && wormHeadPointer->direction != LEFT)
            {
                wormHeadPointer->direction = RIGHT;
            }
            else if (key == UP && wormHeadPointer->direction != DOWN)
            {
                wormHeadPointer->direction = UP;
            }
            else if (key == DOWN && wormHeadPointer->direction != UP)
            {
                wormHeadPointer->direction = DOWN;
            }
        }

        //�� ������ �ڸ� �����
        ClearWorm(wormTailNode->next->x, wormTailNode->next->y);

        //�� ��ĭ�� �����̱�
        MoveSnake(wormTailNode, wormHeadNode);

        if (score >= 600) {
            system("cls");
            gotoxy(FIELD_WIDTH + 5, FIELD_HEIGHT + 5);
            printf("\n");
            printf("		 __    _  _______  _______  ______   ___      _______  _______ \n");
            printf("		|  |  | ||       ||       ||      | |   |    |       ||       |\n");
            printf("		|   |_| ||   _   ||   _   ||  _    ||   |    |    ___||  _____|\n");
            printf("		|       ||  | |  ||  | |  || | |   ||   |    |   |___ | |_____ \n");
            printf("		|  _    ||  |_|  ||  |_|  || |_|   ||   |___ |    ___||_____  |\n");
            printf("		| | |   ||       ||       ||       ||       ||   |___  _____| |\n");
            printf("		|_|  |__||_______||_______||______| |_______||_______||_______|\n");

            printf("		 _______  ______    _______    ______   _______  __    _  _______ \n");
            printf("		|   _   ||    _ |  |       |  |      | |       ||  |  | ||       |\n");
            printf("		|  |_|  ||   | ||  |    ___|  |  _    ||   _   ||   |_| ||    ___|\n");
            printf("		|       ||   |_||_ |   |___   | | |   ||  | |  ||       ||   |___ \n");
            printf("		|       ||    __  ||    ___|  | |_|   ||  |_|  ||  _    ||    ___|\n");
            printf("		|   _   ||   |  | ||   |___   |       ||       || | |   ||   |___ \n");
            printf("		|__| |__||___|  |_||_______|  |______| |_______||_|  |__||_______|\n");
            printf("");
            FreeWormList(wormTailNode);
            FreeItemList(itemNode);
            return 0;
        }
        //���� �ε����� ���ӿ���
        if (wormHeadPointer->x == 0 || wormHeadPointer->x == FIELD_WIDTH || wormHeadPointer->y == 0 || wormHeadPointer->y == FIELD_HEIGHT)
        {
            system("cls");
            gotoxy(FIELD_WIDTH + 5, FIELD_HEIGHT + 5);
            printf("\n");
            printf("			 _______  _______  __   __  _______    _______  __   __  _______  ______ \n");
            printf("			|       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |\n");
            printf("			|    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||\n");
            printf("			|   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_\n");
            printf("			|   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  |\n");
            printf("			|   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | |\n");
            printf("			|_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_|\n");
            printf("						���� �ε������ϴ�.");
            FreeWormList(wormTailNode);
            FreeItemList(itemNode);
            return 0;
        }

        //�������� ����
        while (itemCounter < ITEM_MAX)
        {
            CreateItem(itemNode, &itemNo);
            itemCounter++;
        }

        //������ �Ծ����� Ȯ��
        if (CheckItemHit(wormHeadPointer, itemNode, &delItemNo))
        {
            AddWorm(wormTailNode);
            delItemFromList(itemNode, findItemNoInList(itemNode, delItemNo));
            score += 100;
            itemCounter--;
        }
        PrintItem(itemNode);
        PrintWorm(wormTailNode, wormHeadNode);
        PrintScore(score);
        Sleep(DELAYTIME);
    }

    FreeWormList(wormTailNode);
    FreeItemList(itemNode);

    return 0;
}


