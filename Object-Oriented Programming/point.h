#pragma once
class point
{
private:
	double x, y;
public:
	point(double x = 0, double y = 0);
	point Move(double x, double y);
	double GetX() const;
	double GetY() const;
};