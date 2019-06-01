#include <string>

using namespace std;

template <class T>
class THElem
{
protected:
  string key;
  T data;
	THElem<T> *next;

public:
  void SetKey(string _key);
  void SetData(T _data);
	void SetNext(THElem<T>* _data);
  string GetKey();
  T GetData();
	THElem<T>* GetNext();
  THElem (string _key = "", T _data = 0);
  THElem (THElem &A);
  THElem& operator = (THElem &A);
  bool operator == (THElem &A);
  bool operator != (THElem &A);

  template <class T1>
  friend ostream & operator<<( ostream &out, THElem<T1> t)
  {
		THElem<T1> *p = &t;
		while(p != NULL)
		{
			out<<p->GetKey()<<"\t";
			out<<p->GetData()<<"\t\n";
			p = p->GetNext();
		}
    return out;
  }
};

template <class T>
void THElem<T>::SetKey(string _key)
{
  key = _key;
}

template <class T>
void THElem<T>::SetData(T _data)
{
  data = _data;
}

template <class T>
void THElem<T>::SetNext(THElem<T>* _next)
{
	 next = new THElem<T>(*_next);
}

template <class T>
string THElem<T>::GetKey()
{
  return key;
}

template <class T>
T THElem<T>::GetData()
{
  return data;
}

template <class T>
THElem<T>* THElem<T>::GetNext()
{
	return next;
}

template <class T>
THElem<T>::THElem (string _key, T _data)
{
  key = _key;
  data = _data;
	next = NULL;
}

template <class T>
THElem<T>::THElem(THElem &A)
{
  key = A.key;
  data = A.data;
	next = A.next;
}

template <class T>
THElem<T>& THElem<T>::operator = (THElem &A)
{
  key = A.key;
  data = A.data;
	next = A.next;
  return *this;
}

template <class T>
bool THElem<T>::operator == (THElem &A)
{
  return ((key == A.key) && (data == A.data));
}

template <class T>
bool THElem<T>::operator != (THElem &A)
{
  return ((key != A.key) || (data != A.data));
}