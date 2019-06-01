#pragma once
#include <iostream>

class TString
{
public:
	char* str;
	int len;

	TString();
	TString(const TString& _str);
	TString(const char* c);
	~TString();

	TString& operator=(const TString& _str);
	TString operator+(TString& _str);
	char& operator[] (int i);
	bool operator==(TString Other);


	friend std::istream& operator>>(std::istream &is, TString& st)
	{
		char s[256];
		is >> s;

		char x = 1;
		int size = 0;
		while (x != '\0')
		{
			size++;
			x = s[size];
		}
		st.len = size + 1;
		st.str = new char[st.len];
		for (int i = 0; i < st.len - 1; i++)
			st.str[i] = s[i];
		st.str[st.len - 1] = 0;
		return is;
	}

	friend std::ostream& operator<<(std::ostream &os, const TString& st)
	{
		os << st.str;
		return os;
	}
};

TString::TString()
{
	str = 0;
	len = 0;
}

TString::TString(const TString& _str)
{
	len = _str.len;
	if (_str.len == 0)
		str = 0;
	else
	{
		str = new char[len];
		for (int i = 0; i < len; i++)
			str[i] = _str.str[i];
	}
}

TString::TString(const char* c)
{
	if (c == 0)
		throw 1;
	if (c[0] == '\0')
		return;
	int size=0;
	char k=1;
	while (k != '\0')
	{
		size++;
		k = c[size];
	}
	len = size+1;
	str = new char[len];
	for (int i = 0; i < len; i++)
		str[i] = c[i];
}

TString::~TString()
{
	if (len != 0)
		delete str;
	str = 0;
	len = 0;
}

TString& TString::operator=(const TString& _str)
{
	if (this == &_str)
		return *this;
	if (len != _str.len)
	{
		delete[] str;
		len = _str.len;
	}
	if (len != 0)
	{
		str = new char[len];
		for (int i = 0; i < len; i++)
		{
			str[i] = _str.str[i];
		}
	}
	return *this;
}

TString TString::operator+(TString& _str)
{
	TString Res;
	Res.len = len + _str.len - 1;
	Res.str = new char[Res.len];
	for (int i = 0; i < len - 1; i++)
		Res.str[i] = str[i];
	for (int i = 0; i < _str.len; i++)
		Res.str[i + len - 1] = _str[i];
	return Res;
}

char& TString::operator[] (int i)
{
	if ((i < 0) || (i >= len))
		throw 1;
	return str[i];
}

bool TString::operator==(TString Other)
{
	if (this->len != Other.len)
		return false;
	for (int i = 0; i < this->len; i++)
	{
		if (str[i] != Other[i])
			return false;
	}
	return true;
}
	