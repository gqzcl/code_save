#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define ROW 10
#define COL 11
char map [ROW][COL]={
	"##########",//0
	"###     ##",
	"###     ##",
	"##AX  # ##",
	"###  ##   ",
	"#####    #",
	"##       #",
	"#     ####",
	"###       ",
	"##########"  //9
	//A:�� ��X������ 

} ;
//��ͼ
void showMap();
//����С�˵ķ���
char enterDirection();

//С�������ƶ��ķ��� 
void moveToUp(); 
//С�������ƶ��ķ���
void moveToDown();
//С�������ƶ��ķ���
void moveToRight();
//С�������ƶ��ķ���
void moveToLeft();

//��ǰС�˵�����
int currentPersonRow=3;
int currentPersonCol=2;
//��ǰ���ӵ�����
int currentBoxRow=3;
int currentBoxCol=3;


int main (int argc,char *argv[])
{
	//system("clear");
	printf("����س���ʼ��Ϸ~\n\n");
	//1�������� 0����ֹͣ
	int flag =1;
	while(flag==1)
	{
		//��ʾ��ͼ
		showMap();
		//��ʾС�˵ķ���
		char dir =enterDirection();
		switch(dir)
		{
			//С�������ƶ�
			case 'w':
			case 'W':
				moveToUp();
			break;
			//С�����¶�
			case 's':
			case 'S':
				moveToDown();
			break;
			//С�����Ҷ�
			case 'd':
			case 'D':
				moveToRight();
			break;
			//С������
			case 'a':
			case 'A':
				moveToLeft();
			break;
			//ֹͣ�˶�
			case 'q':
			case 'Q':
				printf("����T_T\n");
				flag=0;
			break;
		}
		showMap();
		if(currentBoxRow==currentBoxCol==9)
		{
			printf("^_^!!!");
			flag=0;
		}
	}
}


//��ͼ
void showMap()
{
	int i;
	for(i=0;i<ROW;i++)
	{
		printf("%s\n",map[i]);
	}
	printf("\n\n\n\n");
	printf("W:��,S:��,A:��,D:��,Q:�˳�");
	printf("\n\n\n\n");
}


//�������
char enterDirection()
{
	rewind(stdin);
	char dir;
	dir=getch();
	return dir;
}

