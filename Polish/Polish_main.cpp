#include "Polish.h"

int  main()
{
  try
  {
    cout << "\n---Enter your math expression---\n";
    TString s;
    cin >> s;
    cout <<"\n----Your expression:"<< s;
    TQueue<char> B;
    B = ConvertToPolish(s);
    B.Print();
    cout << "\n----Polish version your expression: " << Rez(B) << endl;
  }
  
  catch (MyException exp)
  {
    exp.Print();
  }
  return 0;
}
