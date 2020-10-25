#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"
#include <time.h>
//#include <>

void menu()
{
	printf("/****************************************************/\n");
	printf("/************1-play    0-exit************************/\n");
	printf("/****************************************************/\n");
}
void game()
{
	char board[row][col] = { 0 };
	char ret;
	Initboard(board, row, col);                 //初始化数组
	DisplayBpard(board, row, col);              //显示棋盘
	while (1)
	{
		PlayerMove(board, row, col);           //玩家走
		DisplayBpard(board, row, col);         //显示棋盘
		ret = Iswin(board, row, col);          //判断是否产生结局*-玩家赢  #-PC赢  C-继续   Q-平局
		if (ret != 'C')
			break;
		PCMove(board, row, col);               //PC走
		DisplayBpard(board, row, col);			//显示棋盘
		ret = Iswin(board, row, col);			//判断是否产生结局*-玩家赢  #-PC赢  C-继续   Q-平局
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{

		printf("玩家赢\n");
		
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
		
	}
	else
	{
		printf("平局\n");
		

	}
		

}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
	menu();                                              //菜单显示
	printf("请输入：>");
	scanf("%d",&input);									//输入1-进入游戏，0-推出游戏
	switch (input)
	{
	case 0:  printf("退出游戏"); break;
	case 1:  game(); break;                            //进入游戏
	default: printf("输入有误，请重新输入"); break;

	}

	} while (input);
	
}
int main()
{
	test();  //进入
	return 0;
}