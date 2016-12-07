#include "stdafx.h"

SavingsAccount::SavingsAccount(const Date & date, const string & id, double rate) :Account(date, id), rate(rate), acc(date, 0)
{

}

void SavingsAccount::Deposit(const Date & date, double amount, const string & desc)
{
	Record(date, amount, desc);
	acc.Change(date, GetBalance());
}

void SavingsAccount::Settle(const Date & date)
{
	double interest = acc.GetSum(date) * rate / (date - Date(date.GetYear() - 1, 1, 1));
	if (interest)
	{
		Record(date, interest, "interest");
	}
	acc.Reset(date, GetBalance());
}

void SavingsAccount::WithDraw(const Date & date, double amount, const string & desc)
{
	if (amount > GetBalance())
	{
		Error("not enough money");
	}
	else
	{
		Record(date, -amount, desc);
		acc.Change(date, GetBalance());
	}
}

double SavingsAccount::GetRate() const
{
	return rate;
}