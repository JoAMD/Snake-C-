// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <vector>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX, tailY;
vector <pair<int, int>> snake;
vector <pair<int, int>>::iterator ptr;

enum direction
{
	STOP = 0,
	LEFT,
	RIGHT,
	DOWN,
	UP
};
direction snakeDir;

void Setup()
{
	srand(time(NULL));
	gameOver = false;
	x = width / 2;
	y = height / 2;

	snake.push_back({ x, y });
	tailX = x;
	tailY = y;
	/*
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			snakeArr[i][j] = false;
		}
	}
	snakeArr[x][y] = true;
	*/
	fruitX = rand() % width + 1;
	fruitY = rand() % height + 1;
	score = 0;
	snakeDir = STOP;
}

bool CheckSnakeVector(int i, int j) 
{
	//for (int k = 0; k < snake.size; k++)
	for (ptr = snake.begin(); ptr < snake.end(); ptr++)
	{
		if ((*ptr).first == i && (*ptr).second == j) 
		{
			return true;
		}
	}
	return false;
}

void Draw()
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
	
	for (int i = 1; i < width + 1; i++)
	{
		cout << "#";
		for (int j = 1; j < height + 1; j++)
		{
			//if (snakeArr[i - 1][j - 1])
			//if (x == i - 1 && y == j - 1)
			if(CheckSnakeVector(i - 1, j - 1))
			{
				cout << "@";
			}
			else if (i == fruitX && j == fruitY) {
				cout << "F";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "#";
		cout << endl;
	}

	for (int i = 0; i < height + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "\n\n Score = " << score << " x and y = " << x << " " << y;
	cout << " Fruit x and y = " << fruitX << " " << fruitY;
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
			case 'w':
				if (snakeDir != DOWN)
				{
					snakeDir = UP;
				}
				break;

			case 's':
				if (snakeDir != UP)
				{
					snakeDir = DOWN;
				}
				break;

			case 'a':
				if (snakeDir != RIGHT)
				{
					snakeDir = LEFT;
				}
				break;

			case 'd':
				if (snakeDir != LEFT)
				{
					snakeDir = RIGHT;
				}
				break;

			case 'p':
				snakeDir = STOP;
				break;

			default:
				break;
		}
	}
}

void Logic()
{
	if (x < 0 || y < 0 || x > width || y > width) 
	{
		snakeDir = STOP;
		gameOver = true;
		return;
	}

	switch (snakeDir)
	{
	case STOP:
		break;

	case LEFT:
		y--;
		break;

	case RIGHT:
		y++;
		break;

	case DOWN:
		x++;
		break;

	case UP:
		x--;
		break;

	default:
		break;
	}

	if (fruitX == x + 1 && fruitY == y + 1)
	{
		fruitX = rand() % width + 1;
		fruitY = rand() % height + 1;
		score++;
		snake.push_back({ x, y });
	}
	else 
	{
		//snake.at(snake.size - 1)[0] = x;
		//snake.at(snake.size - 1)[1] = y;
		
		//snake[snake.size - 1] = { x, y };
		//for (int i = 0; i + 1 < snake.size; i++)
		for (ptr = snake.begin(); ptr + 1 < snake.end(); ptr++)
		{
			(*ptr).first = (*(ptr + 1)).first;
			(*ptr).second = (*(ptr + 1)).second;
		}
		(*ptr).first = x;
		(*ptr).second = y;
		//snakeArr[tailX][tailY] = false;
	}

	//tailX = x;
	//tailY = y;

	//snakeArr[x][y] = true;

}

int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(10);
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
