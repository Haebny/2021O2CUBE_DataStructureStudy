#include "RecursiveFuncs.h"
#include<iostream>
using namespace std;

RecursiveFuncs::RecursiveFuncs()
{
}

RecursiveFuncs::~RecursiveFuncs()
{
}

// 팩토리얼 계산 함수
int RecursiveFuncs::Factorial(int n)
{
	// 1 반환
	if (n == 1 || n == 0)
		return 1;

	// 팩토리얼 연산(재귀)
	if (n > 1)
		return n * Factorial(n - 1);

	// 음수는 앙대!
	else
	{
		cout << "ERROR::잘못된 입력" << endl;
		return 0;
	}
}

// 하노이의 탑 함수
void RecursiveFuncs::Hanoi(int num, int src, int tmp, int dest)
{
	if (num == 1)
	{
		printf("%d번 원반을 %d번 기둥에서 %d번 기둥으로 옮깁니다.\n", num, src, dest);
		return;
	}

	if (num > 1)
	{
		Hanoi(num - 1, src, dest, tmp);
		printf("%d번 원반을 %d번 기둥에서 %d번 기둥으로 옮깁니다.\n", num, dest, src);
		Hanoi(num - 1, tmp, src, dest);
	}
}