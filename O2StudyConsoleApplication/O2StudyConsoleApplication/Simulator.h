#pragma once
#include "RecursiveFuncs.h"
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
	RecursiveFuncs* recursion;

	Chapter chapter = NONE;	// ���� é��

private:
	Simulator();
	Simulator(const Simulator& other);
	~Simulator();

	// ����Ÿ�� �� ���� �ʿ� �� ���
	static void Destroy();

	void GoMain(int key);

public:
	static Simulator* GetInstance();

	void SimulatorLoop();
};
