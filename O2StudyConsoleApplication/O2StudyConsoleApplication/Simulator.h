#pragma once
#include "RecursiveFuncs.h"
#include "StackFuncs.h"
// #include "stddef.h" // nullptr대신 NULL 쓰고싶을 때!

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
	// 싱글톤
	static Simulator* instance;

	// 실행 관련 변수
	bool isPlaying = true;
	bool isChoosen = false;
	int key;
	RecursiveFuncs* recursionf;
	StackFuncs* stackf;

	Chapter chapter = NONE;	// 진행 챕터

private:
	Simulator();
	Simulator(const Simulator& other);
	~Simulator();

	// 러닝타임 중 해제 필요 시 사용
	static void Destroy();

	// 메인으로 돌아가기
	void GoMain();
	// 메세지 출력
	void SendMessage();

public:
	static Simulator* GetInstance();

	void SimulatorLoop();
};
