#pragma once
#include "point.h"

//Public Inheritance

//class rectangle :public point
//{
//private:
//	double w, h;
//public:
//	rectangle(double x, double y, double w, double h);
//	double GetW() const;
//	double GetH() const;
//};

//Private Inheritance
class rectangle :private point
{
private:
	double w, h;
public:
	rectangle(double x, double y, double w, double h);
	void Move(double x, double y);
	double GetX() const;
	double GetY() const;
	double GetW() const;
	double GetH() const;
};

//Protected Inheritance
//class rectangle :protected point
//{
//private:
//	double w, h;
//public:
//	rectangle(double x, double y, double w, double h);
//	void Move(double x, double y);
//	double GetX() const;
//	double GetY() const;
//	double GetW() const;
//	double GetH() const;
//};