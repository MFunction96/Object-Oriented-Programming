#pragma once
#include "stdafx.h"
#include "Date.h"
#include <string>
using namespace std;

class CreditAccount
{
private:
	Accumulator acc;
	double credit, rate, fee;
	double GetDebt() const;
public:
	CreditAccount(Date date, int id, double credit, double rate, double fee);
	double GetCredit() const;
	double GetRate() const;
	double GetFee() const;
	double GetAvailableCredit() const;
};