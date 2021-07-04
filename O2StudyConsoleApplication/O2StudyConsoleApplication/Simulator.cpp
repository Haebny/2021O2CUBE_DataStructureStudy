#include "Simulator.h"
#include <iostream>
using namespace std;

Simulator::Simulator() :isPlaying(true), isChoosen(false)
{
}

Simulator::Simulator(const Simulator & other)
{
}

Simulator::~Simulator()
{
}

void Simulator::Destroy()
{
	delete instance;
}

void Simulator::GoMain()
{
	// 종료
	cout << "해당 챕터를 나갑니다." << endl << endl;
	isChoosen = false;
	key = NULL;
}

void Simulator::SendMessage()
{
	cout << "디버깅 모드에서만 실행 가능합니다." << endl << endl;
}

Simulator* Simulator::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new Simulator();
	}
	return instance;
}

void Simulator::SimulatorLoop()
{
	while (isPlaying)
	{
		if (!isChoosen)
		{
			cout << "Chapter 번호 선택(종료는 0번)" << endl
				<< "1. 재귀" << endl
				<< "2. 스택(디버깅 전용)" << endl
				<< "3. 큐" << endl
				<< "4. 연결리스트" << endl
				<< "5. 트리" << endl
				<< "6. 우선순위큐" << endl
				<< "7. 힙" << endl
				<< "8. 정렬 알고리즘" << endl
				<< "9. 해싱" << endl
				<< "------------------------------" << endl;

			cin >> key;
		}

		// 종료
		if (key == 0)
		{
			cout << "프로그램을 종료합니다." << endl;
			isPlaying = false;
			key = NULL;
			continue;
		}

		// 재귀 선택
		if (key == 1 && !isChoosen)
		{
			isChoosen = true;
			recursionf = new RecursiveFuncs();
			key = NULL;

			while (isChoosen)
			{
				// 함수 선택
				if (key == NULL)
				{
					cout << endl
						<< "Chapter 번호 선택(종료는 0번)" << endl
						<< "1. 팩토리얼" << endl
						<< "2. 하노이의 탑" << endl;
					cin >> key;
				}

				GoMain();

				// 팩토리얼 계산 함수 실행
				if (key == 1)
				{
					cout << endl << "몇 팩토리얼을 계산하겠습니까?(종료는 음수입력)" << endl;
					int n;
					cin >> n;

					// 종료
					if (n < 0)
					{
						cout << "해당 챕터를 나갑니다." << endl << endl;
						GoMain();
						continue;
					}

					cout << n << "! = " << recursionf->Factorial(n) << endl;
				}

				// 하노이의 탑 함수 실행
				if (key == 2)
				{
					cout << endl << "원반의 개수는 몇 개입니까?(종료는 음수입력) : ";
					int n;
					cin >> n;

					// 종료
					if (n < 0)
					{
						GoMain();
						continue;
					}

					cout << "원반의 개수: " << n << "개" << endl << endl;
					recursionf->Hanoi(n, 1, 2, 3);
				}
			}
			delete recursionf;
			continue;
		}

#ifndef _DEBUG
		if (key == 2 && !isChoosen)
		{
			SendMessage();
			continue;
		}

#else
		// 스택 선택
		if (key == 2 && !isChoosen)
		{
			isChoosen = true;
			stackf = new StackFuncs();
			key = NULL;

			while (isChoosen)
			{
				// 함수 선택
				if (key == NULL)
				{
					cout << endl
						<< "Chapter 번호 선택(종료는 0번)" << endl
						<< "1. 스택 프레임(변수)" << endl
						<< "2. 스택 프레임(재귀)" << endl;
					cin >> key;
				}

				if (key == 0)
				{
					key = NULL;
					isChoosen = false;
					GoMain();
					continue;
				}

				// 변수의 스택프레임 함수 실행
				if (key == 1)	stackf->StackFrameWorks1();

				// 하노이의 탑 함수 실행
				if (key == 2)	stackf->StackFrameWorks2();

				cout << "----- DONE -----" << endl << endl;
				GoMain();
				continue;
			}
			delete stackf;
			continue;
		}

#endif
	}
}

Simulator* Simulator::instance = nullptr;
// 주의::static 전역 변수처럼 main 호출 이전에 초기화
