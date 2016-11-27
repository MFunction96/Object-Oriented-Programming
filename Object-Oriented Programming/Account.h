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
	Account(const Date & date, const string & id);
	void Record(const Date & date, double amount, const string & desc);
	void Error(const string & msg) const;
public:
	const string & GetID() const;
	double GetBalance() const;
	static double GetTotal();
	virtual void Deposit(const Date & date, double amount, const string & desc) = 0;
	virtual void WithDraw(const Date & date, double amount, const string & desc) = 0;
	virtual void Settle(const Date & date) = 0;
	virtual void Show() const;
};