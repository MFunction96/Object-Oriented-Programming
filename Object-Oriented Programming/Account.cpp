#include "stdafx.h"

double Account::total = 0;
RecordMap Account::recordmap;

Account::Account(const Date & date, const string & id) :id(id), balance(0)
{
	date.Show();
	cout << date << "\t#" << id << " created" << endl;
}

void Account::Record(const Date & date, double amount, const string & desc)
{
	amount = floor(amount * 100 + 0.5) / 100;
	balance += amount;
	total += amount;
	recordmap.insert(pair<Date, AccountRecord>(date, AccountRecord(date, this, amount, balance, desc)));
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

void Account::Query(const Date & begin, const Date & end)
{
	if (begin <= end)
	{
		RecordMap::iterator iter1 = recordmap.lower_bound(begin);
		RecordMap::iterator iter2 = recordmap.upper_bound(end);
		for (RecordMap::iterator iter = iter1; iter != iter2; iter++)
		{
			iter->second.Show();
		}
	}
}

void Account::Show(ostream & out) const
{
	out << id << "\tBalance:" << balance << endl;
}

inline ostream & operator<<(ostream & out, const Account & accout)
{
	accout.Show(out);
	return out;
}

AccountRecord::AccountRecord(const Date & date, const Account * account, double amount, double balance, const string desc) :
	date(date), account(account), amount(amount), balance(balance), desc(desc) 
{

}

void AccountRecord::Show() const
{
	date.Show();
	cout << date << "\t#" << account->GetID() << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}
