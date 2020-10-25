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
	Initboard(board, row, col);                 //��ʼ������
	DisplayBpard(board, row, col);              //��ʾ����
	while (1)
	{
		PlayerMove(board, row, col);           //�����
		DisplayBpard(board, row, col);         //��ʾ����
		ret = Iswin(board, row, col);          //�ж��Ƿ�������*-���Ӯ  #-PCӮ  C-����   Q-ƽ��
		if (ret != 'C')
			break;
		PCMove(board, row, col);               //PC��
		DisplayBpard(board, row, col);			//��ʾ����
		ret = Iswin(board, row, col);			//�ж��Ƿ�������*-���Ӯ  #-PCӮ  C-����   Q-ƽ��
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{

		printf("���Ӯ\n");
		
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
		
	}
	else
	{
		printf("ƽ��\n");
		

	}
		

}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
	menu();                                              //�˵���ʾ
	printf("�����룺>");
	scanf("%d",&input);									//����1-������Ϸ��0-�Ƴ���Ϸ
	switch (input)
	{
	case 0:  printf("�˳���Ϸ"); break;
	case 1:  game(); break;                            //������Ϸ
	default: printf("������������������"); break;

	}

	} while (input);
	
}
int main()
{
	test();  //����
	return 0;
}