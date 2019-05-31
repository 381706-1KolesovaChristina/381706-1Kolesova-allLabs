#include "TabLib.h"
#include <string>
#include <iostream>
#include <locale>

using namespace std;

int main()
{
  setlocale (LC_ALL, "Russian");
  TElem<int> e1("A", 35), e2("B", 17), e3("C", 76), e4(e1), e5;
  TTab<int> t1(10);
  
  t1.Put(e2);
  t1.Put(e3);
  t1.Put(e1);

  cout<<t1<<"\n";
  cout<<"Вводим строку с ключом А\n";
  t1.Put(e4);
  cout<<"\nВведите строку:\n";
  cin>>e5;
  t1.Put(e5);
  cout<<"Таблица\n"<<t1<<"\n";
  cout<<"Поиск по ключу С:\n"<<t1.Search("C")<<"\n";
  cout<<"Строки В\n"<<t1["B"]<<"\n";
  return 0;
}
