#pragma once
#include "stdafx.h"
#include "Date.h"
#include <string>
using namespace std;

struct deleter
{
	template<class T>void operator()(T * p)
	{
		delete p;
	}
};

class Controller
{
private:
	bool end;
	Date date;
	vector<Account *> accounts;
public:
	Controller(const Date & date);
	~Controller();
	const Date & GetDate() const;
	bool IsEnd() const;
	bool RunCommand(const string & cmdline);
};