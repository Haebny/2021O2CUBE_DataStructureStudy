// O2StudyConsoleApplication.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 2021년 하계 자료구조 학술회에서 보여줄 실행 코드들이 작성됩니다.
// 2021-06-30 작성시작 ~ 진행중

#include <iostream>
#include "Simulator.h"
using namespace std;

int main()
{
	int x = 1;
	int y = 0;
	int *p = &x;

	*p = 0;

	Simulator* simulator = Simulator::GetInstance();
	simulator->SimulatorLoop();
}