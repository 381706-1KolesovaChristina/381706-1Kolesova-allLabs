#pragma once
#include "..//StackLib/Stack.h"

template <class T>
class TQueue : public TStack <T> 
{
  protected:
  int start;
  int count;
  public:
  TQueue(int n = 0);
  TQueue(TQueue <T> &q);
  //virtual ~TQueue();
  void Put(T a);
  T Get();
	T GetTop();
  bool IsFull();
  bool IsEmpty();
  void PrintQueue();
};

template <class T>
TQueue<T>::TQueue(int n) : TStack<T>(n) 
{
  start = 0;
  count = 0;
}

template <class T>

TQueue<T>::TQueue(TQueue<T> &q) : TStack<T>(q)
{
  start = q.start;
  count = q.count;
}

//template <class T>
//TQueue<T>::~TQueue() {}

template <class T>
void TQueue<T>::Put(T a) 
{
  if (IsFull())
    throw MyException(" Queue is full ");
  else 
  {
		TStack<T>::Put(a);
		TStack<T>::Top = TStack<T>::Top % TStack<T>::Size;
		count++;
  }
}

template <class T>
T TQueue<T>::Get()
{
  if (IsEmpty())
    throw MyException(" Queue is empty ");
  else 
  {
    T temp = TStack<T>::Mas[start];
    start = (start + 1) % TStack<T>::Size;
    count--;
    return temp;
  }
}

template <class T>
T TQueue<T>::GetTop()
{
	return TStack<T>::Mas[start];
}

template <class T>
bool TQueue<T>::IsFull() 
{
  if (count == TStack<T>::Size)
    return true;
  else
    return false;
}

template <class T>
bool TQueue<T>::IsEmpty()
{
  if (count == 0)
    return true;
  else
    return false;
}

template <class T>
void TQueue<T>::PrintQueue()
{
  int i = TStack<T>::Top;
  for (int j = 1; j <= count; j++)
  {
    i = (i + 1) % TStack<T>::Size;
    cout << "\t" << TStack<T>::Mas[i];
  }
}
