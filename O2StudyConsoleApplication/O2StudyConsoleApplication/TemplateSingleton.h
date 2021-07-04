#pragma once
template <typename T>
class TemplateSingleton
{
protected:
	TemplateSingleton();
	virtual ~TemplateSingleton();

public:
	// 인스턴스 받아오기
	static T* GetInstance();

	// 인스턴스 없애기
	static void DestroyInstance();

private:
	static T* instance;
};
