#include "List.h"

int main()
{
		TList<int> L;
		int n1, n2, temp;
		cout << "\n---Put the elements in the beginning---\n";
		cout << "\n-Enter the number of elements-\n";
		cin >> n1;
		cout << "\n-Enter the elements-\n";
		for (int i = 1; i <= n1; i++)
		{
			cin >> temp;
			L.PutBegin(temp);
		}
		cout << "\n---Your List---\n";
		L.Print();
		cout << "\n---Put the elements in the end---\n";
		cout << "\n-Enter the number of elements-\n";
		cin >> n2;
		cout << "\n-Enter the elements-\n";
		for (int i = 1; i <= n2; i++)
		{
			cin >> temp;
			L.PutEnd(temp);
		}
		cout << "\n---Your List---\n";
		L.Print();
		cout << "\n---Get the element from the beginning of the List---\n";
		cout << L.GetBegin();
		cout << "\n---Get the element from the end of the List---\n";
		cout<< L.GetEnd();
		cout << "\n---Your List---\n";
		L.Print(); 
		cout << endl;

}
