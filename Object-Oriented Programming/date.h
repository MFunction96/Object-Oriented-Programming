#pragma once
#include <ctime>


class date
{
private:
	
	int year, month, day, totaldays;
public:
	date(int year, int month, int day);
	Date
	const void Show();
	const bool IsLeapYear();
	const int GetYear();
	const int GetMonth();
	const int GetDay();
	const int GetMaxDay();
	const int Distance(date date);
};