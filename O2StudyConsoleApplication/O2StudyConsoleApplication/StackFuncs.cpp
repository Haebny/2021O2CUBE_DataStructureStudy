#include "StackFuncs.h"
#include <iostream>
#include <iomanip>
using namespace std;

StackFuncs::StackFuncs() : size(5)
{
}

StackFuncs::~StackFuncs()
{
}

void StackFuncs::StackFrameWorks1()
{
	int x = 1;
	int y = 0;
	int *p = &x;

	*p = 0;
	// f5 ������!
}

void StackFuncs::StackFrameWorks2()
{
	if (size > 0)
	{
		size--;
		cout << 5 - size << "��° ȣ��!" << endl;
		StackFrameWorks2();
	}
	else
		size = 5;
	cout << "����!" << endl;
	return;

}
