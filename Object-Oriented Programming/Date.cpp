#include "stdafx.h"

namespace
{
	const int DAYS_BEFORE_MONTH[] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
}

Date::Date(int year, int month, int day) : year(year), month(month), day(day)
{
	if (day <= 0 || day > GetMaxDay())
	{
		cout << "Invalid date:";
		Show();
		cout << endl;
		exit(ERROR_INVALID_FUNCTION);
	}
	int years = year - 1;
	totaldays = years * 365 + years / 4 - years / 100 + years / 400 + DAYS_BEFORE_MONTH[month - 1] + day;
	if (IsLeapYear() && month > 2) totaldays++;
}

void Date::Show() const
{
	cout << GetYear() << "-" << GetMonth() << "-" << GetDay();
}

bool Date::IsLeapYear() const
{
	return year % 4 == 0 && year % 100 || year % 400 == 0;
}

int Date::GetYear() const
{
	return year;
}

int Date::GetMonth() const
{
	return month;
}

int Date::GetDay() const
{
	return day;
}

int Date::GetMaxDay() const
{
	if (IsLeapYear() && month == 2) return 29;
	else return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1];
}

int Date::operator-(const Date & date) const
{
	return totaldays - date.totaldays;
}
