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
	void Deposit(const Date & date, double amount, const string & desc);
	void Settle(const Date & date);
	void WithDraw(const Date & date, double amount, const string & desc);
	double GetRate() const;
};