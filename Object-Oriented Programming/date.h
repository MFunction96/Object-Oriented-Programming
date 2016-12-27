#pragma once
#include "stdafx.h"
#include "Date.h"
#include <string>
using namespace std;

class Date
{
private:
	int year, month, day, totaldays;
public:
	Date(int year = 1, int month = 1, int day = 1);
	void Show() const;
	bool IsLeapYear() const;
	bool operator<(const Date & date) const;
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
	int GetMaxDay() const;
	int operator- (const Date & date) const;
};

istream & operator>>(istream & in, Date & date);
ostream & operator<<(ostream & out, const Date & date);