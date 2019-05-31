#pragma once
#include "ElemLib.h"

using namespace std;

template <class T>
class TList 
{
protected:
	TElem<T>* begin;

public:
	TList();
	TList(TList<T> &A);
	~TList();
	void PutBegin(T A);
	void PutEnd(T A);
	void PutElem(T A, int n);
	T GetBegin();
	T GetEnd();
	T GetElem(int ind);
	bool IsEmpty();
};

template <class T>
TList<T>::TList()
{
	begin = 0;
}

template <class T>
TList<T>::TList(TList<T> &A) 
{
	TElem<T> *a, *b;
	a = A.begin;
	if (A.begin == 0)
		begin = 0;
	else 
	{
		begin = new TElem<T>(*A.begin);
		b = begin;
		while (a->GetNext() != 0) 
		{
			b->SetNext(new TElem<T> (*(a->GetNext())) );
			a = a->GetNext();
			b = b->GetNext();
		}
	}
}

template <class T>
TList<T>::~TList()
{
	if (begin != 0) 
	{
		TElem<T> *a, *b;
		a = begin;
		while (a->GetNext() != 0)
		{
			b = a;
			a = a->GetNext();
			delete b;
		}
	}

}

template <class T>
void TList<T>::PutBegin(T A)
{
	if (begin == 0) 
	{
		TElem<T>* tmp = new TElem<T>(A, 0);
		begin = tmp;
	}
	else 
	{
		TElem<T>* tmp = new TElem<T>(A, begin);
		begin = tmp;
	}
}

template <class T>
void TList<T>::PutEnd(T A)
{
	if (begin != 0) 
	{
		TElem<T>* a = begin;
		while (a->GetNext() != 0) 
		{
			a = a->GetNext();
		}
		a->SetNext(new TElem<T>(A, 0));
	}
	else 
	{
		begin = new TElem<T>(A, 0);
	}
}

template <class T>
void TList<T>::PutElem(T A, int n)
{
	if (n < 0)
		throw -1;

	else if (n == 0)
		this->PutBegin(A);
	
	else
	{
		TElem<T>* a = begin;
		for (int i = 0; i < n-1; i++) 
		{
			if (a == 0) 
				throw -1;
			a = a->GetNext();
		}
		TElem<T>* b = a->GetNext();
		a->SetNext(new TElem<T>(A, b));
	}
}

template <class T>
T TList<T>::GetBegin()
{
	if (IsEmpty()) 
		throw -1;
	TElem<T>* a = begin;
	T tmp = begin->Get();
	begin = begin->GetNext();
	delete a;
	return tmp;
}

template <class T>
T TList<T>::GetEnd()
{
	if (IsEmpty()) 
		throw -1;
	TElem<T>* a;
	T tmp;
	if (begin->GetNext() != 0) 
	{
		a = begin;
		while (a->GetNext()->GetNext() != 0) 
			a = a->GetNext();
		tmp = a->GetNext()->Get();
		a->SetNext(0);
		delete a->GetNext();
	}

	else if (begin->GetNext() == 0) 
	{
		tmp = begin->Get();
		begin = 0;
	}
	else
		throw 1;

	return tmp;
}

template <class T>
T TList<T>::GetElem(int ind) 
{
	if (IsEmpty()) 
		throw -1;
	
	if (ind < 0) 
		throw -1;

	else if (ind == 0)
		return this->GetBegin();

	else 
	{
		TElem<T>* a = begin;
		for (int i = 0; i < ind-1; i++) 
		{
			a = a->GetNext();
			if ((a->GetNext() == 0)||(a==0))
				throw -1;
		}
		TElem<T>* b = a->GetNext(); 
		T temp = b->Get();
		a->SetNext(b->GetNext());
		delete b;
		return temp;
	}
}

template <class T>
bool TList<T>::IsEmpty() 
{
	return (begin == 0);
}