#pragma once
#include <iostream>
#include "ExceptionLib.h"
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
  bool IsFull();
  bool IsEmpty();
  void PrintStack();
};

template <class T>
TStack <T> ::TStack(int n)
{
  if (n < 0)
  throw MyException(" wrong size ");
  if (n == 0)
  {
    size = 0;
    top = 0;
    mas = NULL;
  }
  else
  {
    size = n;
    top = 0;
    mas = new T[size];
    for (int i = 0; i < size; i++)
      mas[i] = 0;
  }
}

template <class T>
TStack <T> ::TStack(TStack <T> &st)
{
  size = st.size;
  top = st.top;
  if (size == 0)
    mas = NULL;
  else
  {
    mas = new T[size];
    for (int i = 0; i < size; i++)
    mas[i] = st.mas[i];
  }
}

template<class T>
TStack <T> :: ~TStack()
{
  if (mas != NULL)
    delete[] mas;
  top = 0;
  size = 0;
}

template <class T>
void TStack<T> ::Put(T a)
{
  if (IsFull())
    throw MyException("Stack is full");
  else
  {
    mas[top] = a;
    top++;
  }
}

template <class T>
T TStack<T> ::Get()
{
  if (IsEmpty())
    throw TException("Stack is empty");
  else
  {
     top--;
    return mas[top];
  }
}

template <class T>
bool TStack<T> ::IsFull()
{
  if (top >= size)
    return true;
  else
    return false;
}

template <class T>
bool TStack<T> ::IsEmpty()
{
  if (top == 0)
    return true;
  else
    return false;
}

template <class T>
void TStack<T>::PrintStack()
{
  for (int i = top - 1; i >= 0; i--)
    cout << "\t" << mas[i] << endl;
}
