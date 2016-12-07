#include "stdafx.h"

double Account::total = 0;

Account::Account(const Date & date, const string & id) :id(id), balance(0)
{
	date.Show();
	cout << "\t#" << id << " created" << endl;
}

void Account::Record(const Date & date, double amount, const string & desc)
{
	amount = floor(amount * 100 + 0.5) / 100;
	balance += amount;
	total += amount;
	date.Show();
	cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

void Account::Error(const string & msg) const
{
	cout << "Error(#" << id << "):" << msg << endl;
}

const string & Account::GetID() const
{
	return id;
}

double Account::GetBalance() const
{
	return balance;
}

double Account::GetTotal()
{
	return total;
}

void Account::Show() const
{
	cout << id << "\tBalance:" << balance << endl;
}
