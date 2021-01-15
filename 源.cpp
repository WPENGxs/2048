#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_NONSTDC_NO_DEPRECATE
#include "stdio.h"
#include "stdlib.h"
#include "Windows.h"
#include "conio.h"
#include "time.h"
int game[4][4];
int game_over=1;
void round()//游戏主体绘制
{
	int x, y;
	printf("*****************************************\n");
	printf("2048\n");
	for (y = 0; y <= 20; y++)
	{
		for (x = 0; x <= 40; x++)
		{
			if (y == 0 || y == 20 || x == 0 || x == 40) printf("#");//边界的绘制
			else if (y == 3)
			{
				if (x == 5) 
				{ 
					if (game[0][0] == 0) printf(" ");
					else printf("%d", game[0][0]); 
				}
				if (x == 14)
				{
					if (game[1][0] == 0) printf(" ");
					else printf("%d", game[1][0]);
				}
				if (x == 23) 
				{
					if (game[2][0] == 0) printf(" ");
					else printf("%d", game[2][0]);
				}
				if (x == 32) 
				{
					if (game[3][0] == 0) printf(" ");
					else printf("%d", game[3][0]);
				}
				else printf(" ");
			}
			else if (y == 8)
			{
				if (x == 5) 
				{
					if (game[0][1] == 0) printf(" ");
					else printf("%d", game[0][1]);
				}
				if (x == 14) 
				{
					if (game[1][1] == 0) printf(" ");
					else printf("%d", game[1][1]);
				}
				if (x == 23) 
				{
					if (game[2][1] == 0) printf(" ");
					else printf("%d", game[2][1]);
				}
				if (x == 32) 
				{
					if (game[3][1] == 0) printf(" ");
					else printf("%d", game[3][1]);
				}
				printf(" ");
			}
			else if (y == 13)
			{
				if (x == 5) 
				{
					if (game[0][2] == 0) printf(" ");
					else printf("%d", game[0][2]);
				}
				if (x == 14) 
				{
					if (game[1][2] == 0) printf(" ");
					else printf("%d", game[1][2]);
				}
				if (x == 23) 
				{
					if (game[2][2] == 0) printf(" ");
					else printf("%d", game[2][2]);
				}
				if (x == 32) 
				{
					if (game[3][2] == 0) printf(" ");
					else printf("%d", game[3][2]);
				}
				printf(" ");
			}
			else if (y == 18)
			{
				if (x == 5) 
				{
					if (game[0][3] == 0) printf(" ");
					else printf("%d", game[0][3]);
				}
				if (x == 14) 
				{
					if (game[1][3] == 0) printf(" ");
					else printf("%d", game[1][3]);
				}
				if (x == 23) 
				{
					if (game[2][3] == 0) printf(" ");
					else printf("%d", game[2][3]);
				}
				if (x == 32) 
				{
					if (game[3][3] == 0) printf(" ");
					else printf("%d", game[3][3]);
				}
				printf(" ");
			}
			else if (y % 5 == 0||x % 10 == 0) printf("#");//内方框的绘制
			else printf(" ");
		}
		printf("\n");
	}
	printf("游戏控制: w/W:上; s/S:下; a/A:左; d/D:右;\n");
	printf("游玩时请将输入法切至英文或大写\n");
	if (game_over == 0) printf("游戏结束，请关闭游戏，下次努力！\n");
	if (game_over == 2) printf("游戏成功，请关闭游戏，谢谢体验！\n");
}
void control(char d)//控制输入并相加
{
	int i, j, t;
	if (d == 'l')
	{
		for (j = 0; j <= 3; j++)
			for (t = 0; t < 4; t++)
			{
				for (i = 0; i + 1 < 4; i++)
				{
					if (game[i][j] == 0)
					{
						game[i][j] = game[i + 1][j]; game[i + 1][j] = 0;
					}
				}
			}
		for(j=0;j<=3;j++)
			for (i = 0; i + 1 < 4; i++)
			{
				if (game[i][j] == game[i + 1][j])
				{
					game[i][j] = game[i][j] + game[i + 1][j];
					game[i + 1][j] = 0;
				}
			}
		for(j=0;j<=3;j++)
			for (t = 0; t < 4; t++)
			{
				for (i = 0; i+1 < 4; i++)
				{
					if (game[i][j] == 0)
					{
						game[i][j] = game[i + 1][j]; game[i + 1][j] = 0;
					}
				}
			}
	}
	if (d == 'r')
	{
		for (j = 0; j <= 3; j++)
			for (t = 0; t < 4; t++)
			{
				for (i = 0; i + 1 < 4; i++)
				{
					if (game[i + 1][j] == 0)
					{
						game[i + 1][j] = game[i][j]; game[i][j] = 0;
					}
				}
			}
		for (j = 0; j <= 3; j++)
			for (i = 0; i + 1 < 4; i++)
			{
				if (game[i+1][j] == game[i][j])
				{
					game[i+1][j] = game[i+1][j] + game[i][j];
					game[i][j] = 0;
				}
			}
		for (j = 0; j <=3; j++)
			for (t = 0; t < 4; t++)
			{
				for (i = 0; i + 1 < 4; i++)
				{
					if (game[i+1][j] == 0)
					{
						game[i+1][j] = game[i][j]; game[i][j] = 0;
					}
				}
			}
	}
	if (d == 'u')
	{
		for (i = 0; i <= 3; i++)
			for (t = 0; t < 4; t++)
			{
				for (j = 0; j + 1 < 4; j++)
				{
					if (game[i][j] == 0)
					{
						game[i][j] = game[i][j + 1]; game[i][j + 1] = 0;
					}
				}
			}
		for(i=0;i<=3;i++)
			for (j = 0; j + 1 < 4; j++)
			{
				if (game[i][j]== game[i][j + 1])
				{
					game[i][j] = game[i][j] + game[i][j + 1];
					game[i][j + 1] = 0;
				}
			}
		for (i = 0; i<=3; i++)
			for (t = 0; t < 4; t++)
			{
				for (j = 0; j + 1 < 4; j++)
				{
					if (game[i][j] == 0)
					{
						game[i][j] = game[i][j+1]; game[i][j+1] = 0;
					}
				}
			}
	}
	if (d == 'd')
	{
		for (i = 0; i <= 3; i++)
			for (t = 0; t < 4; t++)
			{
				for (j = 0; j + 1 < 4; j++)
				{
					if (game[i][j + 1] == 0)
					{
						game[i][j + 1] = game[i][j]; game[i][j] = 0;
					}
				}
			}
		for (i = 0; i <= 3; i++)
			for (j = 0; j + 1 < 4; j++)
			{
				if (game[i][j+1] == game[i][j])
				{
					game[i][j+1] = game[i][j+1] + game[i][j];
					game[i][j] = 0;
				}
			}
		for (i = 0; i <=3; i++)
			for (t = 0; t < 4; t++)
			{
				for (j = 0; j + 1 < 4; j++)
				{
					if (game[i][j+1] == 0)
					{
						game[i][j+1] = game[i][j]; game[i][j] = 0;
					}
				}
			}
	}
}
void random_xy()//产生随机位置的随机数
{
	int d,g,i,j;
	srand((unsigned)time(NULL));//随机数以时间为种子
	d=rand()%2;//产生一个0-1的随机整数
	if (d == 0) g = 2;
	else if (d == 1) g = 4;
	i = rand() % 4;
	j = rand() % 4;
	while(game[i][j]!=0)
	{
		i = rand() % 4;
		j = rand() % 4;
	}
	game[i][j] = g;
}
int over()//判断游戏是否结束
{
	int i, j, o=0;
    for(i=0;i<4;i++)
		for (j = 0; j < 4; j++)
		{
			if (game[i][j] == 0) o = 1;
			if (game[i][j] == 2048) o = 2;
		}
	return o;
}
int main()
{
	round();
	while (1)
	{
		char input,dir;
		if (kbhit())
		{
			system("cls");//清屏函数
			input = getch();
			if (input == 'a' || input == 'A') dir='l';//向左
			if (input == 'd' || input == 'D') dir='r';//向右
			if (input == 'w' || input == 'W') dir='u';//向上
			if (input == 's' || input == 'S') dir='d';//向下
			random_xy();
			control(dir);
			game_over = over();
			round();
		}
		if (game_over == 0 || game_over == 2) break;
	}
}