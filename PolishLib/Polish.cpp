#include "Polish.h"
#include <cstdlib>

TString::TString()
{
	mas = 0; 
	size = 0;
}

TString::TString(TString &A)
{
	size = A.size;
	if (size != 0)
	{
		mas = new char[size];
		for (int i = 0; i < size; i++)
			mas[i] = A.mas[i];
	}
	else mas = 0;
}

TString::TString(char *st)
{
	if (st == 0)
		throw TException("Error. String is empty.");
	if (st[0] == '\0')
		return;
	char t = 1;
	int l = 0;
	while (t != '\0')
	{
		l++; 
		t = st[l];
	}

	size = l + 1;
	mas = new char[size];
	for (int i = 0; i < size - 1; i++)
		mas[i] = st[i];
	mas[size - 1] = 0;
}

TString::~TString()
{
	if (mas != 0)
		delete[]mas;
}

int TString::GetSize()
{
	return size;
}

TString &TString::operator = (TString &A)
{
	if (this != &A)
	{
		size = A.size;
		if (size != 0)
		{
			if (mas != 0)
				delete[]mas;
			mas = new char[A.size];
			for (int i = 0; i < A.size; i++)
				mas[i] = A.mas[i];
		}
		else
		{
			if (mas != 0)
				delete[]mas;
			size = 0;
		}
	}
	return *this;
}

TString TString::operator + (TString &A)
{
	TString str;
	str.mas = new char[size + A.size - 1];
	for (int i = 0; i < size - 1; i++)
		str.mas[i] = mas[i];
	for (int i = size - 1; i < size + A.size - 1; i++)
		str.mas[i] = A.mas[i - (size - 1)];
	return str;
}

char &TString::operator[](int i)
{
	if ((i >= 0) && (i< size))
		return mas[i];
	else
		throw TException("Error. Wrong index.");
}

istream& operator >> (istream &istr, TString &A)
{
	char str[256] = {0};
	istr >> str;
	char t = 1;
	int l = 0;
	while (t != '\0')
	{
		l++;
		t = str[l];
	}

	A.size = l + 1;
	A.mas = new char[A.size];
	for (int i = 0; i < A.size - 1; i++)
		A.mas[i] = str[i];
	A.mas[A.size - 1] = 0;
	return istr;
}

ostream &operator << (ostream &ostr, TString &A)
{
	ostr << A.mas;
	return ostr;
}





bool IsOperation(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

int GetPriority(const char op)
{
	switch (op)
	{
	case '(': 
		return 1;
	case ')':
		return 1;
	case '+': 
		return 2;
	case '-': 
		return 2;
	case '*': 
		return 3;
	case '/': 
		return 3;
	default: 
		throw TException("Error. Unacceptable symbol.");
	}
}

double Res(TQueue<char> Q)
{
	double res;
	TStack <double> St(Q.GetSize());
	if (IsOperation(Q.GetTop()))
		throw TException("Error. Uncurrent queue.");

	while (!Q.IsEmpty())
	{
		char A = Q.Get();
		if (!IsOperation(A))
		{
			A = Q.Get();
			double temp = std::atof(&A);
			while (!Q.IsEmpty() && Q.GetTop() != '}')
			{
				A = Q.Get();
				temp = temp * 10 + std::atof(&A);
			}
			Q.Get();
			St.Put(temp);
		}
		else
		{
			double B = St.Get(), F = St.Get(), H;

			if (A == '+') H = F + B;
			if (A == '-') H = F - B;
			if (A == '*') H = F * B;
			if (A == '/') H = F / B;
			St.Put(H);
		}
	}
	res = St.Get();
	if (!St.IsEmpty())
		throw TException("Error. Uncurrent queue.");
	return res;
}
TQueue<char> ConvertToPolish(TString str)
{
	int open = 0;
	int close = 0;
	TQueue<char> Q(str.GetSize() * 4);
	TStack<char> St(str.GetSize() * 2);

	for (int i = 0; i < str.GetSize(); i++)
	{
		if (i == 0)
		{
			if (str[0] == '-')
			{
				Q.Put('{');
				Q.Put('0');
				Q.Put('}');
			}

			else if (IsOperation(str[0]))
			{
				if (GetPriority(str[0]) != 1)
					throw TException("Error. Wrong math expression.");
			}
		}

		if ((i > 0) && (str[i] == '-') && (str[i - 1] == '('))
		{
			Q.Put('{');
			Q.Put('0');
			Q.Put('}');
		}

		if (!IsOperation(str[i]) && isdigit(str[i]))
		{
			Q.Put('{');
			while ((isdigit(str[i + 1])) && (i < str.GetSize()))
			{
				Q.Put(str[i]);
				i++;
			}
			Q.Put(str[i]);
			Q.Put('}');
		}

		else if (St.IsEmpty() && IsOperation(str[i]))
		{
			St.Put(str[i]);
			if (str[i] == '(')
				open++;

			if (str[i] == ')')
				throw TException("Error. Wrong math expression.");
		}

		else if (IsOperation(str[i]))
		{
			if (str[i] == '(')
			{
				St.Put(str[i]);
				open++;
			}
			else if (str[i] == ')')
			{
				while (St.StGetTop() != '(')
					Q.Put(St.Get());
				St.Get();
				close++;
			}
			else
			{
				int p = GetPriority(str[i]);
				if (p > GetPriority(St.StGetTop()))
					St.Put(str[i]);
				else if (p <= GetPriority(St.StGetTop()) && p != 0)
				{
					while (p <= GetPriority(St.StGetTop()) && !St.IsEmpty())
						Q.Put(St.Get());
					St.Put(str[i]);
				}
			}
		}
		else if (str[i] != '\0')
			throw TException("Error. Wrong math expression.");
	}
	while (!St.IsEmpty())
		Q.Put(St.Get());
	if (open != close)
		throw TException("Error. Wrong math expression.");
	return Q;
}
