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
// #include <sys/wait.h>
// #include <sys/types.h>
// #include <unistd.h>
using namespace std;

/* Variable explain:

*/

int main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	FatherComputer *computer;
	Computer powerful_computer;
	miniComputer mini_computer;
	while (1) {
		cout << "input 1:choose mini computer" << endl;
		cout << "intput 2:choose powerful computer" << endl;
		int choose;
		cin >> choose;
		if (choose == 1) {
			computer = &mini_computer;
			computer->name();
		}
		else {
			computer = &powerful_computer;
			computer->name();
			Exe exe;
			exe.execulter(powerful_computer);
		}
	}
	Computer a;
	Exe exe;
	exe.execulter(a);
	/*
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
	*/
	return 0;
}
