#pragma once
#include"stdafx.h"
using namespace std;

class savingsaccount 
{
private:
	int id, lastdate;
	double balance, rate, ac;
	static double total;
	void Record(int date, double amount);
	double Accumulate(int date) const
	{
		return ac + balance * (date - lastdate);
	}
public:
	savingsaccount(int date, int id, double rate);
	int GetID() const
	{
		return id;
	}
	double GetBalance() const
	{
		return balance;
	}
	double GetRate() const
	{
		return rate;
	}
	static double GetTotal()
	{
		return total;
	}
	void Deposit(int date, double amount);
	void WithDraw(int date, double amount);
	void Settle(int date);
	void Show();
};