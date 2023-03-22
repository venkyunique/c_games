#include<conio.h>
#include<bits/stdc++.h>
#include<windows.h>
#include "box.h"
#include<unistd.h>

using namespace std;

#define RIGHT  100
#define LEFT  97
#define UP  119
#define DOWN  115
int DIR;
int PREVDIR;
int ch;
int tempx,tempy;
int x = 10;
int y = 10;

void move()
{
	switch(DIR)
	{
		case RIGHT:{
			tempx = x++;
			tempy = y;
			gotoxy(tempx,tempy);
			cout << " ";
			if(x >= 128) x = 7;
			gotoxy(x,y);
			cout << "*";
			break;
		}
		case LEFT:{
			tempx = x--;
			tempy = y;
			gotoxy(tempx,tempy);
			cout << " ";
			if(x <= 7) x = 128;
			gotoxy(x,y);
			cout << "*";
			break;
		}
		case UP:{
			tempx = x;
			tempy = y--;
			gotoxy(tempx,tempy);
			cout << " ";
			if(y <= 3) y = 28;
			gotoxy(x,y);
			cout << "*";
			break;
		}
		case DOWN:{
			tempx = x;
			tempy = y++;
			gotoxy(tempx,tempy);
			cout << " ";
			if(y >=28) y = 3;
			gotoxy(x,y);
			cout << "*";
			break;
		}
	}
}

void changeDir(int ch){
	PREVDIR = DIR;
	if(PREVDIR == 100 && ch == 97) DIR = PREVDIR;
	else if(PREVDIR == 119 && ch == 115) DIR = PREVDIR;
	else if(PREVDIR == 97 && ch == 100) DIR = PREVDIR;
	else if(PREVDIR == 115 && ch == 119) DIR = PREVDIR;
	else DIR = ch;	
}
void init()
{
	DIR = RIGHT;
}
int main()
{
	getch();
	init();
	boxDD(125,27,5,2);
	while(1)
	{
		move();
		if(kbhit())
		{
			ch = getch();
			if(ch == 100 || ch == 97 || ch == 115 || ch == 119)
				changeDir(ch);
		}
		
		Sleep(100);
		
	}
	return 0;
}
