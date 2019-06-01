#include <string>

using namespace std;

template <class T>
class TTElem
{
public:
	string key;
	T data;

	TTElem<T> *left, *right, *parent;
	TTElem (string _key = "", T _data = 0);
	TTElem (TTElem<T> &A);
	
	TTElem<T>& operator = (TTElem<T> &A);
	bool operator == (TTElem<T> &A);
	bool operator != (TTElem<T> &A);

};

template <class T>
TTElem<T>::TTElem (string _key, T _data)
{
	key = _key;
	data = _data;
}

template <class T>
TTElem<T>::TTElem(TTElem &A)
{
	key = A.key;
	data = A.data;
}

template <class T>
TTElem<T>& TTElem<T>::operator = (TTElem &A)
{
	key = A.key;
	data = A.data;
	return *this;
}

template <class T>
bool TTElem<T>::operator == (TTElem &A)
{
	return ((key == A.key) && (data == A.data));
}

template <class T>
bool TTElem<T>::operator != (TTElem &A)
{
	return ((key != A.key) || (data != A.data));
}

