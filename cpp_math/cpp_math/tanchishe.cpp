#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
#include <conio.h>
#include<time.h>

#define WIDE  60
#define HIGH  20

typedef struct _body //蛇的身体
{
	int x;
	int y;
} BODY;

typedef struct snake
{
	BODY list[WIDE * HIGH];//身体的每一节都是BODY类型
	int size;//蛇的身体的大小
	BODY food;//食物的坐标
	COORD coord;//光标的位置信息
	int dx;//蛇x轴移动的方向
	int dy;//蛇y轴移动的方向
	int score;//得分
	BODY tail;

} SNAKE;

void init_ui()
{
	for (int i = 0; i < HIGH; i++)
	{
		for (int j = 0; j < WIDE; j++)
		{
			printf("#");
		}
		printf("\n");
	}
}

void init_food(SNAKE* snake)
{
	srand(time(NULL));//设置随机种子
	//初始化食物坐标
	snake->food.x = rand() % WIDE;
	snake->food.y = rand() % HIGH;
}

void init_snake(SNAKE* snake)
{
	//初始化蛇头坐标
	snake->list[0].x = WIDE / 2;
	snake->list[0].y = HIGH / 2;
	//初始化蛇尾坐标
	snake->list[1].x = WIDE / 2 - 1;
	snake->list[1].y = HIGH / 2;
	//初始化蛇的身体大小
	snake->size = 2;
	//初始化 食物的坐标
	init_food(snake);
	//初始化蛇的移动方向
	snake->dx = 1;
	snake->dy = 0;
	//初始化数据
	snake->score = 0;
}


void show_ui(SNAKE* snake)
{
	//显示蛇
	for (int i = 0; i < snake->size; i++)
	{
		snake->coord.X = snake->list[i].x;
		snake->coord.Y = snake->list[i].y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
		if (0 == i)
		{
			printf("@");
		}
		else
		{
			printf("*");
		}
	}
	//显示食物
	snake->coord.X = snake->food.x;
	snake->coord.Y = snake->food.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord); \
		printf("#");
	//将原来的尾巴的位置显示为空格
	snake->coord.X = snake->tail.x;
	snake->coord.Y = snake->tail.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf(" ");
}

void move_snake(SNAKE* snake)
{
	//记录尾巴的坐标
	snake->tail.x = snake->list[snake->size - 1].x;
	snake->tail.y = snake->list[snake->size - 1].y;
	//更新蛇的身体坐标,除蛇头
	for (int i = snake->size - 1; i > 0; i--)
	{
		snake->list[i] = snake->list[i - 1];//将数组的前一个元素的坐标给后一节
	}
	//更新蛇头

	snake->list[0].x += snake->dx;
	snake->list[0].y += snake->dy;
}

void control_snake(SNAKE* snake)
{
	char  key = 0;
	while (_kbhit()) //判断是否按下按键,按下不等于0 
	{
		key = _getch();
		switch (key)
		{
		case 'a':
			snake->dx = -1;
			snake->dy = 0;
			break;
		case 'w':
			snake->dx = 0;
			snake->dy = -1;
			break;
		case 's':
			snake->dx = 0;
			snake->dy = 1;
			break;
		case 'd':
			snake->dx = 1;
			snake->dy = 0;
			break;
		}
	}
}

void game_end(SNAKE* snake)
{
	snake->coord.X = 25;
	snake->coord.Y = 25;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf("游戏结束 得分为%d\n", snake->score);
	Sleep(3000);
	exit(0);//退出进程
}

//咬到自己
void snake_eat_body(SNAKE* snake)
{
	//如果蛇头和蛇的身体的任意一节身体坐标相同,则吃到自己身体
	for (int i = 1; i < snake->size; i++)
	{
		if (snake->list[0].x == snake->list[i].x &&
			snake->list[0].y == snake->list[i].y)
		{
			game_end(snake);
		}
	}
}

void snake_eat_food(SNAKE* snake)
{
	//如果蛇头和食物的坐标重合.则吃到了食物
	if (snake->list[0].x == snake->food.x &&
		snake->list[0].y == snake->food.y)
	{

		//原食物消失,生成新的食物
		init_food(snake);
		//蛇的身体增长一节
		snake->size++;
		//分数增加
		snake->score += 10;
	}
}

void init_wall()
{
	for (int i = 0; i <= HIGH; i++)
	{
		for (int j = 0; j <= WIDE; j++)
		{
			if (i == HIGH || j == WIDE)
			{
				printf("+");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void start_game(SNAKE* snake)
{
	while (snake->list[0].x < WIDE && snake->list[0].x >= 0 &&
		snake->list[0].y < HIGH && snake->list[0].y >= 0)
	{
		//控制蛇的方向
		control_snake(snake);
		//更新蛇的坐标
		move_snake(snake);
		//蛇移动
		//system("cls");//清屏
		//init_wall();
		show_ui(snake);
		//蛇是否碰到自己
		snake_eat_body(snake);
		//蛇是否碰到食物-(碰到食物,原食物消失,产生新的食物)
		snake_eat_food(snake);
		Sleep(100);//延时0.5s
	}
	game_end(snake);
}

void hide_cur()
{
	//隐藏控制台光标
	CONSOLE_CURSOR_INFO  cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

int main()
{
	hide_cur();
	init_wall();
	//申请蛇的结构体
	SNAKE* snake = (SNAKE*)malloc(sizeof(SNAKE));
	init_snake(snake);
	show_ui(snake);
	start_game(snake);
	system("pause");
	return 0;
}
