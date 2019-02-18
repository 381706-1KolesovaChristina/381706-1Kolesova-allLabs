#pragma once
#include <iostream>
#include "ExceptionLib.h"

using namespace std;

class TMonomial
{
protected:
	int* power;      
	int size;        
	double coeff;    
	TMonomial *next; 
public:
	TMonomial(int _Size, int *M, double _Coeff);  
	TMonomial(TMonomial &A);                  

	TMonomial()             
	{
		next = NULL;
		power = NULL;
		coeff = 0;
		size = 0;
	}

	virtual ~TMonomial()  
	{
		if (power != 0)
			delete[]power;
		size = 0;
		coeff = 0;
		next = 0;
	}

	void SetPower(int *M);                        
	void SetSize(int _Size);                      
	void SetCoeff(double _Coeff);                 
	void SetNext(TMonomial* _Next);               

	int *GetPower();                              
	int GetSize();                                
	double GetCoeff();                            
	TMonomial* GetNext();      

	TMonomial &operator = (TMonomial &A);         
	TMonomial operator + (TMonomial &A);          
	TMonomial operator += (TMonomial &A);         
	TMonomial operator - (TMonomial &A);          
	TMonomial operator -= (TMonomial &A);          
	TMonomial operator * (TMonomial &A);          
	TMonomial operator *= (TMonomial &A);         

	bool operator == (TMonomial &A);              
	bool operator < (TMonomial &A);               
	bool operator > (TMonomial &A);              

	friend istream& operator>>(istream &in, TMonomial &m);
	friend ostream& operator<<(ostream &out, TMonomial &m);
};

TMonomial::TMonomial(int _size, int* _power, double _coeff)
{
	if (_size < 0)
		throw MyException(" Negative size ");
	else if (_size == 0)
	{
		power = NULL; next = NULL;
		coeff = _coeff; size = _size; 
	}
	else
	{
		size = _size; coeff = _coeff; next = NULL;
		power = new int[_size];
		for (int i = 0; i < _size; i++)
		{
			if (_power[i] >= 0)
				power[i] = _power[i];
			else
				throw MyException(" Negative power ");
		}
	}
}

TMonomial::TMonomial(TMonomial &A)
{
	size = A.size;
	coeff = A.coeff;
	next = A.next;
	power = new int[size];
	for (int i = 0; i < size; i++)
	{
		power[i] = A.power[i];
	}
}

void TMonomial::SetPower(int *M)
{
	for (int i = 0; i < size; i++)
	{
		if (M[i] >= 0)
			power[i] = M[i];
		else throw MyException(" Negative power ");
	}
}

void TMonomial::SetSize(int _Size)
{
	if (_Size <= 0)
		throw MyException(" Negative size ");
	
	else if (_Size == 0)
	{
		if (power != 0)
			delete[] power;
		size = 0; power = 0;
	}

	else
	{
		int *temporary = new int[size];
		for (int i = 0; i < size; i++)
			temporary[i] = power[i];
		delete[]power;
		int i = 0;
		power = new int[_Size];

		if (size < _Size)
		{
			for (; i < size; i++)
				power[i] = temporary[i];
			for (; i < _Size; i++)
				power[i] = 0;
		}

		if (_Size < size)
			for (; i < _Size; i++)
				power[i] = temporary[i];

		size = _Size;
	}
}

void TMonomial::SetCoeff(double _Coeff)
{
	coeff = _Coeff;
}

void TMonomial::SetNext(TMonomial* _Next)
{
	next = _Next;
}

int *TMonomial::GetPower()
{
	return power;
}

int TMonomial::GetSize()
{
	return size;
}

double TMonomial::GetCoeff()
{
	return coeff;
}

TMonomial* TMonomial::GetNext()
{
	return next;
}

TMonomial &TMonomial::operator = (TMonomial &A)
{
	if (size != A.size)
		throw MyException(" Wrong size");
	coeff = A.coeff;
	size = A.size;
	next = A.next;
	delete[] power;
	power = new int[size];
	for (int i = 0; i < size; i++)
		power[i] = A.power[i];
	return *this;
}

TMonomial TMonomial::operator + (TMonomial &A)
{
	TMonomial temporary(A);
	if (size != A.size)
		throw MyException(" Wrong size ");
	if (!(*this == A))
		throw MyException(" Wrong power ");
	temporary.coeff = coeff + A.coeff;
	return temporary;
}

TMonomial TMonomial::operator+=(TMonomial & A)
{
	if (size != A.size)
		throw MyException(" Wrong size ");
	if (!(*this == A))
		throw MyException(" Wrong size ");
	coeff += A.coeff;
	return *this;
}

TMonomial TMonomial::operator - (TMonomial &A)
{
	TMonomial temporary(A);
	if (size != A.size)
		throw MyException(" Wrong size ");
	if (!(*this == A))
		throw MyException(" Wrong power ");
	temporary.coeff = coeff - A.coeff;
	return temporary;
}

TMonomial TMonomial::operator-=(TMonomial & A)
{
	if (size != A.size)
		throw MyException(" Wrong size");
	if (!(*this == A))
		throw MyException(" Wri=ong size ");
	coeff -= A.coeff;
	return *this;
}

TMonomial TMonomial::operator * (TMonomial &A)
{
	TMonomial temporary(A);
	if (size != A.size)
		throw MyException(" Wrong size");
	else
	{
		temporary.coeff = coeff * A.coeff;
		for (int i = 0; i < size; i++)
			temporary.power[i] = power[i] + A.power[i];
		return temporary;
	}
}

TMonomial TMonomial::operator *= (TMonomial &A)
{
	if (size != A.size)
		throw MyException(" Wrong size");
	coeff = coeff * A.coeff;
	for (int i = 0; i < size; i++)
		power[i] += A.power[i];
	return *this;
}

bool TMonomial::operator == (TMonomial &A)
{
	if (size == A.size)
	{
		for (int i = 0; i < size; i++)
			if (power[i] != A.power[i])
				return false;
		return true;
	}
	else
		return false;
}

bool TMonomial::operator > (TMonomial& A)
{
	if (size != A.size)
		throw MyException(" Wrong size");
	if (*this == A)
		throw MyException(" They are == ");
	for (int i = 0; i < size; i++)
	{
		if (power[i] == A.power[i])
			continue;
		else if (power[i] > A.power[i])
			return true;
		else
			return false;
	}
	return true;
}

bool TMonomial:: operator < (TMonomial &A)
{
	if (size != A.size)
		throw MyException(" Wrong size");
	if (*this == A)
		throw MyException(" They are == ");
	for (int i = 0; i < size; i++)
	{
		if (power[i] == A.power[i])
			continue;
		else if (power[i] < A.power[i])
			return true;
		else
			return false;
	}
	if (coeff > A.coeff)
		return false;
	return true;
}

istream& operator >> (istream &in, TMonomial &M)
{
	cout << "coefficient = ";
	in >> M.coeff;
	cout << "power = ";
	for (int i = 0; i < M.size; i++)
		in >> M.power[i];
	return in;
}

ostream& operator << (ostream &out, TMonomial &M)
{
	out << M.GetCoeff();
	if (M.coeff != 0)
	{
		for (int i=0; i < M.size; i++)
			if (M.power[i] != 0)
			{
				out << "(x" << i << "^" << M.power[i] << ")";
			}
	}
	return out;
}

