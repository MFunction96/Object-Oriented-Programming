#include "stdafx.h"
#include "Date.h"

Accumulator::Accumulator(const Date & date, double value) :lastdate(date), value(value), sum(0)
{

}

void Accumulator::Change(const Date & date, double value)
{
	sum = GetSum(date);
	lastdate = date;
	this->value = value;
}

void Accumulator::Reset(const Date & date, double value)
{
	lastdate = date;
	this->value = value;
	sum = 0;
}

double Accumulator::GetSum(const Date & date) const
{
	return sum + value * (date - lastdate);
}
