#include "stdafx.h"

date::date(int year, int month, int day) : year(year), month(month), day(day)
{
	if (day <= 0 || day > GetMaxDay())
	{
		cout << "Invalid date:";
		Show();
		cout << endl;
		exit(ERROR_INVALID_FUNCTION);
	}
	int years = year - 1;
	totaldays = years * 365 + years / 4 - years / 100 + years / 400;
}

const void date::Show()
{
	return void();
}

const int date::GetYear()
{
	return 0;
}

const int date::GetMonth()
{
	return 0;
}

const int date::GetDay()
{
	return 0;
}

const int date::GetMaxDay()
{
	return 0;
}

const int date::Distance(date date)
{
	return 0;
}
