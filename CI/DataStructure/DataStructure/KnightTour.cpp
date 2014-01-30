#include "stdafx.h"
#include <iostream>

#define COLUMN 8
#define ROW 8

static void printTable(int table[ROW][COLUMN])
{
	for(int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COLUMN; ++j)
			std::cout<<table[i][j]<<" ";
		std::cout<<std::endl;
	}
}

static bool explore(int posX, int posY, int index, int sol[ROW][COLUMN], int xMove[], int yMove[]);
static bool checkValid(int sol[ROW][COLUMN], int posX, int posY);

static void KnightTour()
{
	int sol[ROW][COLUMN];
	for(int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COLUMN; ++j)
			sol[i][j]= -1;
	}

	int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

	sol[0][0] = 0;
	if(explore(0,0,1,sol,xMove,yMove) == false)
		std::cout<<"No solution!"<<std::endl;
	else
		printTable(sol);
}

static bool checkValid(int sol[ROW][COLUMN], int posX, int posY)
{
	if (posX>=0 && posX<ROW && posY>=0 && posY<COLUMN && sol[posX][posY] == -1)
		return true;
	return false;
}

static bool explore(int posX, int posY, int index, int sol[ROW][COLUMN], int xMove[], int yMove[])
{
	if(index == ROW*COLUMN)
		return true;

	int next_PosX, next_PosY;

	for (int i = 0; i<8;++i)
	{
		next_PosX = posX + xMove[i];
		next_PosY = posY + yMove[i];

		if (checkValid(sol,next_PosX,next_PosY))
		{
			sol[next_PosX][next_PosY] = index; //forward
			if(explore(next_PosX,next_PosY,index+1,sol,xMove,yMove) == true) //if goal return true
				return true;
			sol[next_PosX][next_PosY] = -1; //backtracking
		}
	}
	return false;
}