#include <iostream>
#include "Polish.cpp"

using namespace std;

int main()
{
    cout << "Enter math expression:";
    TString str;
    cin >> str;
    cout << str;
    TQueue<char> B;
    B = ConvertToPolish(str);
    cout << " = " << Res(B) << endl;
    return 0;
}
