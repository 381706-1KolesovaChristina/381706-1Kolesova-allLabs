#pragma once
#include "StringLib.h"
#include "StackListLib.h"


class TNode 
{
public:
	TNode* nextl;
	TNode* neigh;
	int level; 
	char data;
	static TNode* start; 
	static TNode* end;
	static TNode* _free;
	static char* mas; 
	static int sizeMas; 
	char* ToStr();
	TNode* Clone();

	TNode(char c);
	TNode(TString s);
	TNode(int _level);
	TNode(TNode& other);
	void Init(int size);
	void* operator new (size_t n);
	void operator delete (void* a);
	static void GC(); 

	TNode& operator=(const TNode& a);
	TNode& operator+=(TNode& a);
	TNode& operator+=(char c);
	TNode& operator+=(char*c);
};

TNode* TNode::start = 0;
TNode* TNode::end = 0;
TNode* TNode::_free = 0;
char* TNode::mas = 0;
int TNode::sizeMas = 0;

TNode::TNode(char c)
{
	Init(200000);
	nextl = NULL;
	neigh = NULL;
	level = 3; 
	data = c;
}

TNode::TNode(TString s)
{
	Init(200000);
	if (s.len == 0)
		throw -1;
	data = 0;
	nextl = new TNode(s[0]);
	level = 2;
	neigh = 0;
	TNode *a = nextl;
	for (int i = 1; i < s.len; i++)
	{
		a->neigh = (new TNode(s[i]));
		a = a->neigh;
	}
}

TNode::TNode(int _level)
{
	Init(200000);
	if ((_level < 0) || (_level > 3))
		throw -1;
	nextl = 0;
	neigh = 0;
	level = _level;
	data = -1;
}

TNode::TNode(TNode& other)
{
	data = other.data;
	nextl = other.nextl;
	neigh = other.neigh;
	level = other.level;
}

TNode& TNode::operator=(const TNode& a)
{
	data = a.data;
	level = a.level;
	neigh = a.neigh;
	nextl = a.nextl;
	return *this;
}

TNode& TNode::operator+=(TNode& a)
{
	if (level < a.level)
		throw -1;
	TStackList<TNode*> st;
	st.Put(this);		
	bool f = true;
	TNode* t;
	while (f || st.IsEmpty()) 
	{
		t = st.Get();
		if (t->nextl != 0)
			st.Put(t->nextl);
		if (t->neigh != 0)
			st.Put(t->neigh);
		if ((t->level = a.level) && (t->neigh == 0))
		{
			f = false;
			t->neigh = a.Clone();
		}
	}
	return *this;
}

TNode& TNode::operator+=(char c)
{
	TNode simbol(c);
	return (*this += simbol);
}

TNode& TNode::operator+=(char* c)
{
	TNode word(c);
	return (*this += word);
}

char* TNode::ToStr()
{
	int l = 0;
	int j = 0;
	TStackList<TNode*> st;
	TNode* t;
	st.Put(this);
	while (!st.IsEmpty())
	{
		t = st.Get();
		if (t->nextl != 0)
			st.Put(t->nextl);
		if (t->neigh != 0)
			st.Put(t->neigh);
		if (t->level == 3)
			l++;
	}
	char* res = new char[l + 1];
	st.Put(this);
	while (!st.IsEmpty()) 
	{
		t = st.Get();
		if (t->level == 3)
		{
			res[j] = t->data;
			j++;
		}
		if (t->neigh != 0)
			st.Put(t->neigh);
		if (t->nextl != 0)
			st.Put(t->nextl);
	}
	res[l] = 0;
	return res;
}

TNode* TNode::Clone()
{
	TNode* res = new TNode(*this);
	TStackList<TNode*> st;
	TStackList<TNode*> copy;
	st.Put(this);
	copy.Put(res);
	while (!st.IsEmpty())
	{
		TNode* t = st.Get();
		TNode* c = copy.Get();
		if (t->neigh != 0)
		{
			c->neigh = new TNode(*(t->neigh));
			st.Put(t->neigh);
			copy.Put(c->neigh);
		}
		if (t->nextl != 0)
		{
			c->nextl = new TNode(*(t->nextl));
			st.Put(t->nextl);
			copy.Put(c->nextl);
		}
	}
	return res;
}

void TNode::Init(int size)
{
	if (mas == 0) 
	{
		sizeMas = size;
		int l = size * sizeof(TNode);
		mas = new char[l];
		start = (TNode*)(mas);
		end = _free = start;
		for (int i = 1; i < size; i++)
		{
			int j = i * sizeof(TNode);
			end->neigh = (TNode*)(&mas[j]); 
			end = end->neigh;
		}
		end->neigh = 0;
	}
}

void * TNode::operator new(size_t n)
{
	if (_free == 0)
		GC();
	if (_free != 0)
	{
		TNode* a = _free; 
		_free = _free->neigh; 
		return a;
	}

	return NULL;
}

void TNode::operator delete(void * a)
{
	TNode* t = (TNode*)(a);
	t->neigh = _free; 
	_free = t;
	t->data = -1;
}

void TNode::GC()
{
	_free = 0; 
	for (int i = 0; i < sizeMas; i++)
	{
		int j = i * sizeof(TNode);
		if (((TNode*)(&mas[j]))->data == '-1')
		{
			((TNode*)(&mas[j]))->neigh = _free;
			_free = (TNode*)(&mas[j]);
		}
	}
}