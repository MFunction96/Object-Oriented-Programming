// Object-Oriented Programming.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Date.h"
#include <string>
using namespace std;

int main()
{
	char cmd;
	int index, day, i;
	double amount;
	string desc;
	Date date = Date(2008, 11, 1);
	SavingsAccount sa1 = SavingsAccount(date, "S3755217", 0.015);
	SavingsAccount sa2 = SavingsAccount(date, "02342342", 0.015);
	CreditAccount ca = CreditAccount(date, "C5392394", 10000, 0.0005, 50);
	Account * accounts[] = { &sa1, &sa2, &ca };
	const int n = sizeof(accounts) / sizeof(Account);
	cout << "(D)Deposit (W)Withdraw (S)Show (C)Change day (N)Next month (E)Exit" << endl;
	date.Show();
	cout << "\tTotal：" << Account::GetTotal() << "\tcoomand>";
	while (cin >> cmd, cmd != 'e')
	{
		if (cmd == 'd')
		{
			cin >> index >> amount;
			getline(cin, desc, cin.widen('\n'));
			accounts[index]->Deposit(date, amount, desc);
		}
		else if (cmd == 'w')
		{
			cin >> index >> amount;
			getline(cin, desc, cin.widen('\n'));
			accounts[index]->Deposit(date, amount, desc);
		}
		else if (cmd == 's')
		{
			for (i = 0; i < n; i++)
			{
				cout << "[" << i << "]";
				accounts[i]->Show();
			}
		}
		else if (cmd == 'c')
		{
			cin >> day;
			if (day < date.GetDay())
			{
				cout << "You cannot specify a previous day" << endl;
			}
			else if (day > date.GetMaxDay())
			{
				cout << "Invalid day" << endl;
			}
			else
			{
				date = Date(date.GetYear(), date.GetMonth(), day);
			}
		}
		else if (cmd == 'n')
		{
			if (date.GetMonth() == 12)
			{
				date = Date(date.GetYear() + 1, 1, 1);
				for (i = 0; i < n; i++)
				{
					accounts[i]->Settle(date);
				}
			}
		}
		else cout << "Bad Command!" << endl;
		cout << "(D)Deposit (W)Withdraw (S)Show (C)Change day (N)Next month (E)Exit" << endl;
		date.Show();
		cout << "\tTotal：" << Account::GetTotal() << "\tcoomand>";
	}
    return 0;
}