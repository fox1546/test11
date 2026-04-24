#pragma once

#define Res_OK 0
#define Res_Fail -1

class CShuDuParser
{
public:
	CShuDuParser();
	virtual ~CShuDuParser();

	int Parse(int io_ShuDu[9][9]);

public:
	int m_iLevel;

private:
	bool IsValid(int board[9][9], int row, int col, int num);
	bool SolveSudoku(int board[9][9]);
	bool FindEmptyCell(int board[9][9], int& row, int& col);
};
