
#include "PlexLib.h"
#include <iostream>
#include <locale>

using namespace std;

int main()
{
  setlocale (LC_ALL, "Russian");

	int a = 0, b = 0;
	TPoint A, B(7,4), C(0,15), D(3,17), E;
	cout<<"Точки:\n";
	cout<<"Введите точку:\n";
	cin>>a>>b;
	cout<<"Точка А :\n";
	A.SetX(a);
	A.SetY(b);
	A.show();
	cout<<"Точки В и С :\n";
	B.show();
	C.show();
	cout<<"\n\n\n";
	
	cout<<"Отрезки:\n";
	TSection AB(A, B);
	cout<<"Отрезок АВ :\n";
	AB.show();
	cout<<"\n\n\n";

	cout<<"Плексы:\n";
	TPlex P, P1(&A, &B);
	TPlex P2(P1);
	cout<<"Плекс из точки А и В создан\n";
	cout<<"В плекс добавлена точка (0, 15)\n";
	P2.Add(&A, &C);
	cout<<"В плекс добавлена точка (3, 17)\n";
	P2.Add(&C, &D);
	
	cout<<"Введите точку:\n";
	cin>>a>>b;
	cout<<"В плекс добавлена точка\n";
	E.SetX(a);
	E.SetY(b);
	P2.Add(&B,&E);
	cout<<"Плекс : \n";
	P2.show();
	cout<<"\n\n\n";
  return 0;
}
