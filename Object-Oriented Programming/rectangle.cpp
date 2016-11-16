#include "stdafx.h"

//Public Inheritance

//rectangle::rectangle(double x, double y, double w, double h)
//{
//	point(x, y);
//	this->w = w;
//	this->h = h;
//}
//
//double rectangle::GetW() const
//{
//	return w;
//}
//
//double rectangle::GetH() const
//{
//	return h;
//}

//Private Inheritance

rectangle::rectangle(double x, double y, double w, double h)
{
	point(x, y);
	this->w = w;
	this->h = h;
}

void rectangle::Move(double x, double y)
{
	point::Move(x, y);
}

double rectangle::GetX() const
{
	return point::GetX();
}

double rectangle::GetY() const
{
	return point::GetY();
}

double rectangle::GetW() const
{
	return w;
}

double rectangle::GetH() const
{
	return h;
}

//Protected Inheritance
//
//rectangle::rectangle(double x, double y, double w, double h)
//{
//	point(x, y);
//	this->w = w;
//	this->h = h;
//}
//
//void rectangle::Move(double x, double y)
//{
//	point::Move(x, y);
//}
//
//double rectangle::GetX() const
//{
//	return point::GetX();
//}
//
//double rectangle::GetY() const
//{
//	return point::GetY();
//}
//
//double rectangle::GetW() const
//{
//	return w;
//}
//
//double rectangle::GetH() const
//{
//	return h;
//}