#include <iostream>
#include "..//StackListLib/StackList.h"

using namespace std;

int main()
{
  cout <<  "\n---Enter stack size---\n";
	int size,temp;
	cin >> size;
		TStackList<int> St(size);
		cout << "\n---Enter the elements---\n";
		for (int i = 1; i <= size; i++)
		{
			cin >> temp;
			St.Put(temp);
		}
		cout << "\n---Your stack---\n";
		St.Print();
		cout << endl;
		cout << "\n---Get element---\n";
		cout << St.Get();
		cout << endl;
  return 0;
}
