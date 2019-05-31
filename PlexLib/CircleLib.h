#pragma once
#include <iostream>
#include "ExceptionLib.h"

using namespace std;

class TCircle

{

protected:
	TPoint* center;
	double radius;

public:

	void SetA(const int _A);
	void SetB(const int _B);
	void SetRadius(const double _radius);
	double GetA() { return center->GetA(); }
	double GetB() { return center->GetB(); }
	double GetRadius() { return radius; }

	virtual void show();
};

void TCircle::SetA(const int _A)
{
	center->SetA(_A);
}

void TCircle::SetB(const int _B)
{
	center->SetY(_B);
}

void TCircle::SetRadius(const double _radius)
{
	if (R < 0)
		throw MyException("Error");
	radius = R;
}

void TCircle::show()
{
	std::cout << "Center ";
	center->Show();
	std::cout << " ";
	std::cout << "Radius " << radius << " " << std::endl;
}