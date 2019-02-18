#include "Polish.h"
#include <cstdlib>

int GetSym(const char symvol)
{
  switch (symvol)
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
    throw MyException(" Uncurrent symbol ");
  }
}

bool IsOper(char a)
{
  return (a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')');
}

TQueue<char> ConvertToPolish(TString s)
{
  int open = 0;
  int close = 0;
  TQueue<char> Q(s.GetLength() * 3);
  TStack<char> S(s.GetLength() * 3);
  for (int i = 0; i < s.GetLength(); i++)
  {
    if (i == 0)
    {
      if (s[0] == '-')
      {
        Q.Put('[');
        Q.Put('0');
        Q.Put(']');
      }
      else if (IsOper(s[0]))
        if (GetSym(s[0]) != 1)
          throw MyException(" Uncurrent math expression ");
    }
    if (isdigit(s[i]))
    {
      Q.Put('[');
      while ((i < s.GetLength()) && isdigit(s[i + 1]))
      {
        Q.Put(s[i]);
        i++;
      }
      Q.Put(s[i]);
      Q.Put(']');
    }
    else if (S.IsEmpty() && IsOper(s[i]))
    {
      S.Put(s[i]);
      if (s[i] == '(')
        open++;
      if (s[i] == ')')
        throw MyException(" Uncurrent math expression ");
    }
    else if (IsOper(s[i]))
    {
      if (s[i] == '(')
      {
        S.Put(s[i]);
        open++;
      }
      else if (s[i] == ')')
      {
        close++;
        while (S.Top() != '(')
          Q.Put(S.Get());
        S.Get();
      }
      else
      {
        int p = GetPrt(s[i]);
        if (p > GetPrt(S.Top()))
          S.Put(s[i]);
        else if (p <= GetPrt(S.Top()))
        {
          while (!S.IsEmpty() && p <= GetPrt(S.Top()))
            Q.Put(S.Get());
          S.Put(s[i]);
        }
      }
    }
    else if (s[i] != '\0')
      throw MyException(" Uncurrent math expression ");
  }
  while (!S.IsEmpty())
    Q.Put(S.Get());
  if (open != close)
    throw MyException(" Uncurrent math expression ");
  return Q;
}

double Rez(TQueue<char> q)
{
  double res = 0;
  TStack<double> S(q.GetSize());
  if (IsOper(q.Top()))
    throw MyException(" Uncurrent queue ");
  int i = 0;
  int dit = 0;
  int t = 0;
  while (!q.IsEmpty())
  {
    i++;
    char A = q.Get();
    if (A == '[')
    {
      dit++;
      A = q.Get();
      double tmp = std::atof(&A);
      while (q.Top() != ']' && !q.IsEmpty())
      {
        A = q.Get();
        tmp = tmp * 10 + std::atof(&A);
      }
      q.Get();
      S.Put(tmp);
    }
    else if (IsOper(A))
    {
      double B = S.Get();
      double C = S.Get();
      double D = 0;
      if (A == '+')
        D = C + B;
      if (A == '-')
        D = C - B;
      if (A == '*')
        D = C * B;
      if (A == '/')
        D = C / B;
      S.Put(D);
    }
    else 
      throw MyException(" Uncurrent symbol in queue ");
    if (i == 2 && dit != 2)
      throw MyException(" Uncurrent queue ");
  }
  res = S.Get();
  if (!S.IsEmpty())
    throw MyException(" Uncurrent queue ");
  return res;
}
