
#include "List.h"
#include <gtest.h>

TEST(Elem, can_copy_elem)
{
	TElem<int> elem1(1, 0);
	TElem<int> elem2(elem1);

	ASSERT_EQ(elem1.GetNext(), elem2.GetNext());
	ASSERT_EQ(elem1.GetData(), elem2.GetData());
}

TEST(Elem, can_get_data)
{
	TElem<int> elem(1, 0);
	ASSERT_EQ(elem.GetData(), 1);
}

TEST(Elem, can_get_next)
{
	TElem<int>* _next = 0;
	TElem<int> elem(1, _next);

	ASSERT_EQ(elem.GetNext(), _next);
}

TEST(Elem, can_set_data)
{
	TElem<int> elem;
	elem.SetData(1);
	ASSERT_EQ(elem.GetData(), 1);
}

TEST(Elem, can_set_next)
{
	TElem<int>* _next = 0;
	TElem<int> elem;
	elem.SetNext(_next);

	ASSERT_EQ(elem.GetNext(), _next);
}

TEST(List, can_create_list)
{
	ASSERT_NO_THROW(TList<int> L);
}

TEST(List, can_copy_list)
{
	TList<int> L;

	ASSERT_NO_THROW(TList<int> L1(L));
}

TEST(List, can_put_begin)
{
	TList<int> L;
	L.PutBegin(1);
	L.PutBegin(7);

	ASSERT_EQ(L.GetBegin(), 7);
}

TEST(List, can_put_end)
{
	TList<int> L;
	L.PutEnd(1);
	L.PutEnd(7);

	ASSERT_EQ(L.GetEnd(),7);
}

TEST(List, can_get_begin)
{
	TList<int> L;
	L.PutBegin(1);
	L.PutBegin(2);

	ASSERT_EQ(L.GetBegin(), 2);
}

TEST(List, can_get_end)
{
	TList<int> L;
	L.PutBegin(1);
	L.PutBegin(2);

	ASSERT_EQ(L.GetEnd(), 1);
}

TEST(List, can_get_size)
{
	TList<int> L;
	L.PutBegin(2);
	L.PutBegin(3);

	ASSERT_EQ(L.GetSize(), 2);
}

TEST(List, is_full_false)
{
	TList<int> L;
	ASSERT_FALSE(L.IsFull());
} 

TEST(List, is_empty_true)
{
	TList<int> L;
	ASSERT_TRUE(L.IsEmpty());
}

TEST(List, is_empty_false)
{
	TList<int> L;
	L.PutBegin(1);
	ASSERT_FALSE(L.IsEmpty());
}
