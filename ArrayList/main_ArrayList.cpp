#include <iostream>
#include "ArrayList.h"

int main()
{
	try
	{
		std::cout << "\n---Create a list with a size of 10---\n" << std::endl;
		TArrayList <int> L1;
		std::cout << "\n---Put in the begin of element 6---\n";
		L1.PutBegin(6);
		std::cout << "\n---Put in the end of element 4 and 7---\n";
		L1.PutEnd(4);
		L1.PutEnd(7);
		std::cout << "\n---Get in the end---\n";
		std::cout << L1.GetEnd();
		std::cout << "\n---Get in the begin---\n";
		std::cout << L1.GetBegin();
	}
	catch (MyException exception)
	{
		exception.Print();
	}
	return 0;
}
