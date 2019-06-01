#pragma once
#include <iostream>

using namespace std;


class TPoint
{
protected:
	double x, y;

 public:

  void SetX(double _x);
  void SetY(double _y);
  double GetX();
  double GetY();

  TPoint (double _x = 0, double _y = 0);
  TPoint (TPoint &A);
	virtual void show();

	bool operator == (TPoint &A);
	TPoint& operator = (TPoint &A);
};

void TPoint::SetX(double _x)
{
  x = _x;
}

void TPoint::SetY(double _y)
{
 y = _y;
}

double TPoint::GetX()
{
  return x;
}

double TPoint::GetY()
{
  return y;
}

TPoint::TPoint (double _x, double _y)
{
  x = _x;
  y = _y;
}

TPoint::TPoint(TPoint &A)
{
  x = A.x;
  y = A.y;
}

void TPoint::show()
{
	cout<<x<<"\t"<<y<<"\n";
}

bool TPoint::operator == (TPoint &A)
{
	return ((x == A.GetX())&&(y == A.GetY()));
}

TPoint& TPoint::operator = (TPoint &A)
{
	x = A.x;
	y = A.y;
	return *this;
}