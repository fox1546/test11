#include "stdafx.h"
#include "CShuDuParser.h"
#include <Windows.h>

CShuDuParser::CShuDuParser()
{
	m_iLevel = 0;
}

CShuDuParser::~CShuDuParser()
{
}

int CShuDuParser::Parse(int io_ShuDu[9][9])
{
	int iRes = Res_OK;

	{
		char czLog[1024];
		sprintf(czLog, "Parse begin input: \n");
		OutputDebugStringA(czLog);
		for(int w=0;w<9;w++)
		{
			sprintf(czLog,"%d %d %d %d %d %d %d %d %d \n"
				,io_ShuDu[w][0]
				,io_ShuDu[w][1]
				,io_ShuDu[w][2]
				,io_ShuDu[w][3]
				,io_ShuDu[w][4]
				,io_ShuDu[w][5]
				,io_ShuDu[w][6]
				,io_ShuDu[w][7]
				,io_ShuDu[w][8]
				);
			OutputDebugStringA(czLog);
		}
	}

	for(int row=0;row<9;row++)
	{
		for(int col=0;col<9;col++)
		{
			int num = io_ShuDu[row][col];
			if(num != 0)
			{
				io_ShuDu[row][col] = 0;
				if(!IsValid(io_ShuDu, row, col, num))
				{
					io_ShuDu[row][col] = num;
					char czLog[1024];
					sprintf(czLog, "Invalid input: row=%d, col=%d, num=%d\n", row, col, num);
					OutputDebugStringA(czLog);
					return Res_Fail;
				}
				io_ShuDu[row][col] = num;
			}
		}
	}

	if(SolveSudoku(io_ShuDu))
	{
		iRes = Res_OK;
	}
	else
	{
		iRes = Res_Fail;
	}

	{
		char czLog[1024];
		sprintf(czLog, "Parse end res %d output: \n", iRes);
		OutputDebugStringA(czLog);
		for(int w=0;w<9;w++)
		{
			sprintf(czLog,"%d %d %d %d %d %d %d %d %d \n"
				,io_ShuDu[w][0]
				,io_ShuDu[w][1]
				,io_ShuDu[w][2]
				,io_ShuDu[w][3]
				,io_ShuDu[w][4]
				,io_ShuDu[w][5]
				,io_ShuDu[w][6]
				,io_ShuDu[w][7]
				,io_ShuDu[w][8]
				);
			OutputDebugStringA(czLog);
		}
	}

	return iRes;
}

bool CShuDuParser::FindEmptyCell(int board[9][9], int& row, int& col)
{
	for(row=0;row<9;row++)
	{
		for(col=0;col<9;col++)
		{
			if(board[row][col] == 0)
			{
				return true;
			}
		}
	}
	return false;
}

bool CShuDuParser::IsValid(int board[9][9], int row, int col, int num)
{
	for(int c=0;c<9;c++)
	{
		if(board[row][c] == num)
		{
			return false;
		}
	}

	for(int r=0;r<9;r++)
	{
		if(board[r][col] == num)
		{
			return false;
		}
	}

	int boxRowStart = (row / 3) * 3;
	int boxColStart = (col / 3) * 3;
	for(int r=0;r<3;r++)
	{
		for(int c=0;c<3;c++)
		{
			if(board[boxRowStart + r][boxColStart + c] == num)
			{
				return false;
			}
		}
	}

	return true;
}

bool CShuDuParser::SolveSudoku(int board[9][9])
{
	int row, col;

	if(!FindEmptyCell(board, row, col))
	{
		return true;
	}

	for(int num=1;num<=9;num++)
	{
		if(IsValid(board, row, col, num))
		{
			board[row][col] = num;

			if(SolveSudoku(board))
			{
				return true;
			}

			board[row][col] = 0;
		}
	}

	return false;
}
