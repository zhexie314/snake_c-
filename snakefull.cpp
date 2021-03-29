#include <iostream>
#include <thread>
#include <chrono>
#include "myconio_mac.h"


using namespace std;



bool gameover = false;
const int height = 20;
const int width = 40;

int x = height/2;
int y = width/2;
int h = 0;
int w = 0;
int len = 1;
char g_input;
int pointArry [2];
int score = 0;
int high_score = 0;

char board [height][width];
void update();
void setup();
void input();
void draw(bool col);
void move();
void over();
void doState();
void gameState();
void moveSnakeArray();
void makePoint();
void buidGameBoard();
void mark();
bool collision();
bool col = false;

enum state {onGame,gameFail};
enum orie {up,down,left,right};

char T_gameover[17] = "G A M E  O V E R";
char T_retry[19] = "~Press Y To Start~";

state currentState = ::onGame;

orie currentOrie = ::right;



struct Position {int x;int y;};

// Position * lenpositon =  new Position [len];
Position * lenpositon;


void moveSnakeArray()
{
	for (int i = len - 2; i >= 0; i--)
	{
		lenpositon[i + 1] = lenpositon[i];
	}
}



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
	while(1)
	{
	gameState();
	}
	thread_roll_input.detach();
	delete [] lenpositon;
	return 0;
}



void gameState()
{
	char _input = popInput();
	switch(currentState)
	{
		case :: onGame:
			setup();
			while(!gameover)
			{
			this_thread::sleep_for(chrono::milliseconds(1000/10));
			cout << "\e[H\e[2J\e[3J";
			doState();
			move();
			mark();
			draw(col);
			}
			break;
		case ::gameFail:
			board[x][y] = ' ';
			if (_input == 'y')
			{
				currentState = ::onGame;
				g_input = 0;
				delete [] lenpositon;

			}else if (_input == 'n')
			{
				gameover = true;
			}
			break;
	}
}

void setup()
{
	gameover = false;
	orie currentOrie = ::right;
	score = 0;
	len = 1;
	lenpositon = new Position[len];
	h = 0;
	w = 0;
	lenpositon[0].x = x;
	lenpositon[0].y = y;
	makePoint();
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
	moveSnakeArray();
	lenpositon[0].x = x + h;
	lenpositon[0].y = y + w;
}


bool collision()
{
	if (board[x + h][y + w] == '#')
	{
		gameover = true;
		currentState = gameFail;
		if (score > high_score)
		{
			high_score = score;
		}
		return true;
	}
	else if (board[x + h][y + w] == 'O')
	{
		makePoint();
		len++;
		score++;
		Position * newlenposition =  new Position [len];
		newlenposition[0].x = x + h;
		newlenposition[0].y = y + w;
		for (int i = 0; i < len-1; ++i)
		{
			newlenposition[i + 1] = lenpositon[i];
		}
		delete [] lenpositon;
		lenpositon = newlenposition;
		// makePoint();
		return false;
	}
	return false;
}

void buidGameBoard()
{
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
}


void mark()
{
	buidGameBoard();
	board[pointArry[0]][pointArry[1]] = 'O';
	// collision();
	col = collision();
	for (int i = 0; i < len; ++i)
	{
		board[lenpositon[i].x][lenpositon[i].y] = '@';
	}
}





void draw(bool col)
{
	if (!col)
	{
		cout << "score :" << score <<"                "<< "high score :" << high_score << endl;
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
	else
	{
		cout << "score :" << score <<"                "<< "high score :" << high_score << endl;
		buidGameBoard();
		for (int i = 0; i < 16; ++i)
		{
			board[8][12 + i] = T_gameover[i];
		}
				for (int i = 0; i < 18; ++i)
		{
			board[11][11 + i] = T_retry[i];
		}
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
}

