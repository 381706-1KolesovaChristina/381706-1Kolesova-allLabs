#pragma once
#include "ListLib.h"

template <class T>
class TStackList 
{
protected:
	TList<T> mas;

public:
	TStackList<T>();
	TStackList<T>(TStackList<T> &A);
	void Put(T A);
	T Get();
	bool IsEmpty();
};

template <class T>
TStackList<T>::TStackList() 
{}

template <class T>
TStackList<T>::TStackList(TStackList<T> &A): mas(A.mas)
{}

template <class T>
void TStackList<T>::Put(T A) 
{
	mas.PutBegin(A);
}

template <class T>
T TStackList<T>::Get() 
{
	if (IsEmpty())
		throw -1;
	T temp;
	temp = mas.GetBegin();
	return temp;
}

template <class T>
bool TStackList<T>::IsEmpty() 
{
	return mas.IsEmpty();
}