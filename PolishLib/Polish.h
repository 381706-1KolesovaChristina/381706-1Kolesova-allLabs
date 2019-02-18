#pragma once
#include "Queue.h"
#include "Stroka.h"

int GetSym(const char symvol);
bool IsOper(char a);
TQueue<char> ConvertToPolish(TString s);
double Rez(TQueue<char> q);
