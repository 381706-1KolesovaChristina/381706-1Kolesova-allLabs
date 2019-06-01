#include "SortTabLib.h"
#include <string>
#include <iostream>
#include <locale>

using namespace std;

int main()
{
	setlocale (LC_ALL, "Russian");
	TSElem<int> e1("A", 35), e2("B", 17), e3("C", 76), e4(e1), e5;
	TSortTab<int> t1(10);
	t1.Put(e2);
	t1.Put(e1);
	t1.Put(e3);
	cout<<t1<<"\n";
	cout<<"Выводим строку с ключом А: \n";
	t1.Put(e4);
	cout<<"Удаляем строку с ключом K: \n";
	t1.Del("K");
	t1.Del("A");
	cout<<"\nВведите строку:\n";
	cin>>e5;
	t1.Put(e5);
	cout<<"Таблица\n"<<t1<<"\n";
	cout<<"Поиск по ключу С:\n"<<t1.Search("C")<<"\n";
	cout<<"Данные строчки В\n"<<t1["B"]<<"\n";
	return 0;
}
