#include "STElemLib.h"
#include <iostream>
#include <locale>

using namespace std;

template <class T>
class TSortTab
{
protected:
	TSElem<T> not_found;
	TSElem<T>* mas;
	int size, count;

public:
	void SetSize (int _size);
	void SetCount (int _count);
	TSElem<T>* GetMas();
	int GetSize();
	int GetCount();

	TSortTab (int _size = 0);
	TSortTab (TSortTab& A);
	void Put (string _key, T _data);
	void Put (TSElem<T> A);
	void Del (string _key);
	int Index (string _key);
	TSElem<T>& Search (string _key);
	T operator[](string _key);
	void Resize();
	bool IsFull ();
	bool IsEmpty();

  friend ostream & operator<<( ostream &out, TSortTab &t)
  {
    for (int i = 0; i < t.GetCount(); i++)
      out<<t.mas[i]<<"\n";
    return out;
  }

};


template <class T>
void TSortTab<T>::SetSize(int _size)
{
	size = _size;
}

template <class T>
void TSortTab<T>::SetCount(int _count)
{
	count = _count;
}

template <class T>
int TSortTab<T>::GetSize()
{
	return size;
}

template <class T>
int TSortTab<T>::GetCount()
{
	return count;
}

template <class T>
TSElem<T>* TSortTab<T>::GetMas()
{
	return mas;
}

template <class T>
TSortTab<T>::TSortTab(int _size)
{
	if (_size < 0)
		throw -1;
	else
	{
		size = _size;
		mas = new TSElem<T>[size];
		count = 0;
		for (int i = count; i < size; i++)
			mas[i] = not_found;
	}
}

template <class T>
TSortTab<T>::TSortTab(TSortTab& A)
{
	size = A.size;
	count = A.count;
	mas = new TSElem<T> [size];
	for (int i = 0; i < count; i++)
		mas[i] = A.mas[i];
	for (int i = count; i < size; i++)
		mas[i] = not_found;
}

template <class T>
int TSortTab<T>::Index (string _key)
{
	if (IsEmpty())
		return 0;
	int left = 0, right = count, cur = (count)/2 ;
	while (right - left != 1)
	{
		if (mas[cur].GetKey() > _key)
		{
			right = cur;
			cur = (left + right)/2;
		}
		else if (mas[cur].GetKey() < _key)
		{
			left = cur;
			cur = (left + right +1)/2;
		}
		else return cur;
	}
 return cur;
}

template <class T>
void TSortTab<T>::Put(string _key, T _data)
{
	TSElem<T> tmp(_key, _data);
	int ind = Index(_key);
	if (IsFull())
		Resize();
	try
	{
		if (Search(_key) != not_found)
			throw -1;
		else
		{
			for (int i = count; i > ind; i--)
				mas[i] = mas[i - 1];
			mas[ind] = tmp;
			count++;
		}
	}
	catch (...)
	{
		cout<<"Îèíàêîâûå êëþ÷è\n";
	}
}

template <class T>
void TSortTab<T>::Put(TSElem<T> A)
{
	int ind = Index(A.GetKey());
	if (IsFull())
		Resize();
	try
	{
		if (Search(A.GetKey()) != not_found)
			throw -1;
		else
		{
			for (int i = count; i > ind; i--)
				mas[i] = mas[i-1];
			mas[ind] = A;
			count++;
		}
	}
	catch (...)
	{
		cout<<"Îäèíàêîâûå êëþ÷è\n";
	}
}

template <class T>
void TSortTab<T>::Del(string _key)
{
	try
	{
		if (Search(_key) == not_found)
			throw -1;
		else
		{
			int ind = Index(_key);
			Resize();
			for (int i = ind; i < count; i++)
				mas[i] = mas[i+1];
			mas[count] = not_found;
			count--;
		}
	}
	catch(...)
	{
		cout<<"Ýë-ò íå íàéäåí \n";
	}
}

template <class T>
TSElem<T>& TSortTab<T>::Search(string _key)
{
	int ind = Index(_key);
	if (IsEmpty())
		return not_found;
	if (mas[ind].GetKey() == _key)
		return mas[ind];
	else return not_found;
}

template <class T>
T TSortTab<T>::operator [] (string _key)
{
	TSElem<T>& tmp = Search(_key);
	if (tmp == not_found)
	{
		if (IsFull())
			Resize();
		else
		{
			TSElem<T> B(_key, NULL);
			int ind = Index (B.GetKey());
			Put(B);
			count++;
			return mas[ind].GetData();
		}
	}
	else return tmp.GetData();
}

template <class T>
void TSortTab<T>::Resize()
{
	size = size + 10;
}

template <class T>
bool TSortTab<T>::IsFull()
{
	return (size == count);
}

template <class T>
bool TSortTab<T>::IsEmpty()
{
	return (count == 0);
}
