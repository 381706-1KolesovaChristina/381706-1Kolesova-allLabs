#pragma once
#include "ExceptionLib.h"

template <class T>
class TVector
{
protected:
	T *Mas;     //указатель на вектор 
	int Size;       // размер вектора
public:
	TVector(int s = 0);
	TVector(const TVector &v);
	virtual ~TVector();

	int getSize() const; // получить размер вектора
	virtual T& operator[](int pos);           // доступ с 0

	bool operator==(const TVector &v) const;  // сравнение равно 
	bool operator!=(const TVector &v) const;  // сравнение не равно
	virtual TVector& operator=(const TVector &v); // присваивание
	
	TVector operator+(const T &val);   // прибавить число
	TVector operator-(const T &val);   // вычесть число
	TVector operator*(const T &val);   // умножить на число

	TVector operator+(const TVector &v);     // сложение
	TVector operator-(const TVector &v);     // вычитание
	T operator*(const TVector &v);     // скалярное произведение

	template <class ValType1>
	friend istream& operator>>(istream &in, TVector<ValType1>& v);
	template <class ValType1>
	friend ostream& operator<<(ostream &out, const TVector<ValType1>& v);
};

template <class T>
TVector<T>::TVector(int s)
{
	if (s < 0)
		throw MyException(" wrong size ");
	else
		if (s == 0)
		{
			Size = s;
			Mas = NULL;
		}
		else
		{
			Size = s;
			Mas = new T[Size];
			for (int i = 0; i < Size; i++)
				Mas[i] = 0;
		}
} 
//-------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(const TVector<T> &V)
{
	Size = V.Size;
	if (Size == 0)
		Mas = NULL;
	else
	{
		Mas = new T[Size];
		for (int i = 0; i < Size; i++)
			Mas[i] = V.Mas[i];
	}
} 
//-------------------------------------------------------------------------
template<class T>
TVector<T>::~TVector()
{
	if (Size > 0)
	{
		Size = 0;
		delete[] Mas;
		Mas = NULL;
	}
} 
//-------------------------------------------------------------------------
template <class T>
int TVector<T>::getSize() const
{
	return Size;
}
//-------------------------------------------------------------------------
template <class T>
T& TVector<T>::operator[](int pos)
{
	if (pos >= 0 && pos < Size)
		return Mas[pos];
	else
		throw MyException("wrong index");
} 
//-------------------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::operator=(const TVector &v)
{
	if (this != &v)
	{
		delete[] Mas;
		Size = v.Size;
		Mas = new T[Size];
		for (int i = 0; i < Size; i++)
			Mas[i] = v.Mas[i];
	}
	return *this;
} 
//-------------------------------------------------------------------------
template <class T>
bool TVector<T>::operator==(const TVector &v) const
{
	if (Size != v.Size)
		return false;
	else {
		T mp = 0.0001;
		for (int i = 0; i < Size; i++)
			if (((Mas[i] - v.Mas[i]) > mp) || ((v.Mas[i] - Mas[i]) > mp)) 
				return false;
	}
	return true;
} 
//-------------------------------------------------------------------------
template <class T>
bool TVector<T>::operator!=(const TVector &v) const
{
	return !(*this == v);
} 
//-------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator+(const T &val)
{
	TVector<T> res(*this);
	for (int i = 0; i < Size; i++)
		res.Mas[i] += val;
	return res;
} //-------------------------------------------------------------------------

template <class T>
TVector<T> TVector<T>::operator-(const T &v)
{
	if (Size != v.Size)
		throw MyException(" wrong size ");
	TVector<T> temp(Size);
	for (int i = 0; i < Size; i++)
		temp[i] = (*this)[i] + v.Mas[i];
	return temp;
} 
//-------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator*(const T &v)
{
	TVector<T> temp(*this);
	for (int i = 0; i < Size; i++)
		temp.Mas[i] = temp.Mas[i] * v;
	return temp;
} 
//-------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator+(const TVector<T> &v)
{
	if (Size != v.Size)
		throw MyException(" wrong size ");
	TVector<T> temp(*this);
	for (int i = 0; i < Size; i++)
		temp[i] = (*this)[i] + v.Mas[i];
	return temp;
} 
//-------------------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator-(const TVector<T> &v)
{
	if (Size != v.Size)
		throw MyException(" wrong size ");
	TVector<T> temp(*this);
	for (int i = 0; i < Size; i++)
		temp[i] = (*this)[i] - v.Mas[i];
	return temp;
} 
//-------------------------------------------------------------------------
template <class T>
T TVector<T>::operator*(const TVector<T> &v)
{
	if (Size != v.Size)
		throw MyException(" wrong size ");
	int temp = 0;
	for (int i = 0; i < Size; i++)
		temp += Mas[i] * v.Mas[i];
	return temp;
} 
//-------------------------------------------------------------------------
template <class T>
istream& operator>>(istream &in, TVector<T> &v)
{
	for (int i = 0; i < v.Size; i++)
		in >> v.Mas[i];
	return in;
}//-------------------------------------------------------------------------

template <class T>
ostream& operator<<(ostream &out, const TVector<T> &v)
{
	for (int i = 0; i < v.Size; i++)
		out << v.Mas[i] << ' ';
	return out;
}
