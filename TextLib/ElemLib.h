#pragma once
#include <iostream>

using namespace std;

template <class T>
class TElem{
protected:
	T A;
	TElem <T>* next;
public:
	TElem (T _A, TElem <T>* n = 0);
	TElem (TElem<T> &B);
	T Get();
	TElem* GetNext();
	void Set(T p);
	void SetNext(TElem<T>* n);
};

template <class T>
TElem<T>::TElem(T _A, TElem <T>* n) 
{
	A = _A;
	next = n;
}

template <class T>
TElem<T>::TElem(TElem<T> &B) 
{
	A = B.A;
	next = B.next;
}

template <class T>
T TElem<T>::Get() 
{
	return A;
}

template <class T>
TElem<T>* TElem<T>::GetNext() 
{
	return next;
}

template <class T>
void TElem<T>::Set(T p) 
{
	A = p;
}

template <class T>
void TElem<T>::SetNext(TElem<T>* n) 
{
	next = n;
}