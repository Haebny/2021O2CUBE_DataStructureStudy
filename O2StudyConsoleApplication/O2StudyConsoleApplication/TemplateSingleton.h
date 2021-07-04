#pragma once
template <typename T>
class TemplateSingleton
{
protected:
	TemplateSingleton();
	virtual ~TemplateSingleton();

public:
	// �ν��Ͻ� �޾ƿ���
	static T* GetInstance();

	// �ν��Ͻ� ���ֱ�
	static void DestroyInstance();

private:
	static T* instance;
};
