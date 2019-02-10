#include <iostream>
#include "Stack.h"
#include "ExceptionLib.h"
using namespace std;

int main()
{
  try
  {
    int n;
    cout << "\n Number of stack elements\n";
    cin >> n;
    TStack<int> St(n);
    int Elem;
    cout << " Elements of the stack\n";
    for (int i = 0; i < n; i++)
    {
      cin >> Elem;
      St.Put(Elem);
    }
    cout <<endl;
    St.PrintStack();

    cout << "\n \n Delete Elem \n";
    St.Get();
    cout <<endl;
    St.PrintStack();

    cout << "\n \n Copy stack \n";
    TStack<int> NewStack(St);
    NewStack.PrintStack();
  }
  catch (MyException exception)
  {
    exception.Print();
  }
  return 0;
}
