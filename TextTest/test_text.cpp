#include <gtest.h>
#include "TextLib.h"
#include "StringLib.h"

TEST(Node, can_create_char)
{
	ASSERT_NO_THROW(TNode A('c'));
}
//-------------------------------------------------------------------------------------------------
TEST(Node, can_create_string)
{
	TString B;
	B = "This is sparta";
	ASSERT_NO_THROW(TNode A(B));
}
//-------------------------------------------------------------------------------------------------
TEST(Node, can_create_level)
{
	ASSERT_NO_THROW(TNode T1(1));
	ASSERT_NO_THROW(TNode T2(2));
	ASSERT_NO_THROW(TNode T3(3));
	ASSERT_ANY_THROW(TNode T4(4));
}
//-------------------------------------------------------------------------------------------------
TEST(Node, can_assign)
{
	TNode A('c');
	TNode B = A;
	ASSERT_EQ(B.level, 3);
	ASSERT_EQ(B.data, 'c');
}
//-------------------------------------------------------------------------------------------------

TEST(Node, to_string)
{
	TString S;
	S = "This is sparta";
	TNode A(S);
	char* C = A.ToStr();
	TString S2(C);
	ASSERT_TRUE(S == S2);
}
//-------------------------------------------------------------------------------------------------
TEST(Text, can_create_default_text)
{
	ASSERT_NO_THROW(TText Text);
}
//-------------------------------------------------------------------------------------------------
TEST(Text, can_copy)
{
	TText Text;
	TString S("This is string");
	Text.Ins(Text.GetRoot(), S);
	ASSERT_NO_THROW(TText C(Text));
}
//-------------------------------------------------------------------------------------------------
TEST(Text, can_Add_char)
{
	TText Text;
	ASSERT_NO_THROW(Text.Ins(Text.GetRoot(), "a"));
}
//-------------------------------------------------------------------------------------------------
TEST(Text, can_Add_string)
{
	TText Text;
	TString S("This is string");
	ASSERT_NO_THROW(Text.Ins(Text.GetRoot(), S));
}
//-------------------------------------------------------------------------------------------------
TEST(Text, can_add_many_nodes)
{
	TText Text;
	TString S("This is string");
	TString S2("string2");
	TString S3("string3");
	ASSERT_NO_THROW(Text.Ins(Text.GetRoot(), S));
	ASSERT_NO_THROW(Text.Ins(Text.GetRoot(), S2));
	ASSERT_NO_THROW(Text.Ins(Text.GetRoot(), S3));
}
//-------------------------------------------------------------------------------------------------
TEST(Text, can_find)
{
	TText Text;
	TString S("The table");
	Text.Ins(Text.GetRoot(), S);
	TNode* P = Text.Find("This");
	ASSERT_TRUE(P->data == 'T');
	P = P->neigh;
	ASSERT_TRUE(P->data == 'h');
}
//-------------------------------------------------------------------------------------------------
TEST(Text, can_find_index)
{
	TText Text;
	TString S("This is sparta");
	Text.Ins(Text.GetRoot(), S);
	int p = Text.FindIndex("This");
	ASSERT_TRUE(p == 0);
}
//-------------------------------------------------------------------------------------------------
TEST(Text, can_delete)
{
	TText Text;
	TString S("This is sparta");
	Text.Ins(Text.GetRoot(), S);
	TNode* tmp = Text.GetRoot()->nextl->nextl->nextl;
	ASSERT_NO_THROW(Text.Del(tmp, 2));
}
//-------------------------------------------------------------------------------------------------
TEST(NodeIter, can_create)
{
	TString S("This is sparta");
	TNode P(S);
	ASSERT_NO_THROW(TNodeIter i(&P));
}
