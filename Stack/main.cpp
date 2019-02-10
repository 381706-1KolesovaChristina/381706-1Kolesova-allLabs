#include <iostream>
#include "Stack.h"
#include "ExceptionLib.h"
#include <locale.h>
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
    stack.Get();
    cout <<endl;
    stack.PrintStack();

    cout << "\n \n Copy stack \n";
    TStack<int> NewStack(St);
    NewStack.PrintStack();
  }
  catch (TException exception)
  {
    exception.Print();
  }
  return 0;
}
