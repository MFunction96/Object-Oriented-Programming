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
public:
	SavingsAccount(const Date & date, const string & id, double rate);
	void Deposit(Date date, double amount, string desc);
	void Settle(Date date);
	void WithDraw(Date date, double amount, string desc);
	double GetRate() const;
};