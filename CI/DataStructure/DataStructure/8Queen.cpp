#include "stdafx.h"
#include <iostream>
#include <cmath>

//Backtracking Algorithm
//Print all solutions of 8 queen
/*
  sample solution:
				  10000000
				  00000010
				  00001000
				  00000001
				  01000000
				  00010000
				  00000100
				  00100000

*/

//Map[8][8], initial {0...}
#define ROW 8
#define COLUMN 8

static bool validate8Queen(int Map[ROW][COLUMN], int row, int col);
static void printTable2(int table[ROW][COLUMN])
{
	for(int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COLUMN; ++j)
			std::cout<<table[i][j]<<" ";
		std::cout<<std::endl;
	}
}

static bool Explore8Queen(int Map[ROW][COLUMN],int col)
{
	if(col >= 8) //Find one solution
		return true;

	for(int row = 0; row < ROW; ++row)
	{
		if(validate8Queen(Map,row,col))
		{
			Map[row][col] = 1;
			if (Explore8Queen(Map,col+1) == true)
				return true;

			Map[row][col] = 0;  //backtracking
		}
	}

	return false;
}


static bool validate8Queen(int Map[ROW][COLUMN], int row, int col)
{
	//no same row
	for (int j=0; j< COLUMN; ++j)
		if (Map[row][j] == 1)
    	   return false;
	
	//no same column
	for (int i=0;i<ROW;++i)
		if (Map[i][col] == 1)
			return false;

	//no same diagonals
	for (int i=0;i<ROW; ++i)
		for (int j=0; j<COLUMN;++j)
			if(Map[i][j] == 1 && abs(i-row) == abs(j-col))
				return false;

	return true;
}

static void EightQueen()
{
	int sol[ROW][COLUMN];
	for(int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COLUMN; ++j)
			sol[i][j]= 0;
	}

	if(Explore8Queen(sol,0) == false)
		std::cout<<"No solution!"<<std::endl;
	else
		printTable2(sol);
}