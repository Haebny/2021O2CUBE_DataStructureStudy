// O2StudyConsoleApplication.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 2021년 하계 자료구조 학술회에서 보여줄 실행 코드들이 작성됩니다.
// 2021-06-30 작성시작 ~ 진행중
#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include "Simulator.h"
using namespace std;

// 벡터 연산자 오버로딩
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	os << "[";
	for (int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i != v.size() - 1)
			os << ", ";
	}
	os << "]\n";
	return os;
}

// [프로그래머스-코딩테스트 연습] 스택 - 주식가격 문제
vector<int> solution(vector<int> prices) {
	stack<int> seconds; // 유지 시간이 저장될 스택
	const int size = prices.size(); // prices의 사이즈 저장
	vector<int> answer(size);    // answer의 사이즈 지정

	// 현재 인덱스에 해당하는 값과 앞으로 변동될 값들 비교
	for (int sec = 0; sec < size; sec++)
	{
		// 가격이 떨어지지 않은 기간 만큼 비교 대상을 변경 및 비교
		// 현재 확인하려는 가격 index == 1, 현재 상태 2초 유지 ==> 비교 대상 index == 3 
		while (!seconds.empty() && prices[sec] < prices[seconds.top()])
		{
			auto top = seconds.top();
			seconds.pop();
			answer[top] = sec - top;
		}
		// 가격이 떨어지지 않은 기간 넣기
		seconds.push(sec);
	}

	while (!seconds.empty())
	{
		auto top = seconds.top();
		seconds.pop();
		answer[top] = size - top - 1;

	}

	return answer;
}

int main()
{
	//// [프로그래머스 문제] Stack - 주식가격
	// 링크 : https://programmers.co.kr/learn/courses/30/lessons/42584?language=cpp
	//vector<int> prices;
	//prices.push_back(1);
	//prices.push_back(2);
	//prices.push_back(3);
	//prices.push_back(2);
	//prices.push_back(3);
	//vector<int> answer = solution(prices);

	Simulator* simulator = Simulator::GetInstance();
	simulator->SimulatorLoop();
}