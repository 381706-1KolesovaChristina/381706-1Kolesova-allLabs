#pragma once
#include <iostream>
#include "..//ExceptionLib/ExceptionLib.h"
#include "..//QueueLib/Queue.h"

template <class T>
class TArrayList 
{
private:
  T * mas;
  int *nextIndex; 
  int *prevIndex; 
  int size; 
  int begin; 
  int end; 
  int count; 
  TQueue <int> FE; 
public:
  TArrayList(int _size = 10);  
  ~TArrayList(); 
  TArrayList(TArrayList<T> &A); 
	bool IsFull();
	bool IsEmpty();
  void PutBegin(T element); 
  void PutEnd(T element);   
  void PutSmthInside(T element, int n);
  T GetBegin(); 
  T GetEnd();   
  T GetSmthFromTheInside(int n);
};

template <class T>
TArrayList<T>::TArrayList(int _size) : FE(_size)
{
  if (_size <= 0)
    throw MyException("Negative size");
  size = _size;
  count = 0; begin = -1; end = -1;

  mas = new T[size];

  nextIndex = new int[size];
  prevIndex = new int[size];

  for (int i = 0; i < size; i++)
  {
    nextIndex[i] = -2;
    prevIndex[i] = -2;
    FE.Put(i);
  }
}

template <class T>
TArrayList<T>::~TArrayList()
{
  size = 0;
  begin = 0; 
  end = 0; 
  count = 0; 
  delete[] mas;
  delete[]nextIndex;
  delete[]prevIndex;
}

template <class T>
void TArrayList<T>::PutSmthInside(T element, int n)
{
  if (n < 0 || n > size)
    throw MyException("Unacceptable index");
  if (IsFull())
    throw MyException("List is full");

  if (n == 0)
    PutBegin(element);
  if (n == count - 1)
    PutEnd(element);

  int f_index = FE.Get(), a = begin, b = nextIndex[begin];
  mas[f_index] = element;

  for (int i = 0; i < n - 1; i++)
  {
    a = b;
    b = nextIndex[b];
  }

  nextIndex[f_index] = b;
  nextIndex[a] = f_index;
  prevIndex[f_index] = a;
  prevIndex[b] = f_index;

  count++;
}

template <class T>
T TArrayList<T>::GetSmthFromTheInside(int n)
{
  if (n < 0 || n > size)
    throw MyException("Unacceptable index");
  if (IsEmpty())
    throw MyException("List's empty");

  if (n == 0)
    return GetBegin();
  if (n == count)
    return GetEnd();

  else
  {
    int i = begin;

    for (int j = 0; j < n; j++)
      i = nextIndex[i];
    T t = mas[i];

    nextIndex[prevIndex[i]] = nextIndex[i];
    prevIndex[nextIndex[i]] = prevIndex[i];

    FE.Put(i);
    count--;

    return t;
    }
}

template <class T>
TArrayList<T>::TArrayList(TArrayList<T> &A)
{
  begin = A.begin; end = A.end;
  size = A.size; count = A.count;

  mas = new T[size];
	
  nextIndex = new int[size];
  prevIndex = new int[size];
  FE = A.FE;
	
  for (int i = 0; i < size; i++)
  {
    mas[i] = A.mas[i];
    nextIndex[i] = A.nextIndex[i];
    prevIndex[i] = A.prevIndex[i];
  }
}

template <class T>
void TArrayList<T>::PutBegin(T elem)
{
  if (IsFull())
    throw MyException("List is full");
	
  int free = FE.Get();
  mas[free] = elem;
  nextIndex[free] = begin;

  if (begin != -1)
    prevIndex[begin] = free;
  else
    end = free;

  begin = free;
  count++;
}

template <class T>
void TArrayList<T>::PutEnd(T element)
{
  if (IsFull())
    throw MyException("List is full");
  int free = FE.Get();
  mas[free] = element;

  if (end != -1)
    nextIndex[end] = free;
  else
  {
    begin = free;
      prevIndex[free] = -1;
  }
  prevIndex[free] = end;
  end = free;
  count++;
}

template <class T>
T TArrayList<T>::GetBegin()
{
  if (IsEmpty())
    throw MyException("List is empty");

  T element = mas[begin];
  int newstart = nextIndex[begin];

  FE.Put(begin);
  nextIndex[begin] = prevIndex[begin] = -2;

  if (newstart != -1)
    prevIndex[newstart] = -1;
  count--;
  begin = newstart;
  return element;
}

template <class T>
T TArrayList<T>::GetEnd()
{
  if (IsEmpty())
    throw MyException("List is empty");
  T elem = mas[end];
  int newFinish = prevIndex[end];
  prevIndex[end] = nextIndex[end] = -2;
  FE.Put(end);
  end = newFinish;
  if (newFinish != -1)
    nextIndex[newFinish] = -1;
  else
    begin = -1;
  count--;
  return elem;
}

template <class T>
bool TArrayList<T>::IsFull()
{
  if (count == size)
    return true;
  else
    return false;
}

template <class T>
bool TArrayList<T>::IsEmpty()
{
  if (count == 0)
    return true;
  else
    return false;
}
