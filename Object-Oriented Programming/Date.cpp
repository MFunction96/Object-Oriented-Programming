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

bool Date::operator<(const Date & date) const
{
	return totaldays < date.totaldays;
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

istream & operator >> (istream & in, Date & date)
{
	char c1, c2;
	int year, month, day;
	in >> year >> c1 >> month >> c2 >> day;
	date = Date(year, month, day);
	return in;
}

ostream & operator<<(ostream & out, const Date & date)
{
	out << date.GetYear() << "-" << date.GetMonth() << "-" << date.GetDay();
	return out;
}
