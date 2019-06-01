#include "PlexLib.h"

#include <gtest.h>


TEST(PointLib, can_create_default_point)
{
  ASSERT_NO_THROW (TPoint s());
}

//-------------------------------------------------------------------------------------------------
TEST(PointLib, can_copy_point)
{
  TPoint s(2, 6);
  ASSERT_NO_THROW (TPoint s1(s));
}
//-------------------------------------------------------------------------------------------------
TEST(PointLib, can_compare_different_points)
{
  TPoint s(2, 6), s1(3,8);
  EXPECT_FALSE (s1 == s);
}
//-------------------------------------------------------------------------------------------------
TEST(PointLib, can_compare_equal_points)
{
  TPoint s(2, 6), s1(2,6);
  EXPECT_TRUE (s1 == s);
}
//-------------------------------------------------------------------------------------------------
TEST(PointLib, can_assign_point)
{
  TPoint s(2, 6), s1(3,8);
  ASSERT_NO_THROW (s1 = s);
}
//-------------------------------------------------------------------------------------------------
TEST(SectionLib, can_create_section)
{
  TPoint s(2, 6), s1(3,8);
  ASSERT_NO_THROW (TSection h(s,s1));
}
//-------------------------------------------------------------------------------------------------
TEST(SectionLib, can_copy_section)
{
  TPoint s(2, 6), s1(3,8);
  TSection h(s, s1);
  ASSERT_NO_THROW (TSection l(h));
}
//-------------------------------------------------------------------------------------------------
TEST(PlexLib, can_create_default_plex)
{
  ASSERT_NO_THROW (TPlex s);
}
//-------------------------------------------------------------------------------------------------
TEST (PlexLib, can_create_plex)
{
  TPoint A, B(7,4);
  ASSERT_NO_THROW (TPlex P1(&A, &B));
}
//-------------------------------------------------------------------------------------------------
TEST(PlexLib, can_copy_plex)
{
  TPoint A, B(7,4);
  TPlex N(&A,&B);
  ASSERT_NO_THROW (TPlex F(N));
}
//-------------------------------------------------------------------------------------------------
TEST (PlexLib, can_search_point)
{
  TPoint A, B(7,4);
  TPoint *k;
  TPlex s(&A,&B);
  ASSERT_NO_THROW (k = (s.Search(&A)));
}
//-------------------------------------------------------------------------------------------------
TEST (PlexLib, search_gives_right_answer)
{
  TPoint A, B(7,4);
  TPlex s(&A,&B);
  TPoint k = *(s.Search(&A));
  EXPECT_TRUE (A == k);
}
//-------------------------------------------------------------------------------------------------
TEST (PlexLib, can_add_point)
{
  TPoint A, B(7,4), C(0,15);
  TPlex P(&A, &B);
  ASSERT_NO_THROW (P.Add(&A, &C));
}

