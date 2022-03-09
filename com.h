#ifndef COM_H_INCLUDED
#define COM_H_INCLUDED

using namespace std;
#define cls system("cls")
#include<string>
#include<map>
#include<deque>
#include <bitset>
#include<math.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include <stdio.h>
#include <iostream>
class FatherComputer
{
public:

	virtual void name()=0;
	string cname = "father computer";
	FatherComputer();
	void read();
};

class miniComputer : public FatherComputer
{
	void name();
	string cname = "minComputer";
};
class Computer : public FatherComputer
{
public:
	string cname = "computer";
	void name();
	map <string, string> cmd;
	class Data
	{
	public:
		int type;
		/*
		1.整数
		2.小数
		3.指令
		4.表达式
		5.程序
		*/
		double v1;
		string v2;
		Data(string in = "")

		{
			while (in.length() && in[0] == ' ')in = in.c_str() + 1;
			while (in.length() && in.back() == ' ')in.pop_back();
			if (in == "")return;
			if ((in[0] >= 'A' && in[0] <= 'Z') || in[0] == '+' || (in[0] == '-' && in.length() == 1) || in[0] == '*' || in[0] == '/' || in[0] == '<' || in[0] == '>' || in[0] == '=' || in[0] == '!')type = 3;
			else if (in[0] == '"')type = 4;
			else if (in[0] == '[')type = 5;
			else
			{
				type = 2;
				sscanf(in.c_str(), "%lf", &v1);
				if (v1 - (int)v1 <= 1e-9)type = 1, v1 = int(v1);
			}
			v2 = in;
		}
		Data(double in)
		{
			type = 2;
			if (fabs(in - (int)in) <= 1e-9)type = 1;
			v1 = in;
		}
		Data explain();

	};
	deque <Data> q;
	string op;
	void refresh();
	void getval(int num, Data ans[]);
	void solve(Data x, int debug = 0);//执行
};

class Exe
{
public:
	void execulter(Computer a);
};

#endif // COM_H_INCLUDED
