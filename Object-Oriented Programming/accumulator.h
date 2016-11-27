#pragma once
#include "stdafx.h"
#include "Date.h"
#include <string>
using namespace std;

class Accumulator
{
private:
	double sum, value;
	Date lastdate;
public:
	Accumulator(const Date & date, double value);
	void Change(const Date & date, double value);
	void Reset(const Date & date, double value);
	double GetSum(const Date &date) const;
};