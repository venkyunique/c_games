#include<stdio.h>
#include<iostream>
#include<windows.h>
#include<unistd.h>
using namespace std;
void gotoxy(int,int);
void boxDD (int len , int bre , int x , int y)        //double horizontal - double vertical
	{
		int i;
		for(i=0 ; i<len ; i++)
		{
			gotoxy(x+i,y);
			printf("%c",205);
			gotoxy(x+i,y+bre);
			printf("%c",205);
		}
		for(i=0 ; i< bre ; i++)
		{
			gotoxy(x,y+i);
			printf("%c",186);
			gotoxy(x+len,y+i);
			printf("%c",186);	
		}
		gotoxy(x+len,y);
		printf("%c",187);
		gotoxy(x+len,y+bre);
		printf("%c",188);
		gotoxy(x,y);
		printf("%c",201);
		gotoxy(x,y+bre);
		printf("%c",200);
	}
	
	void boxSS(int len , int bre , int x , int y){        // single horizontal - single vertical
		int i;
		for(i=0 ; i<len ; i++)
		{
			gotoxy(x+i,y);
			printf("%c",196);
			gotoxy(x+i,y+bre);
			printf("%c",196);
		}
		for(i=0 ; i< bre ; i++)
		{
			gotoxy(x,y+i);
			printf("%c",179);
			gotoxy(x+len,y+i);
			printf("%c",179);	
		}
		gotoxy(x+len,y);
		printf("%c",191);
		gotoxy(x+len,y+bre);
		printf("%c",217);
		gotoxy(x,y);
		printf("%c",218);
		gotoxy(x,y+bre);
		printf("%c",192);
	}
	
	void lineS(int x,int y,int length)            //single line
	{
		gotoxy(x,y);
		int i;
		for(i=0;i<length;i++)
		{
			printf("%c",196);
		}
	}
	void lineD(int x,int y,int length)         //double line
	{
		gotoxy(x,y);
		int i;
		for(i=0;i<length;i++)
		{
			printf("%c",205);
		}
	}
	
	void boxErase(int len , int bre , int x , int y)
	{
		int i;
		for(i=0 ; i<len ; i++)
		{
			gotoxy(x+i,y);
			printf(" ");
			gotoxy(x+i,y+bre);
			printf(" ");
		}
		for(i=0 ; i< bre ; i++)
		{
			gotoxy(x,y+i);
			printf(" ");
			gotoxy(x+len,y+i);
			printf(" ");	
		}
		gotoxy(x+len,y);
		printf(" ");
		gotoxy(x+len,y+bre);
		printf(" ");
		gotoxy(x,y);
		printf(" ");
		gotoxy(x,y+bre);
		printf(" ");
	}
	
	void boxDS (int len , int bre , int x , int y)       //double horizontal-single vertical
	{
		int i;
	for(i=0 ; i<len ; i++)
		{
			gotoxy(x+i,y);
			printf("%c",205);
			gotoxy(x+i,y+bre);
			printf("%c",205);
		}
		for(i=0 ; i< bre ; i++)
		{
			gotoxy(x,y+i);
			printf("%c",179);
			gotoxy(x+len,y+i);
			printf("%c",179);	
		}
		gotoxy(x+len,y);
		printf("%c",184);
		gotoxy(x+len,y+bre);
		printf("%c",190);
		gotoxy(x,y);
		printf("%c",213);
		gotoxy(x,y+bre);
		printf("%c",212);
	}
	
	
void gotoxy(int x , int y)
  {
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
  }
  
  
void boxerase (int len , int bre , int x , int y)        
	{
		int i;
		for(i=0 ; i<len ; i++)
		{
			gotoxy(x+i,y);
			printf(" ");
			gotoxy(x+i,y+bre);
			printf(" ");
		}
		for(i=0 ; i< bre ; i++)
		{
			gotoxy(x,y+i);
			printf(" ");
			gotoxy(x+len,y+i);
			printf(" ");	
		}
		gotoxy(x+len,y);
		printf(" ");
		gotoxy(x+len,y+bre);
		printf(" ");
		gotoxy(x,y);
		printf(" ");
		gotoxy(x,y+bre);
		printf(" ");
	}
