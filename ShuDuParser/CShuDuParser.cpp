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

//io_ShuDu:0-unknown val
int CShuDuParser::Parse(int io_ShuDu[9][9])
{
	int iRes = Res_OK;

	memcpy(m_iOrg,io_ShuDu,9*9*sizeof(int));

	//log
	{
		char czLog[1024];
		sprintf(czLog,"Parse lev %d begin input: \n",m_iLevel);
		OutputDebugStringA(czLog);
		for(int w=0;w<9;w++)
		{
			sprintf(czLog,"%d %d %d %d %d %d %d %d %d \n"
				,m_iOrg[w][0]
			,m_iOrg[w][1]
			,m_iOrg[w][2]
			,m_iOrg[w][3]
			,m_iOrg[w][4]
			,m_iOrg[w][5]
			,m_iOrg[w][6]
			,m_iOrg[w][7]
			,m_iOrg[w][8]
			);
			OutputDebugStringA(czLog);
		}
	}

	iRes = CreateCanbeArray();

	if(iRes == Res_OK)
	{
		bool bContinue = true;
		while(bContinue)
		{
			iRes = Clear();
			if(iRes == Res_OK || iRes == Res_Fail)
			{
				bContinue = false;
			}
		}
	}

	memcpy(io_ShuDu,m_iOrg,9*9*sizeof(int));

	//log
	{
		char czLog[1024];
		sprintf(czLog,"Parse lev %d end res %d output: \n",m_iLevel,iRes);
		OutputDebugStringA(czLog);
		for(int w=0;w<9;w++)
		{
			sprintf(czLog,"%d %d %d %d %d %d %d %d %d \n"
				,m_iOrg[w][0]
			,m_iOrg[w][1]
			,m_iOrg[w][2]
			,m_iOrg[w][3]
			,m_iOrg[w][4]
			,m_iOrg[w][5]
			,m_iOrg[w][6]
			,m_iOrg[w][7]
			,m_iOrg[w][8]
			);
			OutputDebugStringA(czLog);
		}
	}

	return iRes;
}

int CShuDuParser::CreateCanbeArray()
{
	int iRes = Res_OK;

	for(int h=0;h<9;h++)
	{
		for(int w=0;w<9;w++)
		{
			if(m_iOrg[w][h] == 0)
			{
				for(int i=0;i<9;i++)
				{
					m_bCanbe[w][h][i] = true;
				}
			}
			else
			{
				for(int i=0;i<9;i++)
				{
					if(i+1 == m_iOrg[w][h])
					{
						m_bCanbe[w][h][i] = true;
					}
					else
					{
						m_bCanbe[w][h][i] = false;
					}				
				}
			}
		}
	}

	return iRes;
}

int CShuDuParser::Clear()
{
	int iRes = Res_OK;

	for(int w=0;w<9;w++)
	{
		iRes = ClearByRow(w);
	}

	for(int h=0;h<9;h++)
	{
		iRes = ClearByCulm(h);
	}

	for(int bw=0;bw<3;bw++)
	{
		for(int bh=0;bh<3;bh++)
		{
			iRes = ClearByBlock(bw,bh);
		}
	}

	iRes = Check();
	if(iRes == Res_NoRes)
	{
		//try
		int tmpOry[9][9];
		memcpy(tmpOry,m_iOrg,9*9*sizeof(int));

		int h = 0;
		int w = 0;
		int val = 0;

		bool bFind = false;
		for(int tw=0;tw<9;tw++)
		{
			for(int th=0;th<9;th++)
			{
				if(m_iOrg[tw][th] == 0)
				{
					bFind = true;

					h = th;
					w = tw;

					for(int i=0;i<9;i++)
					{
						if(m_bCanbe[tw][th][i])
						{
							val = i+1;
							break;
						}
					}

					break;
				}
			}

			if(bFind)
			{
				break;
			}
		}

		tmpOry[w][h] = val;
		//log
		{
			char czLog[1024];
			sprintf(czLog,"Try w%d h%d v%d \n",w,h,val);
			OutputDebugStringA(czLog);
		}

		//LogCanbeArray();

		//
		CShuDuParser parser;
		parser.m_iLevel = m_iLevel+1;
		iRes = parser.Parse(tmpOry);
		if(iRes == Res_OK)
		{
			memcpy(m_iOrg,tmpOry,9*9*sizeof(int));
		}
		else if(iRes == Res_Fail)
		{
			m_bCanbe[w][h][val-1] = false;
			iRes = Res_Wait;

			//LogCanbeArray();

			//log
			{
				char czLog[1024];
				sprintf(czLog,"Try w%d h%d v%d failed \n",w,h,val);
				OutputDebugStringA(czLog);
			}
		}
	}

	return iRes;
}

