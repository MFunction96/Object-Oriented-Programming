#include "stdafx.h"

double CreditAccount::GetDebt() const
{
	double balance = GetBalance();
	return balance < 0 ? balance : 0;
}

CreditAccount::CreditAccount(const Date & date, const string & id, double credit, double rate, double fee) :
	Account(date, id), credit(credit), rate(rate), fee(fee), acc(date, 0)
{

}

double CreditAccount::GetCredit() const
{
	return credit;
}

double CreditAccount::GetRate() const
{
	return rate;
}

double CreditAccount::GetFee() const
{
	return fee;
}

double CreditAccount::GetAvailableCredit() const
{
	if (GetBalance() < 0)
	{
		return credit + GetBalance();
	}
	else
	{
		return credit;
	}
}

void CreditAccount::Deposit(const Date & date, double amount, const string & desc)
{
	Record(date, amount, desc);
	acc.Change(date, GetDebt());
}

void CreditAccount::WithDraw(const Date & date, double amount, const string & desc)
{
	if (amount - GetBalance() > credit)
	{
		Error("not enough credit");
	}
	else
	{
		Record(date, -amount, desc);
		acc.Change(date, GetDebt());
	}
}

void CreditAccount::Settle(const Date & date)
{
	double interest = acc.GetSum(date) * rate;
	if (interest)
	{
		Record(date, interest, "interest");
	}
	if (date.GetMonth() == 1)
	{
		Record(date, -fee, "annual fee");
	}
	acc.Reset(date, GetDebt());
}

void CreditAccount::Show() const
{
	Account::Show();
	cout << "\tAvailable credit:" << GetAvailableCredit() << endl;
}
