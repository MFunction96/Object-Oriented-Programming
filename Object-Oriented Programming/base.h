#pragma once
class base1
{
public:
	base1(int i);
	~base1();
};

class base2
{
public:
	base2(int i);
	~base2();
};

class base3
{
public:
	base3();
	~base3();
};

class derived :public base2, public base1, public base3
{
private:
	base1 b1;
	base2 b2;
	base3 b3;
public:
	derived(int a, int b, int c, int d) : base1(a), b2(d), b1(c), base2(d){ }
};