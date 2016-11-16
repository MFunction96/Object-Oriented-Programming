// Object-Oriented Programming.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;

void Base()
{
	derived d(1, 2, 3, 4);
}

void Rectangle()
{
	rectangle rect(2, 3, 20, 10);
	rect.Move(3, 2);
	cout << "The data of rect(x, y, w, h):" << endl;
	cout << rect.GetX() << ", "
		<< rect.GetY() << ", "
		<< rect.GetW() << ", "
		<< rect.GetH() << endl;
}

int main()
{
	Rectangle();
	Base();
    return 0;
}