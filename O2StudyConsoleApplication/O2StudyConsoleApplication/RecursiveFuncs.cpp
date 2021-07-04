#include "RecursiveFuncs.h"
#include<iostream>
using namespace std;

RecursiveFuncs::RecursiveFuncs()
{
}

RecursiveFuncs::~RecursiveFuncs()
{
}

// ���丮�� ��� �Լ�
int RecursiveFuncs::Factorial(int n)
{
	// 1 ��ȯ
	if (n == 1 || n == 0)
		return 1;

	// ���丮�� ����(���)
	if (n > 1)
		return n * Factorial(n - 1);

	// ������ �Ӵ�!
	else
	{
		cout << "ERROR::�߸��� �Է�" << endl;
		return 0;
	}
}

// �ϳ����� ž �Լ�
void RecursiveFuncs::Hanoi(int num, int src, int tmp, int dest)
{
	if (num == 1)
	{
		printf("%d�� ������ %d�� ��տ��� %d�� ������� �ű�ϴ�.\n", num, src, dest);
		return;
	}

	if (num > 1)
	{
		Hanoi(num - 1, src, dest, tmp);
		printf("%d�� ������ %d�� ��տ��� %d�� ������� �ű�ϴ�.\n", num, dest, src);
		Hanoi(num - 1, tmp, src, dest);
	}
}