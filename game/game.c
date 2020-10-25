#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


void Initboard(char board[row][col], int row1, int col1)     //��ʼ������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row1; i++)
	{
		for (j = 0; j < col1; j++)
		{
			board[i][j] = ' ';              //������Ԫ�ض�Ϊ�ո�
		}
	}

}

void DisplayBpard(char board[row][col], int row1, int col1)   //��ʾ����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row1; i++)    //��
	{
		for (j = 0; j < col1; j++)      //��       
		{
			printf(" %c ", board[i][j]);            
			if (j < col1 - 1)
				printf("|");
		}
		printf("\n");
		if (i < row1 - 1)                //��ʾ�м�ָ���
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
		printf("�����\n");
		printf("�����룺>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)        //�ж���������Ƿ������鷶Χ��
		{
			if (board[x-1][y-1] == ' ')                   //�ж����������Ƿ��ѷ�������
			{
				board[x - 1][y - 1] = '*';
				break;
			}

			else
				printf("���������������ӣ�����������\n");
		}
		else
			printf("������������������\n");
	}
}

void PCMove(char board[row][col], int row1, int col1)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		
		x = rand() % row;                  //�����������%row ������Ϊ0��1��2֮���������
		y = rand() % col;        
		if (board[x][y] == ' ')
		{
			printf("������\n");
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
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2]&& board[i][2]!=' ')          //�ж�ÿ������Ԫ���Ƿ���ȣ����Ҳ�Ϊ�� ��
			return board[i][0];
		else if(board[0][i] == board[1][i] && board[0][i] == board[2][i]&& board[2][i]!=' ')       //�ж�ÿ������Ԫ���Ƿ���ȣ����Ҳ�Ϊ�� ��
			return board[0][i];
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[1][1]!=' ')                           //�ж�б������Ԫ��
			return board[1][1];
	if (board[2][0] == board[1][1] && board[0][2] == board[1][1] && board[1][1] != ' ')
		return board[1][1];
	ret = IsFull(board, row, col);                                                                     //���������û�г��֣��ж��Ƿ��Ѿ���������
	if (ret == 0)
		return 'C';                                 //δ����
	else if (ret == 1)
		return 'Q';                               //������

}

int IsFull(char board[row][col], int row1, int col1)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)               //�ж��������Ƿ��� �ո�
		{
			if (board[i][j] == ' ')
			{
   				return 0;                      //�� ����ʾ���̻�û������
				break;
			}
				
		}
	}
	return 1;	                               //û���� 
}
