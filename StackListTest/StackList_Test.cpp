#include "gtest.h"
#include "../StackListLib/StackList.h"

TEST(StackList, can_create_stacklist)
{
	ASSERT_NO_THROW(TStackList<int> St);
}

TEST(StackList, can_stacklist_create_with_size)
{
	ASSERT_NO_THROW(TStackList<int> St(5));
}

TEST(StackList, throws_when_create_stacklist_with_negative_size)
{
	ASSERT_ANY_THROW(TStackList<int> St(-5));
}

TEST(StackList, can_copy_stacklist)
{
	TStackList<int> St1(5);
	ASSERT_NO_THROW(TStackList<int> St(St1));
}

TEST(StackList, can_get_size)
{
	TStackList<int> St(5);
	St.Put(1);
	St.Put(2);
	St.Put(3);
	ASSERT_EQ(St.GetSize(), 3);
}

TEST(StackList, can_get_maxsize)
{
	TStackList<int> St(5);
	ASSERT_EQ(St.GetMaxSize(), 5);
}

TEST(StackList, can_put)
{
	TStackList<int> St(5);

	ASSERT_NO_THROW(St.PutBegin(1));
}

TEST(StackList, throws_when_put_elem_in_full_stacklist)
{
	TStackList<int> St(1);
	St.Put(1);
	ASSERT_ANY_THROW(St.Put(2));
}

TEST(StackList, can_get)
{
	TStackList<int> St(5);
	St.Put(1);
	ASSERT_NO_THROW(St.Get());
}

TEST(StackList, can_get_correctly)
{
	TStackList<int> St(5);
	St.Put(1);
	St.Put(2);
	EXPECT_EQ(2, St.Get());
}
TEST(StackList, throws_when_get_elem_from_empty_stack)
{
	TStackList <int> St(5);
	ASSERT_ANY_THROW(St.Get());
}

TEST(StackList, is_full_true)
{
	TStackList<int> St(3);
	
	St.Put(1);
	St.Put(2);
	St.Put(3);
	ASSERT_TRUE(St.IsFull());
}

TEST(StackList, is_full_false)
{
	TStackList<int> St(5);

	St.Put(1);
        ASSERT_FALSE(St.IsFull());
}

TEST(StackList, is_empty_true)
{
	TStackList<int> St(5);

	ASSERT_TRUE(St.IsEmpty());
}

TEST(StackList, is_empty_false)
{
	TStackList<int> St(5);
	St.Put(1);
        ASSERT_FALSE(St.IsEmpty());
}

