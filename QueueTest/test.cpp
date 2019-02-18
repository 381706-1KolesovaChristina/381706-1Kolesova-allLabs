#include <gtest.h>
#include "Queue.h"

TEST(TQueue, can_create_queue_with_positive_size)
{
  ASSERT_NO_THROW(TQueue <int> Q(10));
}

TEST(Queue, throws_when_create_queue_with_negative_size)
{
  ASSERT_ANY_THROW(TQueue <int> Q(-10));
}

TEST(Queue, can_put_and_get)
{
  TQueue <int> Q(10);
  Q.Put(1);
  ASSERT_EQ(1, Q.Get());
}
TEST(TQueue, can_copy_queue)
{
  TQueue<int> Q(3);
  Q.Put(5);
  Q.Put(4);
  ASSERT_NO_THROW(TQueue<int> Q1(Q));
}

TEST(Queue, correct_order_of_return_values)
{
  TQueue <int> Q(3);
  Q.Put(5);
  Q.Put(4);
  Q.Put(3);
  ASSERT_EQ(5, Q.Get());
  ASSERT_EQ(4, Q.Get());
  ASSERT_EQ(3, Q.Get());
}
TEST(Queue, is_full_true)
{
  TQueue <int> Q(3);
  Q.Put(5);
  Q.Put(4);
  Q.Put(3);
  ASSERT_TRUE(Q.IsFull());
}

TEST(Queue, is_full_false)
{
  TQueue <int> Q(3);
  Q.Put(5);
  ASSERT_FALSE(Q.IsFull());
}

TEST(Queue, is_empty_true)
{
  TQueue <int> Q(3);
  ASSERT_TRUE(Q.IsEmpty());
}

TEST(Queue, is_empty_false)
{
  TQueue <int> Q(3);
  Q.Put(5);
  Q.Put(4);
  Q.Put(3);
  ASSERT_FALSE(Q.IsEmpty());
}

TEST(Stack, throws_when_in_full_stack_put_elem)
{
  TQueue <int> Q(3);
  Q.Put(5);
  Q.Put(4);
  Q.Put(3);
  ASSERT_ANY_THROW(Q.Put(2));
}

TEST(Stack, throws_when_from_empty_stack_get_elem)
{
  TQueue <int> Q(3);
  ASSERT_ANY_THROW(Q.Get());
}

