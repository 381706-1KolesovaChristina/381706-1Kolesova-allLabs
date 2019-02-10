#include "../gtest/gtest.h"
#include "../StackLib/Stack.h"

TEST(TStack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(TStack<int> S(10));
}

TEST(TStack, throws_when_create_stack_with_negative_size)
{
  ASSERT_ANY_THROW(TStack<int> S(-10));
}

TEST(Stack, can_put_and_get)
{
  TStack <int> S(3);
  S.Put(3);
  ASSERT_EQ(3, S.Get());
}

TEST(TQueue, can_copy_stack)
{
  TStack<int> S(3);
  S.Put(3);
  ASSERT_NO_THROW(TStack<int> S1(S));
}

TEST(Stack, correct_order_of_return_values)
{
  TStack <int> S(3);
  S.Put(3);
  S.Put(4);
  S.Put(5);
  ASSERT_EQ(5, S.Get());
  ASSERT_EQ(4, S.Get());
  ASSERT_EQ(3, S.Get());
}

TEST(Stack, is_full_false)
{
  TStack <int> S(3);
  ASSERT_FALSE(S.IsFull());
}

TEST(Stack, is_full_true)
{
  TStack <int> S(3);
  S.Put(3);
  S.Put(4);
  S.Put(5);
  ASSERT_TRUE(S.IsFull());
}

TEST(Stack, is_empty_false)
{
  TStack <int> S(3);
  S.Put(3);
  S.Put(4);
  ASSERT_FALSE(S.IsEmpty());
}

TEST(Stack, is_empty_true)
{
  TStack <int> S(3);
  ASSERT_TRUE(S.IsEmpty());
}

TEST(Stack, throws_when_in_full_stack_put_elem)
{
  TStack <int> S(3);
  S.Put(3);
  S.Put(4);
  S.Put(5);
  ASSERT_ANY_THROW(S.Put(6));
}

TEST(Stack, throws_when_from_empty_stack_get_elem)
{
  TStack <int> S(5);
  ASSERT_ANY_THROW(S.Get());
}
