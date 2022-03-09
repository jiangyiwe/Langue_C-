#define _CRT_SECURE_NO_DEPRECATE
/************************
*创建时间：2020 10
*文件类型：源代码文件


************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <map>
#include <math.h>
#include "com.h"
using namespace std;
#define cls system("cls")

//minicomputer函数实现
void miniComputer::name()
{
	cout << "this is a mini computer,  it is useless!" << endl;
}

//Exe函数实现
void Exe::execulter(Computer a)
{
	a.read();
	a.refresh();
	while (1)
	{
		char ls1[100] = "";
		int flag = 0, len = 0;
		while (1)
		{
			scanf("%s", ls1 + len);
			for (int i = len; ls1[i] == '['; ++i)++flag;
			len = strlen(ls1) + 1;
			for (int i = len - 2; ls1[i] == ']'; --i)--flag;
			if (!flag)break;
			ls1[len - 1] = ' ';
		}

		a.solve(Computer::Data(ls1));
		a.refresh();
	}
}
//computer函数实现
void Computer::name()
{
	cout << "this is a powerful computer, it is useful" << endl;
}
Computer::Data Computer::Data::explain() {
	Data ans = *this;
	if (type > 3)
	{
		ans.v2 = ans.v2.c_str() + 1;
		ans.v2.pop_back();
		while (ans.v2[0] == ' ')ans.v2 = ans.v2.c_str() + 1;
		while (ans.v2.back() == ' ')ans.v2.pop_back();
	}
	return ans;
}

//fathercomputer函数实现
/*
void FatherComputer::name()
{
	cout << "this a father computer, you shouldn't use it directly" << endl;
}
*/
void FatherComputer::read()
{

	return;
}
void Computer::refresh()
{
	cls;
	cout << "OutPut:" << op << "\n--------------------\n";
	for (int i = 5; i; --i)
	{
		cout << i << ':';
		if (q.size() >= i)
		{
			Data now = q[q.size() - i];
			if (now.type == 1)cout << (int)now.v1;
			else if (now.type == 2)cout << now.v1;
			else cout << now.v2;
		}
		cout << endl;
	}
	cout << "--------------------\n";
}

