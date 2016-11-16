#include "stdafx.h"

point::point(double x, double y)
{
	this->x = x;
	this->y = y;
}

point point::Move(double x, double y)
{
	this->x += x;
	this->y += y;
	return point(this->x, this->y);
}

double point::GetX() const
{
	return x;
}

double point::GetY() const
{
	return y;
}