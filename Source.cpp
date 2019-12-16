#include <iostream>
#include <mutex>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, dest_, destl, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;
void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	dest_ = rand() % width;
	destl = rand() % height;
	score = 0;
}
void Draw()
{
	system("cls"); //system("clear");
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;

	for (int cursorlbordas不contam始0 = 0; cursorlbordas不contam始0 < height; cursorlbordas不contam始0++)
	{
		for (int cursor_bordas不contam始0 = 0; cursor_bordas不contam始0 < width; cursor_bordas不contam始0++)
		{
			if (cursor_bordas不contam始0 == 0)
				cout << "#";
			if (cursorlbordas不contam始0 == y && cursor_bordas不contam始0 == x)
				cout << "G";
			else if (cursorlbordas不contam始0 == fruitY && cursor_bordas不contam始0 == fruitX)
				cout << "F";
			else if (cursorlbordas不contam始0 == destl && cursor_bordas不contam始0 == dest_)
				cout << "A";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailY[k] == cursorlbordas不contam始0 && tailX[k] == cursor_bordas不contam始0)
					{
						switch (k) {
						case 0:
							cout << "r";
							print = true;
							break;
						case 1:
							cout << "e";
							print = true;
							break;
						case 2:
							cout << "g";
							print = true;
							break;
						default:
							cout << "g";
							print = true;
						}



					}

				}

				if (!print)
					cout << " ";
			}


			if (cursor_bordas不contam始0 == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;
	cout << "Balanc,o do Greg:" << score << endl;
}
void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	//if (x > width || x < 0 || y > height || y < 0)
	// gameOver = true;
	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;

	for (int i = 0; i < nTail; i++) {
		if (tailX[i] == y && tailY[i] > x) {
				gameOver = false;
		}
	}

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}

	//Muda a posição do A ↓
	if (x == dest_ && y == destl)
	{
		score -= 10;
		dest_ = rand() % width;
		destl = rand() % height;
		nTail--;
	}
}
void Input() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		}
	}

}

int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(10); //sleep(10);
	}
	return 0;
}