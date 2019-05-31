#pragma once
#include "StackListLib.h"
#include "NodeLib.h"
using namespace std;

class TNodeIter
{
protected:
	TNode* root;
	TNode* cur;
	TStackList <TNode*> St;

public:
	TNodeIter(TNode*r);
	TNodeIter& GoNext(); 
	void Reset(); 
	bool IsEnd(); 
	TNode* operator() ();
	TNodeIter& operator++ (int);
};

TNodeIter::TNodeIter(TNode *r)
{
	root = cur = r;
	St.Put(root);
}

TNodeIter& TNodeIter::GoNext()
{
	cur = St.Get();
	if (cur->neigh != 0)
	{
		St.Put(cur->neigh);
	}
	if (cur->nextl != 0)
		St.Put(cur->nextl);
	return *this;
}

void TNodeIter::Reset()
{
	cur = root;
	while (!(St.IsEmpty()))
		St.Get();
	St.Put(cur);
}

bool TNodeIter::IsEnd()
{
	return St.IsEmpty();
}

TNode* TNodeIter::operator()()
{
	return cur;
}

TNodeIter& TNodeIter::operator++(int)
{
	return (*this)=this->GoNext();
}