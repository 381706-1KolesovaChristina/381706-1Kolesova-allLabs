#pragma once

#include <iostream>
#include <stdlib.h>
#include "..//QueueLib/Queue.h"

using namespace std;

class TString
{
protected:
	int size;
	char *mas;

public:
	TString();
	TString(TString &A);
	TString(char *mas);
	~TString();
	int GetSize();
	TString operator + (TString &A);
	TString & operator = (TString &A);
	char & operator [] (int i);

	friend ostream & operator << (ostream &ostr, TString &A);
	friend istream& operator >> (istream &istr, TString &A);
};

int GetPriority(const char op);
bool IsOperation(char c);
TQueue<char> ConvertToPolish(TString str);
double Res(TQueue<char> Q);