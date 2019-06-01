#include "THElemLib.h"
#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

template <class T>
class THashTab
{
public:
  THElem<T>** mas;
  int size, count;
  
	THashTab (int _size = 0);
  THashTab (THashTab& A);
	unsigned long int Hash(string _key);
  void Put (string _key, T _data);
  void Put (THElem<T> A);
  void Del (string _key);
	void Resize();
  THElem<T>* Search (string _key);
  bool IsEmpty();

template <class T1>
friend ostream & operator<<( ostream &out, THashTab<T1> &t)
{
	for (int i = 0; i < t.size; i++)
		if (t.mas[i] != NULL)
		{
			out<<*t.mas[i];
		}
	return out;
}
};

template <class T>
THashTab<T>::THashTab(int _size)
{
  if (_size < 0)
    throw -1;
  else
  {
    size = _size;
    mas = new THElem<T>*[size];
    count = 0;
    for (int i = 0; i < size; i++)
      mas[i] = NULL;
	}
}

template <class T>
THashTab<T>::THashTab(THashTab& A)
{
  size = A.size;
  count = A.count;
  mas = new THElem<T>* [size];
  for (int i = 0; i < size; i++)
    mas[i] = A.mas[i];
}

template <class T>
unsigned long int THashTab<T>::Hash(string _key)
{
	unsigned long int h = 0, c = 1;
	for (int i = 0; i < strlen(_key.c_str()); i++)
	{
		h = h + ((int)_key[i] - 65) * c;
		c = c * 10;
	}
	return h;
}

template <class T>
void THashTab<T>::Put(string _key, T _data)
{
	int hash = Hash(_key);
	THElem<T> tmp(_key, _data);
  try
  {
    if (Search(_key) != NULL)
      throw -1;
    else
    {
			while (hash > size)
				Resize();
			if (mas[hash] == NULL)
			{
				mas[hash] = new THElem<T>(tmp);
				count++;
			}
			else
			{
				THElem<T> *p = mas[hash];
				while (p->GetNext() != NULL)
					p = p->GetNext();
				p->SetNext(&tmp);
			}
		}
  }
  catch (...)
  {
    cout<<"Одинаковые ключи\n";
  }
}

template <class T>
void THashTab<T>::Put(THElem<T> A)
{
	int hash = Hash(A.GetKey());
  try
  {
    if (Search(A.GetKey()) != NULL)
      throw -1;
    else
    {
			while (hash > size)
				Resize();
			if (mas[hash] == NULL)
			{
				mas[hash] = new THElem<T> (A);
				count++;
			}
			else
			{
				THElem<T> *tmp = mas[hash];
				while (tmp->GetNext() != NULL)
					tmp = tmp->GetNext();
				tmp->SetNext(&A);
			}
		}
  }
  catch (...)
  {
    cout<<"Одинаковые ключи\n";
  }
}

template <class T>
void THashTab<T>::Del(string _key)
{
  if (IsEmpty())
    throw -1;
  
	try
	{
		if (Search(_key) == NULL)
			throw -1;
		int hash = Hash(_key);
		THElem<T> *tmp = mas[hash];
		while (tmp != NULL)
		{
			if (tmp->GetKey() == _key)
			{
				mas[hash] = tmp->GetNext();
				count--;
			}
			else if ((tmp->GetNext() != NULL)&&(tmp->GetNext()->GetKey() == _key))
			{
				tmp->SetNext(tmp->GetNext()->GetNext());
			}
			else
				tmp = tmp->GetNext();
		}
	}
	catch(...)
	{
		cout<<" Одинаковые ключи\n";
	}
}

template <class T>
THElem<T>* THashTab<T>::Search(string _key)
{
	THElem<T> *p = mas[Hash(_key)];
	if (p == NULL)
		return NULL;
	else
	{
		while (p)
		{
			if (p->GetKey() == _key)
				return p;
			p = p->GetNext();
		}
	}
	return NULL;
}

template <class T>
void THashTab<T>::Resize()
{
	THElem<T>** tmp;
	tmp = new THElem<T>* [size];
	for(int i = 0; i < size; i++)
	{
		tmp[i] = mas[i];
	}
	delete [] mas;
	int oldsize = size;
	size = size * 10;
	mas = new THElem<T>* [size];
	for(int i = 0; i < oldsize; i++)
	{
		mas[i] = tmp[i];
	}
	for(int i = oldsize; i < size; i++)
	{
		mas[i] = NULL;
	}

}

template <class T>
bool THashTab<T>::IsEmpty()
{
  return (count == 0);
}