#include "stdafx.h"
#include "Controller.h"

Controller::Controller(const Date & date) :date(date), end(false)
{

}

Controller::~Controller()
{
	for_each(accounts.begin(), accounts.end(), deleter());
}

const Date & Controller::GetDate() const
{
	return date;
}

bool Controller::IsEnd() const
{
	return end;
}

bool Controller::RunCommand(const string & cmdline)
{
	istringstream str(cmdline);
	char cmd, type;
	int index, day;
	double amount, credit, rate, fee;
	string id, desc;
	Account * account;
	Date date1, date2;
	str >> cmd;
	if (cmd == 'a')
	{
		str >> type >> id;
		if (type == 's')
		{
			str >> rate;
			account = new SavingsAccount(date, id, rate);
		}
		else
		{
			str >> credit >> rate >> fee;
			account = new CreditAccount(date, id, credit, rate, fee);
		}
		accounts.push_back(account);
		return true;
	}
	else if (cmd == 'd')
	{
		str >> index >> amount;
		getline(str, desc);
		accounts[index]->Deposit(date, amount, desc);
		return true;
	}
	else if (cmd == 'w')
	{
		str >> index >> amount;
		getline(str, desc);
		accounts[index]->WithDraw(date, amount, desc);
		return true;
	}
	else if (cmd == 's')
	{
		for (size_t i = 0; i < accounts.size(); i++)
		{
			cout << "[" << i << "]";
			accounts[i]->Show(cout);
			cout << end;
		}
		return false;
	}
	else if (cmd == 'c')
	{
		str >> day;
		if (day < date.GetDay()) cout << "You cannot specify a previous day";
		else if (day > date.GetMaxDay()) 
			cout << "Invaliday";
		else date = Date(date.GetYear(), date.GetMonth(), day);
		return true;
	}
	else if (cmd == 'n')
	{
		if (date.GetMonth() == 12) date = Date(date.GetYear() + 1, 1, 1);
		else date = Date(date.GetYear(), date.GetMonth() + 1, 1);
		for (vector<Account *>::iterator iter = accounts.begin(); iter != accounts.end(); iter++)
		{
			(*iter)->Settle(date);
		}
		return true;
	}
	else if (cmd == 'q')
	{
		str >> date1 >> date2;
		Account::Query(date1, date2);
		return false;
	}
	else if (cmd == 'e')
	{
		end = true;
		return false;
	}
	cout << "Invalid command£º" << cmdline << endl;
	return false;
}
