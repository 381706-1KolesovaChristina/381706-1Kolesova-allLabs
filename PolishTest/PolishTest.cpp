#include "..//PolishLib/Polish.h"
#include <gtest.h>


TEST(Polish, can_get_priority)
{
	EXPECT_EQ(GetPriority(')'), 1);
	EXPECT_EQ(GetPriority('('), 1);
	EXPECT_EQ(GetPriority('+'), 2);
	EXPECT_EQ(GetPriority('-'), 2);
	EXPECT_EQ(GetPriority('*'), 3);
	EXPECT_EQ(GetPriority('/'), 3);
}

TEST(Polish, can_check_is_operation)
{
	EXPECT_EQ(IsOperation('+'), true);
	EXPECT_EQ(IsOperation('+'), true);
	EXPECT_EQ(IsOperation('*'), true);
	EXPECT_EQ(IsOperation('/'), true);
	EXPECT_EQ(IsOperation(')'), true);
	EXPECT_EQ(IsOperation('('), true);
	EXPECT_EQ(IsOperation('.'), false);
}

TEST(Polish, can_convert_to_polish)
{
	char s[] = "4+5";
	TString str(s);
	TQueue<char> A;
        A = ConvertToPolish(str);
	
	EXPECT_EQ('{', A.Get());
	EXPECT_EQ('4', A.Get());
	EXPECT_EQ('}', A.Get());
	EXPECT_EQ('{', A.Get());
	EXPECT_EQ('5', A.Get());
	EXPECT_EQ('}', A.Get());
	EXPECT_EQ('+', A.Get());
}

TEST(Polish, can_add)
{
  char s[] = "5+4";
  TString str(s);
  TQueue<char> B;
  B = ConvertToPolish(str);
  EXPECT_EQ(9, Res(B));
}
TEST(Polish, can_subtract) 
{
  char s[] = "10-5";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPolish(A);

  EXPECT_EQ(5, Res(B));
}

TEST(Polish, can_multiply)
{
  char s[] = "5*4";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPolish(A);

  EXPECT_EQ(20, Res(B));
}

TEST(Polish, throw_when_math_expression_have_is_an_unacceptable_symbol)
{
  char s[] = "5#6";
  TString A(s);
  TQueue<char> B;

  ASSERT_ANY_THROW(B = ConvertToPolish(A));
}

TEST(Polish, throw_when_first_operation_is_something)
{
  char s[] = "*5+8";

  TString A(s);
  TQueue<char> B;

  ASSERT_ANY_THROW(B = ConvertToPolish(A));
}

TEST(Polish, throw_when_kol_sk_wrong)
{
  char s[] = "-2+8)";
  char s1[] = "(-2+8";

  TString A(s), B(s1);
  TQueue<char> C, D;

  ASSERT_ANY_THROW(C = ConvertToPolish(A));
  ASSERT_ANY_THROW(D = ConvertToPolish(B));
}
TEST(Polish, can_del)
{
  char s[] = "10/2";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPolish(A);

  EXPECT_EQ(5, Res(B));
}