//�����ƶ�
void moveToUp()
{
	//С�˵���һ������
	int nextPersonCol=currentPersonCol;
	int nextPersonRow=currentPersonRow-1; 
	//���ӵ���һ������
	int nextBoxRow=currentBoxRow-1;
	int nextBoxCol=currentBoxCol;
	
	//���С�˵���һ��������·
	if(map[nextPersonRow][nextPersonCol]==' ')
	{
		map[nextPersonRow][nextPersonCol]='A';
		map[currentPersonRow][currentPersonCol]=' ';
		currentPersonRow=nextPersonRow;
		currentPersonCol=nextPersonCol;
	}
	//���С�˵���һ��������ǽ
	if(map[nextPersonRow][nextPersonCol]=='#'){
	}
	//���С�˵���һ������������
	if(map[nextPersonRow][nextPersonCol]=='X')
	{
		if(map[nextBoxRow][nextBoxCol]==' '){
			map[nextPersonRow][nextPersonCol]='A';
			map[currentPersonRow][currentPersonCol]=' ';
			
			map[nextBoxRow][nextBoxCol]='X';
			map[currentPersonRow][currentPersonCol]='A';
			
			currentPersonRow=nextPersonRow;
			currentPersonCol=nextPersonCol;
			currentBoxRow=nextBoxRow;
			currentBoxCol=nextBoxCol;
		}
	}
}
//�����ƶ�
void moveToDown()
{
	//С�˵���һ������
	int nextPersonCol=currentPersonCol;
	int nextPersonRow=currentPersonRow+1;
	//���ӵ���һ������
	int nextBoxRow=currentBoxRow+1;
	int nextBoxCol=currentBoxCol;
	
	//���С�˵���һ��������·
	if(map[nextPersonRow][nextPersonCol]==' ')
	{
		map[nextPersonRow][nextPersonCol]='A';
		map[currentPersonRow][currentPersonCol]=' ';
		currentPersonRow=nextPersonRow;
		currentPersonCol=nextPersonCol;
	}
	//���С�˵���һ��������ǽ
	if(map[nextPersonRow][nextPersonCol]=='#'){
	}
	//���С�˵���һ������������
	if(map[nextPersonRow][nextPersonCol]=='X')
	{
		if(map[nextBoxRow][nextBoxCol]==' '){
			map[nextPersonRow][nextPersonCol]='A';
			map[currentPersonRow][currentPersonCol]=' ';
			
			map[nextBoxRow][nextBoxCol]='X';
			map[currentPersonRow][currentPersonCol]='A';
			
			currentPersonRow=nextPersonRow;
			currentPersonCol=nextPersonCol;
			currentBoxRow=nextBoxRow;
			currentBoxCol=nextBoxCol;
		}
	}
}
//�����ƶ�
void moveToRight()
{
	//С�˵���һ������
	int nextPersonCol=currentPersonCol+1;
	int nextPersonRow=currentPersonRow;
	//���ӵ���һ������
	int nextBoxRow=currentBoxRow;
	int nextBoxCol=currentBoxCol+1;
	
	//���С�˵���һ��������·
	if(map[nextPersonRow][nextPersonCol]==' ')
	{
		map[nextPersonRow][nextPersonCol]='A';
		map[currentPersonRow][currentPersonCol]=' ';
		currentPersonRow=nextPersonRow;
		currentPersonCol=nextPersonCol;
	}
	//���С�˵���һ��������ǽ
	if(map[nextPersonRow][nextPersonCol]=='#'){
	}
	//���С�˵���һ������������
	if(map[nextPersonRow][nextPersonCol]=='X')
	{
		if(map[nextBoxRow][nextBoxCol]==' '){
			map[nextPersonRow][nextPersonCol]='A';
			map[currentPersonRow][currentPersonCol]=' ';
			
			map[nextBoxRow][nextBoxCol]='X';
			map[currentPersonRow][currentPersonCol]='A';
			
			currentPersonRow=nextPersonRow;
			currentPersonCol=nextPersonCol;
			currentBoxRow=nextBoxRow;
			currentBoxCol=nextBoxCol;
		}
	}
}
//�����ƶ�
void moveToLeft()
{
	//С�˵���һ������
	int nextPersonCol=currentPersonCol-1;
	int nextPersonRow=currentPersonRow;
	//���ӵ���һ������
	int nextBoxRow=currentBoxRow;
	int nextBoxCol=currentBoxCol-1;
	
	//���С�˵���һ��������·
	if(map[nextPersonRow][nextPersonCol]==' ')
	{
		map[nextPersonRow][nextPersonCol]='A';
		map[currentPersonRow][currentPersonCol]=' ';
		currentPersonRow=nextPersonRow;
		currentPersonCol=nextPersonCol;
	}
	//���С�˵���һ��������ǽ
	if(map[nextPersonRow][nextPersonCol]=='#'){
	}
	//���С�˵���һ������������
	if(map[nextPersonRow][nextPersonCol]=='X')
	{
		if(map[nextBoxRow][nextBoxCol]==' '){
			map[nextPersonRow][nextPersonCol]='A';
			map[currentPersonRow][currentPersonCol]=' ';
			
			map[nextBoxRow][nextBoxCol]='X';
			map[currentPersonRow][currentPersonCol]='A';
			
			currentPersonRow=nextPersonRow;
			currentPersonCol=nextPersonCol;
			currentBoxRow=nextBoxRow;
			currentBoxCol=nextBoxCol;
		}
	}
}
