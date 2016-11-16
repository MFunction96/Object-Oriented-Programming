#pragma once
#include "stdafx.h"
#include "Date.h"
#include <string>
using namespace std;

class SavingsAccount : public Account
{
private:
	Accumulator acc;
	double rate;
protected:
	SavingsAccount(Date date, int id);
	void Record(Date date, double amount, string desc);
	void Error(string msg) const;
public:
	void Deposit(Date date, double amount, string desc);
	void Settle(Date date);
	void Show() const;
	void WithDraw(Date date, double amount, string desc);
	int GetID() const;
	double GetBalance() const;
	static double GetTotal();
};