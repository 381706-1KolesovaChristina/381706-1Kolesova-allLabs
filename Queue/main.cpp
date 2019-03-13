#include <iostream>
#include "Queue.h"
#include "ExceptionLib.h"
using namespace std;

int main()
{ 
  try
  {
    int n;
    cout << "\n---Enter the number elements---\n";
    cin >> n;
    TQueue<int> queue(n);
    int elem;
    cout << "\n---Enter the elements---\n";
    for (int i = 0; i < n; i++)
    {
      cin >> elem;
      queue.Put(elem);
    }
		cout << "\n---Execution result---\n";
    queue.PrintQueue();
    cout << "\n---Copy the queue---\n";
    TQueue <int> queue1(queue);
		cout << "\n---Execution result---\n";
    queue1.PrintQueue();
    cout << "\n---Get the element---\n";
    queue.Get();
		cout << "\n---Execution result---\n";
    queue.PrintQueue();
  }
  catch (MyException exception)
  {
    exception.Print();
  }
	return 0;  
}
