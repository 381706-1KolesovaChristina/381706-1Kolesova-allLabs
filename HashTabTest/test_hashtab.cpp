#include "HashTabLib.h"

#include <gtest.h>

TEST(HashTabLib, can_create_default_tab)
{
  ASSERT_NO_THROW (THashTab<int> s);
}
//-------------------------------------------------------------------------------------------------
TEST(HashTabLib, can_create_tab_with_positive_size)
{
  ASSERT_NO_THROW (THashTab<int> s(1));
}
//-------------------------------------------------------------------------------------------------
TEST (HashTabLib, throws_when_create_tab_with_negative_size)
{
  ASSERT_ANY_THROW (THashTab<int> s(-8));
}
//-------------------------------------------------------------------------------------------------
TEST(HashTabLib, can_copy_tab)
{
  THashTab<int> A;
  ASSERT_NO_THROW (THashTab<int> s(A));
}
//-------------------------------------------------------------------------------------------------
TEST(HashTabLib, can_resize)
{
  THashTab<int> A;
  ASSERT_NO_THROW (A.Resize());
}
//-------------------------------------------------------------------------------------------------
TEST (HashTabLib, can_put_key_to_tab)
{
  THashTab<int> A(4);
  ASSERT_NO_THROW (A.Put("kig", 7));
}
//-------------------------------------------------------------------------------------------------
TEST (HashTabLib, can_put_elem_to_tab)
{
  THashTab<int> A(4);
	THElem<int> t("kig", 7);
  ASSERT_NO_THROW (A.Put(t));
}
//-------------------------------------------------------------------------------------------------
TEST (HashTabLib, throws_when_delete_from_empty_tab)
{
  THashTab<int> A(1);
  ASSERT_ANY_THROW (A.Del("kj"));
}
//-------------------------------------------------------------------------------------------------
TEST (HashTabLib, isempty_gives_right_true_answer)
{
  THashTab<int> A(1);
  EXPECT_EQ (true, A.IsEmpty());
}
//-------------------------------------------------------------------------------------------------
TEST (HashTabLib, isempty_gives_right_false_answer)
{
  THashTab<int> A(1);
  A.Put("A", 7);
  EXPECT_EQ (false, A.IsEmpty());
}