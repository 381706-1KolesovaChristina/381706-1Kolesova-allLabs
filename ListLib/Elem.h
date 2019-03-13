#pragma once

template <class T>
class TElem
{
public:
	T Data;
	TElem<T>* Next;

	TElem(T _data = 0, TElem<T>* _next = 0);
	TElem(TElem<T> & A);
	virtual ~TElem();
	T GetData();
	TElem<T>* GetNext();
	void SetData(T _data);
	void SetNext(TElem <T>* _next);
};

template <class T>
TElem<T>::TElem(T _data, TElem<T>* _next)
{
	Data = _data;
	Next = _next;
}

template <class T>
TElem<T>::TElem(TElem<T> &A)
{
	Data = A.Data;
	Next = A.Next;
}

template <class T>
TElem<T>::~TElem() {}

template <class T>
T TElem<T>::GetData()
{
	return Data;
}

template <class T>
TElem<T>* TElem<T>::GetNext()
{
	return Next;
}

template <class T>
void TElem<T>::SetData(T _data)
{
	Data = _data;
}

template <class T>
void TElem<T>::SetNext(TElem<T>* _next)
{
	Next = _next;
}
