#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>

#include"box.h"

void menu();

using namespace std;

#define up 119
#define down 115
#define right 100
#define left 97
void out_screen();

int x,y,foodx=10,foody=10;
bool food=false;
int direction = 2;
deque<int> dqx;
deque<int> dqy;

bool check_out(deque<int> x,deque<int> y){
	int hx,hy;
	hx=x.front();
	hy=y.front();
	deque<int> tempx=x;
	deque<int> tempy=y;
	tempx.pop_front();
	tempy.pop_front();
	while(!tempx.empty()){
		if(tempx.front()==hx && tempy.front()==hy){
			out_screen();
		}
		tempx.pop_front();
		tempy.pop_front();
	}
	return false;
}
void check_food(int direction,deque<int> &x, deque<int> &y){
	if(x.front()==foodx && y.front()==foody){
		int a,b;
		switch(direction){
			case 1:{
				a=x.front();
				b=y.front();
				b--;
				x.push_front(a);
				y.push_front(b);
				break;
			}
			case 2:{
				a=x.front();
				b=y.front();
				a++;
				x.push_front(a);
				y.push_front(b);
				break;
			}
			case 3:{
				a=x.front();
				b=y.front();
				b++;
				x.push_front(a);
				y.push_front(b);
				break;
			}
			case 4:{
				a=x.front();
				b=y.front();
				a--;
				x.push_front(a);
				y.push_front(b);
				break;
			}
		}
		foodx=((rand()%123)+6);
		foody=((rand()%26)+3);
		gotoxy(foodx,foody);
		cout << "#";
	}
}
void out_screen(){
	system("cls");
	boxDD(125,27,5,2);
	gotoxy(63,15);
	cout << " O U T  !";
	gotoxy(58,28);
	cout << "press 'e' to exit...";
	int opt=getch();
	if(opt == 101) exit(1);
	else menu();
}
void print_snake(deque<int> x,deque<int> y){
	int x_,y_,ex,ey;
	deque<int> gx=x;
	deque<int> gy=y;
	x_=gx.front();
	y_=gy.front();
	gotoxy(x_,y_);
	cout << "@";
	gx.pop_front();
	gy.pop_front();
	ex=gx.back();
	ey=gy.back();
	gotoxy(ex,ey);
	cout << " ";
	
	gx.pop_back();
	gy.pop_back();
	while(!gx.empty()){
		
		
		x_=gx.front();
		y_=gy.front();
		gotoxy(x_,y_);
		cout << "*";
		
		gx.pop_front();
		gy.pop_front();
	}
}
void movement(int direction,int x,int y){
	while(!kbhit()){
		int xc,yc;
		switch(direction){
			case 1: xc=dqx.front();
					yc=dqy.front();
					if(yc<=3) out_screen();
					else{
						yc--;
						dqx.push_front(xc);
						dqy.push_front(yc);
						dqx.pop_back();
						dqy.pop_back();
						
						if(!check_out(dqx,dqy)){
							check_food(direction,dqx,dqy);
							print_snake(dqx,dqy);
						}
					}
					Sleep(120);
					break;
			case 2: xc=dqx.front();
					yc=dqy.front();
					if(xc>=129) out_screen();
					else{
						
						xc++;
						dqx.push_front(xc);
						dqy.push_front(yc);
						dqx.pop_back();
						dqy.pop_back();
						if(!check_out(dqx,dqy)){
							check_food(direction,dqx,dqy);
							print_snake(dqx,dqy);
						}
					}
					Sleep(60);
					break;
			case 3: xc=dqx.front();
					yc=dqy.front();
					if(yc>=28) out_screen();
					else{
						yc++;
						dqx.push_front(xc);
						dqy.push_front(yc);
						dqx.pop_back();
						dqy.pop_back();
						if(!check_out(dqx,dqy)){
							check_food(direction,dqx,dqy);
							print_snake(dqx,dqy);
						}
					}
					Sleep(120);
					break;
			case 4: xc=dqx.front();
					yc=dqy.front();
					if(xc<=6) out_screen();
					else{
						
						xc--;
						dqx.push_front(xc);
						dqy.push_front(yc);
						dqx.pop_back();
						dqy.pop_back();
						if(!check_out(dqx,dqy)){
							check_food(direction,dqx,dqy);
							print_snake(dqx,dqy);
						}
					}
					Sleep(60);
					break;
		}
	}
	char hit;
	int dascii;
	hit=getch();
	if((hit==119 && direction == 1) ||(hit==115 && direction==1)) direction = 1;
	else if((hit==115 && direction==3) || (hit==119 && direction==3))	direction = 3;
	else if((hit==97 && direction==2) || (hit==100 && direction==2)) direction = 2;
	else if((hit==100 && direction == 4)||(hit==100 && direction ==4)) direction = 4;
	else{
		if(hit==119) direction=1;
		else if(hit==100) direction = 2;
		else if(hit==115) direction = 3;
		else if(hit==97) direction = 4;
	}
	movement(direction,x,y);
}
void gameloop(){
	dqx.push_back(67);
	dqy.push_back(15);
	dqx.push_back(66);
	dqy.push_back(15);
	dqx.push_back(65);
	dqy.push_back(15);
	
	dqx.push_back(64);
	dqy.push_back(15);
	dqx.push_back(63);
	dqy.push_back(15);
	dqx.push_back(62);
	dqy.push_back(15);
	movement(direction,67,15);
}
void clearScreen(){
	system("cls");
	boxDD(125,27,5,2);
}
void menu(){
	boxDD(125,27,5,2); // main box
//	gotoxy(55,15);
//	cout << "* S N A K E    G A M E *";
//	lineS(56,14,22);
//	lineS(56,16,22);
//	gotoxy(54,28);
//	cout << "press any key to continue...";
	getch();
	clearScreen();
	gotoxy(foodx,foody);
	cout << "#";
	gameloop();
}
int main(){
	srand(time(0));
	getch();
	menu();	
}
