#pragma once
#include "NodeLib.h"
#include "NodeIterLib.h"
class TText
{
protected:
	TNode *root;
public:
	TText();
	TText(TNode* r);
	TText(TText& T);
	TNode* GetRoot();
	char* Copy(int start, int n);
	void Del(TNode* start, int n);
	void Ins(TNode* start, TNode* d); 
	void Ins(TNode* start, TString S);
	void Ins(TNode* start, char c);
	TNode* Find(char* a); 
	int FindIndex(char* a); 
	int GetCount();
	friend ostream& operator<<(ostream& ostr, const TText &T);

};

TText::TText()
{
	root = new TNode(0);
}

TText::TText(TNode* r)
{
	root = r;
}

TText::TText(TText& T)
{
	root = T.root->Clone();
}

TNode* TText::GetRoot()
{
	return root;
}

char* TText::Copy(int start, int n)
{
	char* res = new char[n];
	bool f = false;
	int pos = 0;
	TNodeIter t(root);
	while (pos != start)
	{
		if (t.IsEnd())
			throw -2;
		if (t()->level == 3)
			pos++;
		t++;
	}
	pos = 0;
	while (pos < n)
	{
		if (t.IsEnd())
			throw -1;
		if (t()->level == 3)
		{
			res[pos] = t()->data;
			pos++;
		}
		t++;
	}
	return res;
}

void TText::Del(TNode* start, int n)
{

	TNodeIter iter(root);
	int i = n;
	int count = 0;
	bool flag = false;
	bool nextflag = false;
	bool sameflag = false;
	TNode* temp1;
	TNode* temp2;
	TNode* temp3;

	while (iter.IsEnd() != true)
	{
		iter++;
		TNode* tmp = iter();
		if (tmp->neigh == start)
		{
			temp1 = tmp;
			sameflag = true;
		}
		if (tmp->nextl == start)
		{
			temp3 = tmp;
			nextflag = true;
		}
		if (tmp == start)
		{
			delete tmp;
			i--;
			flag = true;
		}
		else if (flag == true && tmp->level == 3)
		{
			if (i == 1)
				temp2 = tmp->neigh;
			delete tmp;
			i--;
		}
		if (i == 0)
			break;
	}
	if (nextflag == true)
		temp3->nextl = (temp2);
	if (sameflag == true)
		temp1->nextl = (temp2);
		
}

int TText::GetCount()
{
	TNodeIter i(root);
	int count = 0;
	for (; !(i.IsEnd()); i++)
		if (i()->level == 3)
			count++;
	return count;
}

void TText::Ins(TNode* start, TNode* d)
{ 
	if (start->level != d->level)
		throw -1;
	d->neigh = (start->neigh);
	start->neigh = d;
}

void TText::Ins(TNode* start, TString S)
{
	if (start->level == 3)
		throw -1;
	TNode* N = new TNode(S);
	if (start->level == 0)
	{
		if (start->nextl == 0)
			start->nextl = new TNode(1);
		start = start->nextl;
	}
	if (start->level == 1)
	{
		if (start->nextl == 0)
		{
			start->nextl = N;
			return;
		}
		start = start->nextl;
	}
	N->neigh = start->neigh;
	start->neigh = N;
}

void TText::Ins(TNode* start, char c)
{
	if (start->level != 3)
		throw -1;
	TNode* N = new TNode(c);
	if (start->level == 0)
	{
		if (start->nextl == 0)
			start->nextl = new TNode(1);
		start = start->nextl;
	}
	if (start->level == 1)
	{
		if (start->nextl == 0)
			start->nextl = (new TNode(1));
		start = start->nextl;
	}
	if (start->level == 2)
	{
		if (start->nextl == 0)
		{
			start->nextl = (N);
			return;
		}
		start = start->nextl;

	}
	N->neigh = (start->neigh);
	start->neigh = (N);
}

TNode* TText::Find(char* a)
{
	TNodeIter i(root);
	for (; !(i.IsEnd()); i++)
	{
		if (i()->data == a[0])
		{
			bool f = true;
			TNodeIter j = i;
			int t = 1;
			while ((!(j.IsEnd())) && (a[t]!='\0'))
			{
				if (j()->data != a[t])
				{
					f = false;
					break;
				}
				t++;
			}
			if (f = true)
				return i();
		}
	}
	return NULL;
}

int TText::FindIndex(char * a)
{
	int k = -1;
	TNodeIter i(root);
	for (; !(i.IsEnd()); i++)
	{
		if (i()->level == 3)
			k++;
		if (i()->data == a[0])
		{
			bool f = true;
			TNodeIter j = i;
			int t = 1;
			while ((!(j.IsEnd())) && (a[t] != '\0'))
			{
				if (j()->data != a[t])
				{
					f = false;
					break;
				}
				t++;
			}
			if (f = true)
				return k;
		}
	}
	return -1;
}

ostream& operator<<(ostream& ostr, const TText &T)
{
	TNodeIter i(T.root);
	for (int k = 0; k < 3; k++)
	{
		if (i()->nextl == 0)
			return ostr;
		i++;
	}
	for (; !(i.IsEnd()); i++)
	{
		if ((i()->level == 3) && (i()->data != -1))
			ostr << i()->data;
		else if ((i()->level == 2) && (i()->neigh != 0) && (i()->level!= 0))
			ostr << " ";
		else if (i()->level == 1)
			ostr << endl;
	}
	return ostr;
}