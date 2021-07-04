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
	// ����
	cout << "�ش� é�͸� �����ϴ�." << endl << endl;
	isChoosen = false;
	key = NULL;
}

void Simulator::SendMessage()
{
	cout << "����� ��忡���� ���� �����մϴ�." << endl << endl;
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
			cout << "Chapter ��ȣ ����(����� 0��)" << endl
				<< "1. ���" << endl
				<< "2. ����(����� ����)" << endl
				<< "3. ť" << endl
				<< "4. ���Ḯ��Ʈ" << endl
				<< "5. Ʈ��" << endl
				<< "6. �켱����ť" << endl
				<< "7. ��" << endl
				<< "8. ���� �˰���" << endl
				<< "9. �ؽ�" << endl
				<< "------------------------------" << endl;

			cin >> key;
		}

		// ����
		if (key == 0)
		{
			cout << "���α׷��� �����մϴ�." << endl;
			isPlaying = false;
			key = NULL;
			continue;
		}

		// ��� ����
		if (key == 1 && !isChoosen)
		{
			isChoosen = true;
			recursionf = new RecursiveFuncs();
			key = NULL;

			while (isChoosen)
			{
				// �Լ� ����
				if (key == NULL)
				{
					cout << endl
						<< "Chapter ��ȣ ����(����� 0��)" << endl
						<< "1. ���丮��" << endl
						<< "2. �ϳ����� ž" << endl;
					cin >> key;
				}

				GoMain();

				// ���丮�� ��� �Լ� ����
				if (key == 1)
				{
					cout << endl << "�� ���丮���� ����ϰڽ��ϱ�?(����� �����Է�)" << endl;
					int n;
					cin >> n;

					// ����
					if (n < 0)
					{
						cout << "�ش� é�͸� �����ϴ�." << endl << endl;
						GoMain();
						continue;
					}

					cout << n << "! = " << recursionf->Factorial(n) << endl;
				}

				// �ϳ����� ž �Լ� ����
				if (key == 2)
				{
					cout << endl << "������ ������ �� ���Դϱ�?(����� �����Է�) : ";
					int n;
					cin >> n;

					// ����
					if (n < 0)
					{
						GoMain();
						continue;
					}

					cout << "������ ����: " << n << "��" << endl << endl;
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
		// ���� ����
		if (key == 2 && !isChoosen)
		{
			isChoosen = true;
			stackf = new StackFuncs();
			key = NULL;

			while (isChoosen)
			{
				// �Լ� ����
				if (key == NULL)
				{
					cout << endl
						<< "Chapter ��ȣ ����(����� 0��)" << endl
						<< "1. ���� ������(����)" << endl
						<< "2. ���� ������(���)" << endl;
					cin >> key;
				}

				if (key == 0)
				{
					key = NULL;
					isChoosen = false;
					GoMain();
					continue;
				}

				// ������ ���������� �Լ� ����
				if (key == 1)	stackf->StackFrameWorks1();

				// �ϳ����� ž �Լ� ����
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
// ����::static ���� ����ó�� main ȣ�� ������ �ʱ�ȭ
