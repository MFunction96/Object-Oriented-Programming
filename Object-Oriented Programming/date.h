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
	Date(int year, int month, int day);
	void Show() const;
	bool IsLeapYear() const ;
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
	int GetMaxDay() const;
	int operator- (const Date& date) const;
};