#pragma once
#include "RecursiveFuncs.h"
#include "StackFuncs.h"
// #include "stddef.h" // nullptr��� NULL ������� ��!

enum Chapter
{
	NONE = 0,
	RECURSION,
	STACK,
	QUEUE,
	LINKED_LIST,
	TREE,
	PRIORITY_QUEUE,
	HEAP,
	SORTING,
	HASHING
};

class Simulator
{
private:
	// �̱���
	static Simulator* instance;

	// ���� ���� ����
	bool isPlaying = true;
	bool isChoosen = false;
	int key;
	RecursiveFuncs* recursionf;
	StackFuncs* stackf;

	Chapter chapter = NONE;	// ���� é��

private:
	Simulator();
	Simulator(const Simulator& other);
	~Simulator();

	// ����Ÿ�� �� ���� �ʿ� �� ���
	static void Destroy();

	// �������� ���ư���
	void GoMain();
	// �޼��� ���
	void SendMessage();

public:
	static Simulator* GetInstance();

	void SimulatorLoop();
};
