#pragma once
#include "stdafx.h"
#include "Date.h"
#include <string>
using namespace std;

class CreditAccount : public Account
{
private:
	Accumulator acc;
	double credit, rate, fee;
	double GetDebt() const;
public:
	CreditAccount(const Date & date, const string & id, double credit, double rate, double fee);
	double GetCredit() const;
	double GetRate() const;
	double GetFee() const;
	double GetAvailableCredit() const;
	void Deposit(const Date & date, double amount, const string & desc);
	void WithDraw(const Date & date, double amount, const string & desc);
	void Settle(const Date &date);
	void Show() const;
};