int CShuDuParser::ClearByRow(int in_iIdx)
{
	int iRes = Res_OK;

	for(int h=0;h<9;h++)
	{
		if(m_iOrg[in_iIdx][h] != 0)
		{
			for(int th=0;th<9;th++)
			{
				m_bCanbe[in_iIdx][th][m_iOrg[in_iIdx][h]-1] = false;
			}
		}
	}

	return iRes;
}

int CShuDuParser::ClearByCulm(int in_iIdx)
{
	int iRes = Res_OK;

	for(int w=0;w<9;w++)
	{
		if(m_iOrg[w][in_iIdx] != 0)
		{
			for(int tw=0;tw<9;tw++)
			{
				m_bCanbe[tw][in_iIdx][m_iOrg[w][in_iIdx]-1] = false;
			}
		}
	}

	return iRes;
}

int CShuDuParser::ClearByBlock(int in_w,int in_h)
{
	int iRes = S_OK;

	for(int w=0;w<3;w++)
	{
		for(int h=0;h<3;h++)
		{
			if(m_iOrg[in_w*3+w][in_h*3+h] != 0)
			{
				for(int tw=0;tw<3;tw++)
				{
					for(int th=0;th<3;th++)
					{
						m_bCanbe[in_w*3+tw][in_h*3+th][m_iOrg[in_w*3+w][in_h*3+h]-1] = false;
					}
				}
			}
		}
	}

	return iRes;
}

int CShuDuParser::Check()
{
	bool bSubOK = false;
	for(int w=0;w<9;w++)
	{
		for(int h=0;h<9;h++)
		{
			if(m_iOrg[w][h] == 0)
			{
				int iHasValueCount = 0;
				int iValue = 0;
				for(int i=0;i<9;i++)
				{
					if(m_bCanbe[w][h][i])
					{
						iHasValueCount++;
						iValue = i+1;
					}
				}

				if(iHasValueCount == 0)
				{
					return Res_Fail;
				}
				else if(iHasValueCount == 1) //唯一值，表示确认
				{
					bSubOK = true;
					m_iOrg[w][h] = iValue;

					//log
					{
						char czLog[1024];
						sprintf(czLog,"Find Value w%d h%d v%d \n",w,h,iValue);
						OutputDebugStringA(czLog);
					}
				}
			}
		}
	}

	bool bAllOK = true;
	for(int w=0;w<9;w++)
	{
		for(int h=0;h<9;h++)
		{
			if(m_iOrg[w][h] == 0)
			{
				bAllOK = false;
				break;
			}
		}

		if(!bAllOK)
		{
			break;
		}
	}

	if(bAllOK)
	{
		return Res_OK;
	}

	if(bSubOK)
	{
		return Res_SubOK;
	}

	return Res_NoRes;
}

void CShuDuParser::LogCanbeArray()
{
	char czLog[1024];
	sprintf(czLog,"Lev %d CanbeArray begin: \n",m_iLevel);
	OutputDebugStringA(czLog);

	for(int w=0;w<9;w++)
	{
		for(int h=0;h<9;h++)
		{
			sprintf(czLog,"CanbeArray[%d][%d]:",w,h);
			OutputDebugStringA(czLog);

			for(int i=0;i<9;i++)
			{
				if(m_bCanbe[w][h][i])
				{
					sprintf(czLog," %d",i+1);
					OutputDebugStringA(czLog);
				}
			}

			sprintf(czLog,"\n");
			OutputDebugStringA(czLog);
		}
	}

	sprintf(czLog,"Lev %d CanbeArray end: \n",m_iLevel);
	OutputDebugStringA(czLog);
}