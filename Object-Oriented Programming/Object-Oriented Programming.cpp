// Object-Oriented Programming.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Date.h"
#include <string>
using namespace std;

int main()
{
	Controller controller(Date(2008, 11, 1));
	string cmdline;
	const char * FILE_NAME = "Command.txt";
	ifstream filein(FILE_NAME);
	if (!filein.bad())
	{
		while (getline(filein, cmdline))
		{
			controller.RunCommand(cmdline);
		}
		filein.close();
	}
	//ofstream fileout(FILE_NAME, ios_base::app);
	cout << "(a)add account (d)deposit (w)withdraw (w)withdraw (s)show (c)change day (n)next month (q)query (e)exit" << endl;
	while (!controller.IsEnd())
	{
		//cout << controller.GetDate() << "\tTotal:" << Account::GetTotal() << "\tcommand>";
		//getline(cin, cmdline);
		//if (controller.RunCommand(cmdline))
		//{
		//	fileout << cmdline << endl;
		//}
		//fileout.close();
	}
    return 0;
}