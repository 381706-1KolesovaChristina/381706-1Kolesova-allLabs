#include "..//PolinomialLib/Polinomial.h"

int main()
{
	cout << "\n\n---Create 3 monomials---\n\n";

	int m1[5] = { 1, 2, 3, 4, 5 }, m2[5] = { 6, 7, 8, 9, 0 }, m3[5] = { 0, 1, 9, 2, 6 };
	
	TMonomial M1(5, m1, 2), M2(5, m2, 0), M3(5, m3, 1);
	
	cout << "\n---Created monomials---\n";
	cout << "\tMonom #1: " << M1 << "\n";
	cout << "\tMonom #2: " << M2 << "\n";
	cout << "\tMonom #3: " << M3 << "\n";
	
	cout << "\n---Created polynomials---\n";
	TPolinomial Poly(5);
	Poly += M1;
	Poly += M3;
	cout << "\n---Polynom---\n";
	cout << Poly << "\n";

	return 0;
}
