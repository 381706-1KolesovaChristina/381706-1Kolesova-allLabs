#pragma once
#include <iostream>
#include "..//ExceptionLib/ExceptionLib.h"
using namespace std;

template <class T>
class TStack
{
  protected:
  int Size;
  int Top;
  T* Mas;
  public:
  TStack(int n = 0);
  TStack(TStack<T> &st);
  virtual ~TStack();
  void Put(T a);
  T Get();
	int GetSize() { return Size; }
  bool IsFull();
  bool IsEmpty();
  void PrintStack();
	T StGetTop(); 
};

template <class T>
TStack <T> ::TStack(int n)
{
  if (n < 0)
  throw MyException(" wrong size ");
  if (n == 0)
  {
    Size = 0;
    Top = 0;
    Mas = NULL;
  }
  else
  {
    Size = n;
    Top = 0;
    Mas = new T[Size];
    for (int i = 0; i < Size; i++)
      Mas[i] = 0;
  }
}

template <class T>
TStack <T> ::TStack(TStack <T> &st)
{
  Size = st.Size;
  Top = st.Top;
  if (Size == 0)
    Mas = NULL;
  else
  {
    Mas = new T[Size];
    for (int i = 0; i < Size; i++)
    Mas[i] = st.Mas[i];
  }
}

template<class T>
TStack <T> :: ~TStack()
{
  if (Mas != NULL)
    delete[] Mas;
  Top = 0;
  Size = 0;
}

template <class T>
void TStack<T> ::Put(T a)
{
  if (IsFull())
    throw MyException("Stack is full");
  else
  {
    Mas[Top] = a;
    Top++;
  }
}

template <class T>
T TStack<T> ::Get()
{
  if (IsEmpty())
    throw MyException("Stack is empty");
  else
  {
     Top--;
    return Mas[Top];
  }
}

template <class T>
T TStack<T> ::StGetTop()
{
	if (IsEmpty())
		throw "Stack is empty.";
	return Mas[Top - 1];
}

template <class T>
bool TStack<T> ::IsFull()
{
  if (Top >= Size)
    return true;
  else
    return false;
}

template <class T>
bool TStack<T> ::IsEmpty()
{
  if (Top == 0)
    return true;
  else
    return false;
}

template <class T>
void TStack<T>::PrintStack()
{
  for (int i = Top - 1; i >= 0; i--)
    cout << "\t" << Mas[i] << endl;
}
