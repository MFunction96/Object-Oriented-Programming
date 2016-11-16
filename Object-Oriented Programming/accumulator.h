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
	Accumulator(Date date, double value);
	void Change(Date date, double value);
	void Reset(Date date, double value);
	double GetSum(Date date) const;
};