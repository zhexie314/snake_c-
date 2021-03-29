#include <iostream>
#include <thread>
#include <chrono>
#include "myconio_mac.h"


using namespace std;



bool gameover = false;
const int height = 20;
const int width = 40;
int x,y;
int h = 0;
int w = 0;
int point = 0;
int len = 3;
int lenArry = 0;
char g_input;
int pointArry [2];


char board [height][width];
void update();
void setup();
void input();
void draw();
void move();
void over();
void doState();
void moveSnakeArray();
void makePoint();

enum orie {up,down,left,right};




orie currentOrie = ::right;



struct Position {int x;int y;};

Position * lenpositon =  new Position [len];


// void moveSnakeArray()
// {
// 	for (int i = len - 2; i >= 0; i--)
// 	{
// 		lenpositon[i + 1] = lenpositon[i];
// 	}
// }



void rollInput()
{
		while (true)
		{
			g_input = getch();
		}
}

char popInput()
{
		char input = g_input;
		// g_input = 0;
		return input;
}




int main(int argc, char const *argv[])
{
	thread thread_roll_input(rollInput);

	setup();
	while(!gameover)
	{
	this_thread::sleep_for(chrono::milliseconds(1000/2));
	update();
	}

	thread_roll_input.detach();
	return 0;
}






void setup()
{
	gameover = false;
	point = 0;
	// len = 1;
	x = height/2;
	y = width/2;

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (j == 0 || j == width - 1 || i == 0 || i == height - 1)
			{
				board[i][j] = '#';
			}
			else
			{
				board[i][j] = ' ';
			}
		}
	}

	board[x][y] = '@';
	makePoint();
}


void update()
{

	// system("clear");
	cout << "\e[H\e[2J\e[3J";
	doState();
	move();
	draw();
	if (lenArry > len)
	{
		lenArry = 0;
	}else
	{
		lenArry++;
	}
}


void makePoint()
{
	pointArry[0] = rand()% 18 + 1;
	pointArry[1] = rand()% 38 + 1;
}

void doState()
{
	char _input = popInput();
	switch(currentOrie)
	{
		case ::up:
			h--;
			if (_input == 'd')
			{
				currentOrie = ::right;
			}else if (_input == 'a')
			{
				currentOrie = ::left;
			}
			break;
		case ::down:
			h++;
			if (_input == 'd')
			{
				currentOrie = ::right;
			}else if (_input == 'a')
			{
				currentOrie = ::left;
			}
			break;
		case ::left:
			w--;
			if (_input == 'w')
			{
				currentOrie = ::up;
			}else if (_input == 's')
			{
				currentOrie = ::down;
			}
			break;
		case ::right:
			w++;
			if (_input == 'w')
			{
				currentOrie = ::up;
			}else if (_input == 's')
			{
				currentOrie = ::down;
			}
			break;
	}
}


void move()
{
	// moveSnakeArray();
	lenpositon[lenArry].x = x + h;
	lenpositon[lenArry].y = y + w;
	board[x + h][y + w] = '@';
}


void draw()
{


	board[pointArry[0]][pointArry[1]] = 'O';


	board[lenpositon[0].x][lenpositon[0].y] = ' ';




	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (j== width - 1)
			{
				cout << board[i][j] << endl;
			}
			else
			{
				cout << board[i][j];
			}
		}
	}
}

