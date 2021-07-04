#pragma once
class RecursiveFuncs
{
private:

public:
	RecursiveFuncs();
	~RecursiveFuncs();

	int Factorial(int n);
	void Hanoi(int num, int src, int tmp, int dest);
};