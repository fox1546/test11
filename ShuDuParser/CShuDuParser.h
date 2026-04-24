#pragma once

#define Res_OK 0
#define Res_Fail -1 //无解
#define Res_Wait 1 //待定
#define Res_SubOK 2 //确认部分值
#define Res_NoRes 3 //未确认值

class CShuDuParser
{
public:
	CShuDuParser();
	virtual ~CShuDuParser();

	//io_ShuDu:0-unknown val
	int Parse(int io_ShuDu[9][9]);

public:
	int m_iLevel;

private:
	int CreateCanbeArray();
	int Clear();
	int ClearByRow(int in_iIdx);
	int ClearByCulm(int in_iIdx);
	int ClearByBlock(int in_w,int in_h);
	int Check();

	void LogCanbeArray();

private:

	int m_iOrg[9][9];
	bool m_bCanbe[9][9][9];

};