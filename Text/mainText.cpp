#include <iostream>
#include "TextLib.h"
#include "StringLib.h"

using namespace std;

int main()
{
  
	TString S;
	S = "My string";
	TNode A(S);
	char* C = A.ToStr();
	TString S2(C);
	cout << S2 << endl;
	TText Text;
	cout << "1 string ""2 string""" << endl << endl;
	Text.Ins(Text.GetRoot(), S);
	cout << "Text" << endl;
	cout << Text << endl;
	cout << "Add char 'c'" << endl << endl;
	Text.Ins(Text.GetRoot(), "c");
	cout << "Text:" << endl;
	cout << Text << endl;
	cout << "index ""c""" << endl << endl;
	int p = Text.FindIndex("str");
	cout << "index = " << p << endl;
	return 0;
}