void Computer::getval(int num, Data ans[])
{
	for (int i = 1; i <= num; ++i)
	{
		ans[i] = q.back();
		q.pop_back();
	}
	for (int i = 1; i <= num; ++i)
	{
		solve(ans[i]);
	}
	for (int i = 1; i <= num; ++i)
	{
		ans[i] = q.back();
		q.pop_back();
	}
}
void Computer::solve(Data x, int debug)//执行
{
	// if(debug)printf("Solve: %d %f %s\n",x.type,x.v1,x.v2.c_str());
	if (x.type <= 2 || x.type == 4)
	{
		q.push_back(x);
	}
	else if (x.type == 3)
	{
		if (x.v2 == "+")
		{
			Data a[3];
			getval(2, a);
			solve(Data(a[1].v1 + a[2].v1));
		}
		else if (x.v2 == "-")
		{
			Data a[3];
			getval(2, a);
			solve(Data(a[1].v1 - a[2].v1));
		}
		else if (x.v2 == "*")
		{
			Data a[3];
			getval(2, a);
			solve(Data(a[1].v1 * a[2].v1));
		}
		else if (x.v2 == "/")
		{
			Data a[3];
			getval(2, a);
			if (a[2].v1 != 0)solve(Data(a[1].v1 / a[2].v1));
			else
			{
				solve(a[1]);
				solve(a[2]);
				op = "操作无效";
			}
		}
		else if (x.v2 == "DIV")
		{
			Data a[3];
			getval(2, a);
			if ((int)a[2].v1 != 0)solve(Data((int)a[1].v1 / (int)a[2].v1));
			else
			{
				solve(a[1]);
				solve(a[2]);
				op = "操作无效";
			}
		}
		else if (x.v2 == "MOD")
		{
			Data a[3];
			getval(2, a);
			if ((int)a[2].v1 != 0)solve(Data((int)a[1].v1 % (int)a[2].v1));
			else
			{
				solve(a[1]);
				solve(a[2]);
				op = "操作无效";
			}
		}
		else if (x.v2 == "NEG")
		{
			Data a[3];
			getval(1, a);
			solve(Data(-a[1].v1));
		}
		else if (x.v2 == "POW")
		{
			Data a[3];
			getval(2, a);
			solve(Data(pow(a[1].v1, a[2].v1)));
		}
		else if (x.v2 == "SQRT")
		{
			Data a[3];
			getval(1, a);
			solve(Data(sqrt(a[1].v1)));
		}
		else if (x.v2 == "EXP")
		{
			Data a[3];
			getval(1, a);
			solve(Data(exp(a[1].v1)));
		}
		else if (x.v2 == "LN")
		{
			Data a[3];
			getval(1, a);
			solve(Data(log(a[1].v1) / log(exp(1))));
		}
		else if (x.v2 == "=")
		{
			Data a[3];
			getval(2, a);
			solve(Data(a[1].v1 == a[2].v1));
		}
		else if (x.v2 == "!=")
		{
			Data a[3];
			getval(2, a);
			solve(Data(a[1].v1 != a[2].v1));
		}
		else if (x.v2 == "<")
		{
			Data a[3];
			getval(2, a);
			solve(Data(a[1].v1 < a[2].v1));
		}
		else if (x.v2 == ">")
		{
			Data a[3];
			getval(2, a);
			solve(Data(a[1].v1 > a[2].v1));
		}
		else if (x.v2 == "<=")
		{
			Data a[3];
			getval(2, a);
			solve(Data(a[1].v1 <= a[2].v1));
		}
		else if (x.v2 == ">=")
		{
			Data a[3];
			getval(2, a);
			solve(Data(a[1].v1 >= a[2].v1));
		}
		else if (x.v2 == "AND")
		{
			Data a[3];
			getval(2, a);
			solve(Data((int)a[1].v1 & (int)a[2].v1));
		}
		else if (x.v2 == "OR")
		{
			Data a[3];
			getval(2, a);
			solve(Data((int)a[1].v1 | (int)a[2].v1));
		}
		else if (x.v2 == "NOT")
		{
			Data a[3];
			getval(1, a);
			solve(Data(!a[1].v1));
		}
		else if (x.v2 == "EVAL")
		{
			Data a[3];
			getval(1, a);
			solve(a[1].explain(), 1);
		}
		else if (x.v2 == "DUP")
		{
			q.push_back(q.back());
		}
		else if (x.v2 == "DROP")
		{
			q.pop_back();
		}
		else if (x.v2 == "SWAP")
		{
			swap(*(q.end() - 1), *(q.end() - 2));
		}
		else if (x.v2 == "CLEAR")
		{
			q.clear();
		}
		else if (x.v2 == "IFT")
		{
			Data a[3];
			getval(2, a);
			if (a[1].v1)solve(a[2].explain());
		}
		else if (x.v2 == "STO")
		{
			Data a[3];
			getval(2, a);
			cmd[a[2].explain().v2] = a[1].v2;
		}
		else if (x.v2 == "FORGET")
		{
			Data a[3];
			getval(1, a);
			cmd[a[2].explain().v2] = "";
		}
		else
		{
			solve(Data(cmd[x.v2]).explain());
		}
	}
	else if (x.type == 5)
	{
		// printf("执行:%s\n",x.v2.c_str());
		int flag = 0;
		string now = "";
		for (int i = 0; i < x.v2.length(); ++i)
		{
			if (x.v2[i] == '[')++flag;
			if (!flag && x.v2[i] == ' ' && now != "") { solve(Data(now), 1), now = ""; continue; }
			now += x.v2[i];
			if (x.v2[i] == ']')
			{
				--flag;
				if (!flag)q.push_back(Data(now)), now = "";
			}
		}
		if (now != "" && now != " ")solve(Data(now), 1);
	}
	// if(debug)refresh();
}

FatherComputer::FatherComputer()
{
	cout << "create a computer" << endl << endl;
}
