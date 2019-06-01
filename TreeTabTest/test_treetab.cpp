#include "TreeTabLib.h"

#include <gtest.h>

TEST(TreeTabLib, can_create_default_tab)
{
  ASSERT_NO_THROW (TTreeTab<int> s);
}
//-------------------------------------------------------------------------------------------------
TEST(TreeTabLib, can_copy_tab)
{
  TTreeTab<int> A;
  ASSERT_NO_THROW (TTreeTab<int> s(A));
}
//-------------------------------------------------------------------------------------------------
TEST(TreeTabLib, can_count_height)
{
  TTreeTab<int> A;
	TTElem<int> b("jk", 7);
	A.Put(b);
	A.Put("kig", 7);
  ASSERT_NO_THROW (int h = A.Height(A.root));
}
//-------------------------------------------------------------------------------------------------
TEST(TreeTabLib, height_gives_right_answer)
{
  TTreeTab<int> A;
	TTElem<int> b("jk", 7);
	A.Put(b);
	A.Put("kig", 7);
  EXPECT_EQ (A.Height(A.root), 1);
}
//-------------------------------------------------------------------------------------------------
TEST (TreeTabLib, can_put_string_to_tab)
{
  TTreeTab<int> A;
  ASSERT_NO_THROW (A.Put("kig", 7));
}
//-------------------------------------------------------------------------------------------------
TEST (TreeTabLib, can_put_elem_to_tab)
{
  TTreeTab<int> A;
	TTElem<int> b("jk", 7);
  ASSERT_NO_THROW (A.Put(b));
}
//-------------------------------------------------------------------------------------------------
TEST (TreeTabLib, can_change_root)
{
  TTreeTab<int> A;
	TTElem<int> b("jk", 7);
	A.Put(b);
  ASSERT_NO_THROW (A.ChangeRoot());
}
//-------------------------------------------------------------------------------------------------
TEST (TreeTabLib, can_search_in_tab)
{
  TTreeTab<int> A;
  A.Put("kif", 98);
  ASSERT_NO_THROW (A.Search("kif"));
}

//-------------------------------------------------------------------------------------------------
TEST(TreeTabLib, can_delete_from_tab)
{
  TTreeTab<int> s;
	TTElem<int> A("A", 3);
	s.Put(A);
	ASSERT_NO_THROW (s.Del("A"));
}

//-------------------------------------------------------------------------------------------------
TEST (TreeTabLib, isempty_gives_right_true_answer)
{
  TTreeTab<int> A;
  EXPECT_EQ (true, A.IsEmpty());
}
//-------------------------------------------------------------------------------------------------
TEST (TreeTabLib, isempty_gives_right_false_answer)
{
  TTreeTab<int> A;
	A.Put("kdgjh", 8);
  EXPECT_EQ (false, A.IsEmpty());
}
