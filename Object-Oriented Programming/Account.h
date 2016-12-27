#pragma once
#include "stdafx.h"
#include "Date.h"
#include <string>
using namespace std;

class Account;

inline ostream & operator<<(ostream & out, const Account & accout);

class AccountRecord
{
private:
	Date date;
	const Account * account;
	double amount;
	double balance;
	string desc;
public:
	AccountRecord(const Date & date, const Account * account, double amount, double balance, const string desc);
	void Show() const;
};

typedef multimap<Date, AccountRecord> RecordMap;

class Account
{
private:
	string id;
	double balance;
	static double total;
	static RecordMap recordmap;
protected:
	Account(const Date & date, const string & id);
	void Record(const Date & date, double amount, const string & desc);
	void Error(const string & msg) const;
public:
	const string & GetID() const;
	double GetBalance() const;
	static double GetTotal();
	static void Query(const Date & begin, const Date & end);
	virtual void Deposit(const Date & date, double amount, const string & desc) = 0;
	virtual void WithDraw(const Date & date, double amount, const string & desc) = 0;
	virtual void Settle(const Date & date) = 0;
	virtual void Show(ostream & out) const;
};