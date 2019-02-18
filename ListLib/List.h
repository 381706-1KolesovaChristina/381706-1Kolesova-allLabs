#pragma once
#include <iostream>
#include "Elem.h"
#include "ExceptionLib.h"

using namespace std;

template <class T>
class TList
{
protected:
	TElem<T>* Begin;          
	int Size;              
public:
	TList();                    
	TList(TList<T> &A);        
	virtual ~TList();         
	int GetSize();     
	bool IsFull();
	bool IsEmpty();
	void Print();
	void Put(int n, T A);
	T Get(int n);
	void PutBegin(T A);    
	void PutEnd(T A);       
	T GetBegin();               
	T GetEnd();                            
};

template <class T>
TList<T>::TList()
{
	Begin = 0;
	Size = 0;
}

template <class T>
TList<T>::TList(TList<T> &A)
{
	
	TElem<T>* a = A.Begin, *b;
	Size = A.Size;
	if (A.Begin == 0)
		Begin = 0;
	else
	{
		Begin = new TElem<T>(*A.Begin);
		b = Begin;
		while (a->GetNext()!= 0)
		{
			b->SetNext(new TElem<T>(*(a->GetNext())));
			a = a->GetNext();
			b = b->GetNext();
		}
	}
}

template <class T>
TList<T>::~TList()
{
	while (Begin != 0)
	{
		TElem<T>* temp = Begin;
		Begin = Begin->GetNext();
		delete temp;
	}
}

template<class T>
int TList<T>::GetSize()
{
	return Size;
}

template<class T>
void TList<T>::Put(int n, T A)
{
  if (this->IsFull())
    throw MyException(" List is full ");
  if (n < 1 || n > Size - 1)
    throw TException(" Wrong index ");
  else
  {
    int i = 0;
    TElem<T>* a = Begin;
    while (i != n - 1)
    {
      a = a->GetNext();
      i++;
    }
    TElem<T>* temp = new TElem<T>(A, a->GetNext());
    a->SetNext(temp);
    Size++;
  }
}

template<class T>
T TList<T>::Get(int n)
{
  if (this->IsEmpty())
    throw MyException(" List is empty ");
  if (n < 1 || n > Size - 1)
    throw MyException(" Wrong index ");
  else
  {
    int i = 0;
    Size--;
    TElem<T>* t1 = Begin;
    TElem<T>* t2 = Begin->GetNext();
    while (i != n - 1)
    {
      t1 = t2;
      t2 = t2->GetNext();
      i++;
    }
    T temp = t2->GetData();
    t1->SetNext(t2->GetNext());
    delete t2;
    return temp;
  }
}	
template <class T>
void TList<T>::PutBegin(T A)
{
	if (this->IsFull())
		throw MyException(" List is full ");
	if (Begin == 0)
	{
		TElem<T>* temp = new TElem<T>(A, 0);
		Begin = temp;
	}
	else
	{
		TElem<T>* temp = new TElem<T>(A, Begin);
		Begin = temp;
	}
	Size++;
}

template <class T>
void TList<T>::PutEnd(T A)
{
	if (this->IsFull())
		throw MyException(" List is full ");
	if (Begin != 0)
	{
		TElem<T>* a = Begin;
		while (a->GetNext() != 0)
			a = a->GetNext();
		a->SetNext(new TElem <T>(A, 0));
	}
	else
		Begin = new TElem<T>(A, 0);
	Size++;
}

template <class T>
T TList<T>::GetBegin()
{
	if (IsEmpty())
		throw MyException(" List is empty ");
	else
	{
		TElem<T>* a = Begin;
		T temp = Begin->TElem<T>::GetData();
		Begin = Begin->TElem<T>::GetNext();
		delete a;
		Size--;
		return temp;
	}
}

template <class T>
T TList<T>::GetEnd()
{
	if (IsEmpty())
		throw MyException(" List is Empty ");
	else
	{
		Size--;
		TElem<T>* a = Begin;
		TElem<T>* b = Begin->GetNext();
		if (b == 0)
		{
			T temp = a->TElem<T>::GetData();
			delete a;
			Begin = 0;
			return temp;
		}
		else
		{
			while (b->GetNext() != 0)
			{
				a = b;
				b = b->GetNext();
			}
			T temp = b->GetData();
			delete b;
			a->SetNext(0);
			return temp;
		}
	}
}

template<class T>
inline void TList<T>::Print()
{
	if (Begin == 0)
		throw MyException(" List is Empty ");
	else
	{
		TElem<T>* a = Begin;
		while (a->GetNext() != 0)
		{
			cout << a->GetData() << " ";
			a = a->GetNext();
		}
		cout << a->GetData() << " ";
	}
}
template <class T>
bool TList<T>::IsFull()
{
	try
	{
		TElem<T>* A = new TElem<T>();
		if (A == NULL)
			return true;
		else
		{
			delete A;
			return false;
		}
	}
	catch (...)
	{
		return 0;
	}
	return true;
}

template <class T>
bool TList<T>::IsEmpty()
{
	if (Begin == 0)
		return true;
	return false;
}

