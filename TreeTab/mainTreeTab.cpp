#include "TreeTabLib.h"
#include <string>
#include <iostream>
#include <locale>

using namespace std;

int main()
{
	setlocale (LC_ALL, "Russian");
	int h;
	TTElem<int> A(), B("B", 7), C("C", 10), D("D", 2), E("E", 45);
	TTreeTab<int> T;
	//T.Put(D);
	T.Put("F", 12);
	//T.Put(C);
	//T.Put(E);
	//T.Put(B);

	T.Del("C");
	T.Search("F");
	h = T.Height(T.root);
	cout<<"Высота дерева:\n"<<h;
	return 0;
}
