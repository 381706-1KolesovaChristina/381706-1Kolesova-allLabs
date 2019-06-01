#pragma once
#include <iostream>

using namespace std;


class TSection
{
protected:
	TPoint A, B;

 public:

  void SetA(TPoint _A);
  void SetB(TPoint _B);
  TPoint GetA();
  TPoint GetB();

  TSection (TPoint _A, TPoint _B);
  TSection (TSection &S);
	virtual void show();

};

void TSection::SetA(TPoint _A)
{
  A = _A;
}

void TSection::SetB(TPoint _B)
{
 B = _B;
}

TPoint TSection::GetA()
{
  return A;
}

TPoint TSection::GetB()
{
  return B;
}

TSection::TSection (TPoint _A, TPoint _B)
{
  A = _A;
  B = _B;
}

TSection::TSection(TSection &S)
{
  A = S.A;
  B = S.B;
}

void TSection::show()
{
	cout<<A.GetX()<<"\t"<<A.GetY()<<"\n"<<B.GetX()<<"\t"<<B.GetY()<<"\n";
}
