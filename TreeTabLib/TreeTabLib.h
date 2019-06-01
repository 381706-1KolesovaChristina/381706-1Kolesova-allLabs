#include "TTElemLib.h"
#include <iostream>
#include <locale>

using namespace std;

template <class T>
class TTreeTab
{
public:
	TTElem<T>* root;
	int count;

	TTreeTab ();
 	TTreeTab (int _size, string* _key, int* _data);
	TTreeTab (TTreeTab& A);
	int Height(TTElem<T>* k);
	void ChangeRoot();
	void Put (string _key, T _data);
	void Put (TTElem<T> &A);
	void Del (string _key);
	TTElem<T>* Search(string _key);

	bool IsEmpty();
};

template <class T>
TTreeTab<T>::TTreeTab()
{
	count = 0;
	root = NULL;
}

template <class T>
TTreeTab<T>::TTreeTab(int _count, string* _key, int* _data)
{
	if (_count < 0)
		throw -1;
	else
	{
		count = _count;
		for (int i = 0; i < count; i++)
		{
			TTElem<T> tmp(_key, _data);
			Put(tmp);
		}
	}
}

template <class T>
TTreeTab<T>::TTreeTab(TTreeTab& A)
{
	count = A.count;
	root = A.root;
}
//-------------------------------------------------------------------------------------------------
template <class T>
int TTreeTab<T>::Height(TTElem<T>* k)
{
	int hl = 0, hr = 0;
	if (k == NULL)
		return -1;
	if (k->left != NULL)
	{
		hl = Height(k->left) + 1;
	}
	if (k->right != NULL)
	{
		hr = Height(k->right) + 1;
	}
	if (hl >= hr)
		return hl;
	else 
		return hr;
}

template <class T>
void TTreeTab<T>::ChangeRoot()
{
	if ((Height(root->right) - Height(root->left) == 2)&&(Height(root->right->left) > Height(root->right->right)))
	{
		TTElem<T> *A(root), *B(root->right), *C(root->right->left);	
		if (C->left == NULL)
			C->left = new TTElem<T>();
		C->left->parent = A;
		A->right = C->left;
		if (C->right == NULL)
			C->right = new TTElem<T>();
		C->right->parent = B;
		B->left = C->right;
		C->left = A;
		A->parent = C;
		C->right = B;
		B->parent = C;
		root = C;
	}
	else if ((Height(root->left)-Height(root->right) == 2)&&(Height(root->left->right) > Height(root->left->left)))
	{
		TTElem<T> *a(root), *b(root->left), *c(root->left->right);
		if (c->left == NULL)
			c->left = new TTElem<T>();
		c->left->parent = b;
		b->right = c->left;
		if (c->right == NULL)
			c->right = new TTElem<T>();
		c->right->parent = a;
		a->left = c->right;
		c->left = b;
		b->parent = c;
		c->right = a;
		a->parent = c;
		root = c;
	}
	else if((Height(root->left)-Height(root->right) == 2)&&(Height(root->left->right) <= Height(root->left->left)))
	{
		TTElem<T> *a(root), *b(root->left);
		if (b->right == NULL)
			b->right = new TTElem<T>();
		b->right->parent = a;
		a->left = b->right;
		b->right = a;
		a->parent = b;
		root = b;
	}
	else if((Height(root->right)-Height(root->left) == 2)&&(Height(root->right->left) <= Height(root->right->right)))
	{
		TTElem<T> *a(root), *b(root->right);
		if (b->left == NULL)
			b->left = new TTElem<T>();
		b->left->parent = a;
		a->right = b->left;
		b->left = a;
		a->parent = b;
		root = b;
	}
}

template <class T>
void TTreeTab<T>::Put(string _key, T _data)
{
	TTElem<T> A(_key, _data);
	if (IsEmpty())
	{	
		root = new TTElem<T>(A);
		root->left = NULL;
		root->right = NULL;
		count++;
	}
	else
	{
		bool flag = true;
		TTElem<T>* tmproot = root;
		while (flag)
		{
			if ( _key < tmproot->key)
			{				
				if (tmproot->left != NULL)				
					tmproot = tmproot->left;
				else
				{
					tmproot->left = new TTElem<T> (A);
					(tmproot->left)->parent = tmproot;
					(tmproot->left)->left = NULL;
					(tmproot->left)->right = NULL;
					count++;
					flag = false;
				}
			}
			else if ( A.key > tmproot->key)
			{
				if (tmproot->right != NULL)
					tmproot = tmproot->right;
				else
				{
					tmproot->right = new TTElem<T> (A);
					(tmproot->right)->parent = tmproot;
					(tmproot->right)->left = NULL;
					(tmproot->right)->right = NULL;
					count++;
					flag = false;
				}
			}
			else 
				throw -1;
		}
	}
	ChangeRoot();
}

template <class T>
void TTreeTab<T>::Put(TTElem<T> &A)
{
	try
	{
	if (IsEmpty())
	{	
		root = new TTElem<T>(A);
		root->left = NULL;
		root->right = NULL;
		count++;
	}
	else
	{
		bool flag = true;
		TTElem<T>* tmproot = root;
		while (flag)
		{
			if ( A.key < tmproot->key)
			{				
				if (tmproot->left != NULL)				
					tmproot = tmproot->left;
				else
				{
					tmproot->left = new TTElem<T> (A);
					(tmproot->left)->parent = tmproot;
					(tmproot->left)->left = NULL;
					(tmproot->left)->right = NULL;
					count++;
					flag = false;
					
				}
			}
			else if ( A.key > tmproot->key)
			{
				if (tmproot->right != NULL)
					tmproot = tmproot->right;
				else
				{
					tmproot->right = new TTElem<T> (A);
					(tmproot->right)->parent = tmproot;
					(tmproot->right)->left = NULL;
					(tmproot->right)->right = NULL;
					count++;
					flag = false;
				}
			}
			else 
				throw -1;
		}
	}
	ChangeRoot();
	}
	catch(...)
	{
		cout<<"\nŇŕęîé ęëţ÷ óćĺ ĺńňü!\n";
	}
}

template <class T>
void TTreeTab<T>::Del(string _key)
{
	TTElem<T> *k = Search(_key), *l = Search(_key)->left, *r = Search(_key)->right;
	if (IsEmpty())
		throw -1;
	if (Search(_key) == NULL)
		throw -1;
	if (Search(_key) == root)
		root = NULL;
	else 
	{
		if (k->key < k->parent->key)
			k->parent->left = NULL;
		else
			k->parent->right = NULL;
	}
	if (l != NULL)
		Put(*l);
	if (r != NULL)
		Put(*r);
	count--;
}

template <class T>
TTElem<T>* TTreeTab<T>::Search(string _key)
{
	if (IsEmpty())
		return NULL;
	else
	{
		bool flag = true;
		TTElem<T>* tmproot = root;
		while (flag)
		{
			if (_key < tmproot->key)
			{				
				if (tmproot->left != NULL)				
					tmproot = tmproot->left;
				else
				{
					flag = false;
					return NULL;					
				}
			}
			else if (_key > tmproot->key)
			{
				if (tmproot->right != NULL)
					tmproot = tmproot->right;
				else
				{
					flag = false;
					return NULL;					
				}
			}
			else
			{
				return tmproot;
				flag = false;
			}
		}
	}
}

template <class T>
bool TTreeTab<T>::IsEmpty()
{
	return (count == 0);
}
