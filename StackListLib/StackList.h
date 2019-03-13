#pragma once
#include "..//ListLib/List.h"
#include "..//ExceptionLib/ExceptionLib.h"

template <class T>
class TStackList : public TList<T>
{
protected:
	int size_st;
public:
	TStackList<T>(int _size = 10);
	TStackList<T>(TStackList<T> &A);
	~TStackList();
	void Print();
	void Put(T A);
	T Get();
	int GetSize();
	int GetMaxSize();
	bool IsEmpty();
	bool IsFull();
};

template <class T>
TStackList<T>::TStackList(int _size) : TList<T>()
{
	if (_size <= 0)
		throw MyException(" Wrong size ");
	size_st = _size;
}

template <class T>
TStackList<T>::TStackList(TStackList<T> &A) : TList<T>(A)
{
	TList<T>::Size = A.Size;
}

template<class T>
TStackList<T>::~TStackList()
{}

template <class T>
void TStackList<T>::Put(T A)
{
	if (this->IsFull())
		throw MyException(" Stack is full ");
	TList<T>::PutBegin(A);
}

template <class T>
T TStackList<T>::Get()
{
	if (this->IsEmpty())
		throw MyException(" Stack is empty ");
	return TList<T>::GetBegin();
}

template <class T>
int TStackList<T>::GetMaxSize()
{
	return size_st;
}

template<class T>
inline int TStackList<T>::GetSize()
{
	return TList<T>::Size;
}

template <class T>
bool TStackList<T>::IsEmpty()
{
	if (TList<T>::Size == 0)
		return true;
	return false;
}
template<class T>
bool TStackList<T>::IsFull()
{
	if (TList<T>::Size == size_st)
		return true;
	return false;
}

template<class T>
void TStackList<T>::Print()
{
	if (this->IsEmpty())
		throw MyException(" Stack is empty ");
	TList<T>::Print();
}
