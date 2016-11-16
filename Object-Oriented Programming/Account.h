#pragma once
#include "stdafx.h"
#include "Date.h"
#include <string>
using namespace std;

class Account
{
private:
	string id;
	double balance;
	static double total;
protected:
	Account(Date date, int id);
	void Record(Date date, double amount, string desc);
	void Error(string msg) const;
public:
	int GetID() const;
	double GetBalance() const;
	static double GetTotal();
	virtual void Deposit(int Date, double amount);
	virtual void WithDraw(int Date, double amount);
	virtual void Settle(int Date);
	virtual void Show();
};