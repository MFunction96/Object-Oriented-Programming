#include "stdafx.h"
using namespace std;

double savingsaccount::total = 0;

void savingsaccount::Record(int date, double amount)
{
	ac = Accumulate(date);
	lastdate = date;
	amount = floor(amount * 100 + 0.5) / 100;
	balance += amount;
	total += amount;
	cout << date << "\t#" << id << '\t' << amount << '\t' << balance << endl;
}

savingsaccount::savingsaccount(int date, int id, double rate) :
	id(id), balance(0), rate(rate), lastdate(date), ac(0)
{
	cout << date << "\t#" << id << " is created!" << endl;
}

void savingsaccount::Deposit(int date, double amount)
{
	Record(date, amount);
}

void savingsaccount::WithDraw(int date, double amount)
{
	if (amount > GetBalance()) cout << "Error: not enough money" << endl;
	else Record(date, -amount);
}

void savingsaccount::Settle(int date)
{
	double interest = Accumulate(date) * rate / 365;
	if (interest) Record(date, interest);
	ac = 0;
}

void savingsaccount::Show()
{
	cout << '#' << id << "\tBalance:" << balance << endl;
}