#include "SortTabLib.h"

#include <gtest.h>


TEST(SortTabLib, can_create_tab_with_positive_size)
{
  ASSERT_NO_THROW (TSortTab<int> s(1));
}
//-------------------------------------------------------------------------------------------------
TEST (SortTabLib, throws_when_create_tab_with_negative_size)
{
  ASSERT_ANY_THROW (TSortTab<int> s(-8));
}
//-------------------------------------------------------------------------------------------------
TEST(SortTabLib, can_copy_tab)
{
  TSortTab<int> A;
  ASSERT_NO_THROW (TSortTab<int> s(A));
}
//-------------------------------------------------------------------------------------------------
TEST (SortTabLib, can_put_string_to_tab)
{
  TSortTab<int> A(4);
  ASSERT_NO_THROW (A.Put("kig", 7));
}
//-------------------------------------------------------------------------------------------------
TEST (SortTabLib, can_put_elem_to_tab)
{
  TSortTab<int> A(4);
	TSElem<int> b("jk", 7);
  ASSERT_NO_THROW (A.Put(b));
}
//-------------------------------------------------------------------------------------------------
TEST (SortTabLib, can_resize)
{
  TSortTab<int> A(1);
  ASSERT_NO_THROW (A.Resize());
}
//-------------------------------------------------------------------------------------------------
TEST (SortTabLib, can_get_index)
{
  TSortTab<int> A(4);
  A.Put("kif", 98);
	int k;
  ASSERT_NO_THROW (k = A.Index("kif"));
}
//-------------------------------------------------------------------------------------------------
TEST (SortTabLib, get_index_gives_right_answer)
{
  TSortTab<int> A(4);
  A.Put("kif", 98);
	int k = A.Index("kif");
  EXPECT_EQ (0, k);
}
//-------------------------------------------------------------------------------------------------
TEST (SortTabLib, can_get_from_tab)
{
  TSortTab<int> A(4);
  A.Put("kif", 98);
	int k;
  ASSERT_NO_THROW (k = A["kif"]);
}
//-------------------------------------------------------------------------------------------------
TEST (SortTabLib, get_gives_right_answer)
{
  TSortTab<int> A(2);
  A.Put("bol", 8);
	int k = A["bol"];
	EXPECT_EQ (8, k);
}
//-------------------------------------------------------------------------------------------------
TEST(SortTabLib, can_delete_from_tab)
{
  TSortTab<int> s(10);
	TSElem<int> A("A", 3);
	s.Put(A);
	ASSERT_NO_THROW (s.Del("A"));
}
//-------------------------------------------------------------------------------------------------
TEST (SortTabLib, isfull_gives_right_true_answer)
{
  TSortTab<int> A(1);
  A.Put("kdgjh", 8);
  EXPECT_EQ (true, A.IsFull());
}
//-------------------------------------------------------------------------------------------------
TEST (SortTabLib, isfull_gives_right_false_answer)
{
  TSortTab<int> A(1);
  EXPECT_EQ (false, A.IsFull());
}
//-------------------------------------------------------------------------------------------------
TEST (SortTabLib, isempty_gives_right_true_answer)
{
  TSortTab<int> A(1);
  EXPECT_EQ (true, A.IsEmpty());
}
//-------------------------------------------------------------------------------------------------
TEST (SortTabLib, isempty_gives_right_false_answer)
{
  TSortTab<int> A(1);
	A.Put("kdgjh", 8);
  EXPECT_EQ (false, A.IsEmpty());
}
