#include "stdafx.h"

base1::base1(int i)
{
	cout << "Constructing Base1 " << i << endl;
}

base1::~base1()
{
	cout << "Destructing Base1" << endl;
}

base2::base2(int i)
{
	cout << "Constructing Base2 " << i << endl;
}

base2::~base2()
{
	cout << "Destructing Base2" << endl;
}

base3::base3()
{
	cout << "Constructing Base3* " << endl;
}

base3::~base3()
{
	cout << "Destructing Base3" << endl;
}
