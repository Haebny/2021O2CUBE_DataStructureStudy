#include "TemplateSingleton.h"

template<typename T>
inline TemplateSingleton<T>::TemplateSingleton()
{
}

template<typename T>
inline TemplateSingleton<T>::~TemplateSingleton()
{
}

template<typename T>
inline T * TemplateSingleton<T>::GetInstance()
{
	if (instance == nullptr)
		instance = new T;
	return instance;
}

template<typename T>
void TemplateSingleton<T>::DestroyInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

template <typename T>
T * TemplateSingleton<T>::instance = nullptr;