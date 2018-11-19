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
	//A:人 ，X：箱子 

} ;
//地图
void showMap();
//接收小人的方向
char enterDirection();

//小人向上移动的方法 
void moveToUp(); 
//小人向下移动的方法
void moveToDown();
//小人向右移动的方法
void moveToRight();
//小人向左移动的方法
void moveToLeft();

//当前小人的坐标
int currentPersonRow=3;
int currentPersonCol=2;
//当前箱子的坐标
int currentBoxRow=3;
int currentBoxCol=3;


int main (int argc,char *argv[])
{
	//system("clear");
	printf("点击回车开始游戏~\n\n");
	//1代表运行 0代表停止
	int flag =1;
	while(flag==1)
	{
		//显示地图
		showMap();
		//显示小人的方向
		char dir =enterDirection();
		switch(dir)
		{
			//小人向上移动
			case 'w':
			case 'W':
				moveToUp();
			break;
			//小人向下动
			case 's':
			case 'S':
				moveToDown();
			break;
			//小人向右动
			case 'd':
			case 'D':
				moveToRight();
			break;
			//小人向左动
			case 'a':
			case 'A':
				moveToLeft();
			break;
			//停止运动
			case 'q':
			case 'Q':
				printf("渣渣T_T\n");
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


//地图
void showMap()
{
	int i;
	for(i=0;i<ROW;i++)
	{
		printf("%s\n",map[i]);
	}
	printf("\n\n\n\n");
	printf("W:上,S:下,A:左,D:右,Q:退出");
	printf("\n\n\n\n");
}


//方向控制
char enterDirection()
{
	rewind(stdin);
	char dir;
	dir=getch();
	return dir;
}

//向上移动
void moveToUp()
{
	//小人的下一个坐标
	int nextPersonCol=currentPersonCol;
	int nextPersonRow=currentPersonRow-1; 
	//箱子的下一个坐标
	int nextBoxRow=currentBoxRow-1;
	int nextBoxCol=currentBoxCol;
	
	//如果小人的下一个坐标是路
	if(map[nextPersonRow][nextPersonCol]==' ')
	{
		map[nextPersonRow][nextPersonCol]='A';
		map[currentPersonRow][currentPersonCol]=' ';
		currentPersonRow=nextPersonRow;
		currentPersonCol=nextPersonCol;
	}
	//如果小人的下一个坐标是墙
	if(map[nextPersonRow][nextPersonCol]=='#'){
	}
	//如果小人的下一个坐标是箱子
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
//向下移动
void moveToDown()
{
	//小人的下一个坐标
	int nextPersonCol=currentPersonCol;
	int nextPersonRow=currentPersonRow+1;
	//箱子的下一个坐标
	int nextBoxRow=currentBoxRow+1;
	int nextBoxCol=currentBoxCol;
	
	//如果小人的下一个坐标是路
	if(map[nextPersonRow][nextPersonCol]==' ')
	{
		map[nextPersonRow][nextPersonCol]='A';
		map[currentPersonRow][currentPersonCol]=' ';
		currentPersonRow=nextPersonRow;
		currentPersonCol=nextPersonCol;
	}
	//如果小人的下一个坐标是墙
	if(map[nextPersonRow][nextPersonCol]=='#'){
	}
	//如果小人的下一个坐标是箱子
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
//向右移动
void moveToRight()
{
	//小人的下一个坐标
	int nextPersonCol=currentPersonCol+1;
	int nextPersonRow=currentPersonRow;
	//箱子的下一个坐标
	int nextBoxRow=currentBoxRow;
	int nextBoxCol=currentBoxCol+1;
	
	//如果小人的下一个坐标是路
	if(map[nextPersonRow][nextPersonCol]==' ')
	{
		map[nextPersonRow][nextPersonCol]='A';
		map[currentPersonRow][currentPersonCol]=' ';
		currentPersonRow=nextPersonRow;
		currentPersonCol=nextPersonCol;
	}
	//如果小人的下一个坐标是墙
	if(map[nextPersonRow][nextPersonCol]=='#'){
	}
	//如果小人的下一个坐标是箱子
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
//向左移动
void moveToLeft()
{
	//小人的下一个坐标
	int nextPersonCol=currentPersonCol-1;
	int nextPersonRow=currentPersonRow;
	//箱子的下一个坐标
	int nextBoxRow=currentBoxRow;
	int nextBoxCol=currentBoxCol-1;
	
	//如果小人的下一个坐标是路
	if(map[nextPersonRow][nextPersonCol]==' ')
	{
		map[nextPersonRow][nextPersonCol]='A';
		map[currentPersonRow][currentPersonCol]=' ';
		currentPersonRow=nextPersonRow;
		currentPersonCol=nextPersonCol;
	}
	//如果小人的下一个坐标是墙
	if(map[nextPersonRow][nextPersonCol]=='#'){
	}
	//如果小人的下一个坐标是箱子
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
