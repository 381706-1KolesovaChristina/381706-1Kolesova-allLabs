#include "Vector.h"

int main()
{
	cout << "Vectors:";
	TVector <int> V1(3), V2(3), R(3);
	for (int i = 0; i < 3; i++)
	{
		V1[i] = (i+3)*2;
		V2[i] = i*3+2;
	}
	cout << "\n\nV1: " << V1 << endl;
	cout << "V2: " << V2 << endl;

	cout << "\n Arithmetic operations:\n";
	try
	{
		R = V1 + V2;
		cout << "Result V1 + V2: " << R << endl;
	}
	catch (MyException exp)
	{
		exp.Print();
	}

	try
	{
		R = V1 - V2;
		cout << "Result V1 - V2: " << R << endl;
	}
	catch (MyException exp)
	{
		exp.Print();
	}

	try
	{
		int k = V1 * V2;
		cout << "Result V1 * V2: " << k << endl;
	}
	catch (MyException exp)
	{
		exp.Print();
	}

	cout << "\n Using input / output streams:\n";
	TVector <int> V(5);
	cin >> V;
	cout << "\n Entered vector: " << V << endl;
	return 0;
}