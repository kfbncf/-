#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


void Initboard(char board[row][col], int row1, int col1)     //初始化数组
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row1; i++)
	{
		for (j = 0; j < col1; j++)
		{
			board[i][j] = ' ';              //数组中元素都为空格
		}
	}

}

void DisplayBpard(char board[row][col], int row1, int col1)   //显示棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row1; i++)    //行
	{
		for (j = 0; j < col1; j++)      //列       
		{
			printf(" %c ", board[i][j]);            
			if (j < col1 - 1)
				printf("|");
		}
		printf("\n");
		if (i < row1 - 1)                //显示中间分割线
		{
			for (j = 0; j < col1; j++)
			{
					printf("---", board[i][j]);
				if (j < col1 - 1)
					printf("|");
			}
			printf("\n");
		}
		
	}
}

void PlayerMove(char board[row][col], int row1, int col1)
{
	int i = 0;
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("玩家走\n");
		printf("请输入：>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)        //判断玩家输入是否在数组范围内
		{
			if (board[x-1][y-1] == ' ')                   //判断玩家输入的是否已放入棋子
			{
				board[x - 1][y - 1] = '*';
				break;
			}

			else
				printf("输入坐标已有棋子，请重新输入\n");
		}
		else
			printf("输入有误请重新输入\n");
	}
}

void PCMove(char board[row][col], int row1, int col1)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		
		x = rand() % row;                  //产生随机数，%row ，余数为0、1、2之间的三个数
		y = rand() % col;        
		if (board[x][y] == ' ')
		{
			printf("电脑走\n");
			board[x ][y ] = '#';
			break;
		}
	}
}

char Iswin(char board[row][col], int row1, int col1)
{
	int i = 0;
	int j = 0;
	int ret = 0;
	for (i = 0; i < row; i++)
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2]&& board[i][2]!=' ')          //判断每行三个元素是否相等，并且不为‘ ’
			return board[i][0];
		else if(board[0][i] == board[1][i] && board[0][i] == board[2][i]&& board[2][i]!=' ')       //判断每列三个元素是否相等，并且不为‘ ’
			return board[0][i];
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[1][1]!=' ')                           //判断斜着三个元素
			return board[1][1];
	if (board[2][0] == board[1][1] && board[0][2] == board[1][1] && board[1][1] != ' ')
		return board[1][1];
	ret = IsFull(board, row, col);                                                                     //以上情况都没有出现，判断是否已经下满棋子
	if (ret == 0)
		return 'C';                                 //未下满
	else if (ret == 1)
		return 'Q';                               //以下满

}

int IsFull(char board[row][col], int row1, int col1)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)               //判断数组中是否还有 空格
		{
			if (board[i][j] == ' ')
			{
   				return 0;                      //有 ，表示棋盘还没有下满
				break;
			}
				
		}
	}
	return 1;	                               //没有了 
}
