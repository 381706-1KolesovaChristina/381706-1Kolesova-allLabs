#include <string>

using namespace std;

template <class T>
class TSElem
{
protected:

	string key;
	T data;

public:

	void SetKey(string _key);
	void SetData(T _data);
	string GetKey();
	T GetData();

	TSElem (string _key = "", T _data = 0);
	TSElem (TSElem &A);
	TSElem& operator = (TSElem &A);
	bool operator == (TSElem &A);
	bool operator != (TSElem &A);
	bool operator > (TSElem &A);
	bool operator < (TSElem &A);

	template <class T1>
	friend istream & operator>>( istream &in, TSElem<T1> &t)
  {
    in>>t.key;
		in>>t.data;
    return in;
  }

	template <class T1>
  friend ostream & operator<<( ostream &out, TSElem<T1> &t)
  {    
		out<<t.GetKey()<<"\t";
		out<<t.GetData()<<"\t";
    return out;
  }
};

template <class T>
void TSElem<T>::SetKey(string _key)
{
	key = _key;
}

template <class T>
void TSElem<T>::SetData(T _data)
{
	data = _data;
}

template <class T>
string TSElem<T>::GetKey()
{
	return key;
}

template <class T>
T TSElem<T>::GetData()
{
	return data;
}

template <class T>
TSElem<T>::TSElem (string _key, T _data)
{
	key = _key;
	data = _data;
}

template <class T>
TSElem<T>::TSElem(TSElem &A)
{
	key = A.key;
	data = A.data;
}

template <class T>
TSElem<T>& TSElem<T>::operator = (TSElem &A)
{
	key = A.key;
	data = A.data;
	return *this;
}

template <class T>
bool TSElem<T>::operator == (TSElem &A)
{
	return ((key == A.key) && (data == A.data));
}

template <class T>
bool TSElem<T>::operator != (TSElem &A)
{
	return ((key != A.key) || (data != A.data));
}

template <class T>
bool TSElem<T>::operator > (TSElem &A)
{
	return (key > A.GetKey());
}

template <class T>
bool TSElem<T>::operator < (TSElem &A)
{
	return (key < A.GetKey());
}