#include "cNode.h"
#include <iostream>
using namespace std;

template <typename T>
class cBinarySearchTree {
	friend class cNode<T>;
public:
	cBinarySearchTree()
		:root(NULL){} 
	~cBinarySearchTree()
	{
	}
	void treeInsert(T x)
	{
		root = treeInsert(root, x);
	}
	void treeDelete(T x)
	{
		flag = 0;
		cNode<T>* r = root;
		cNode<T>* p = 0;
		r = search(root, x);
		p = searchParent(root, x);
		if (r)
		{
			treeDelete(root, r, p);
		}
	}
	void treePrint()
	{
		treePrint(root, 0);
	}
	int flag = 0;
private:
	cNode<T>* search(cNode<T>* now, T x)
	{
		if (now->key == NULL)
		{
			return NULL;
		}
		if (now->key == x)
		{
			return now;
		}
		if (now->key < x)
		{
			return search(now->right, x);
		}
		else
		{
			return search(now->left, x);
		}
	}
	cNode<T>* searchParent(cNode<T>* now, T x)
	{
		if (now->key == x)			//now is root
		{
			return NULL;
		}
		if (now->right == nullptr && now->left == nullptr)		//now is leaf
		{
			return NULL;
		}
		else if ((now->left != nullptr && now->right != nullptr))
		{
			if (now->left->key == x || now->right->key == x)
			{
				return now;
			}
			else if (now->key > x)
			{
				return searchParent(now->left, x);
			}
			else
			{
				return searchParent(now->right, x);
			}
		}
		else if (now->left==nullptr)
		{
			if (now->right->key == x)
			{
				return now;
			}
			else if(now->right->key<x)
			{
				return searchParent(now->right, x);
			}
			else
			{
				return NULL;
			}
		}
		else if (now->right == nullptr)
		{
			if (now->left->key == x)
			{
				return now;
			}
			else if (now->left->key > x)
			{
				return searchParent(now->left, x);
			}
			else
			{
				return NULL;
			}
		}
	}
	cNode<T>* treeInsert(cNode<T>* t, T x)
	{
		if(t == NULL)
		{
			t = new cNode<T>(x);
			return t;
		}
		if (x < t->key)
		{
			t->left = treeInsert(t->left, x);
			return t;
		}
		else
		{
			t->right = treeInsert(t->right, x);
			return t;
		}
	}
	void treeDelete(cNode<T>* t, cNode<T>* r, cNode<T>* p)
	{
		if (r == t)
		{
			root = deleteNode(t);
		}
		else if (r == p->left)
		{
			p->left = deleteNode(r);
		}
		else
		{
			p->right = deleteNode(r);
		}
	}
	cNode<T>* deleteNode(cNode<T>* r)
	{
		cNode<T>* s(NULL);
		cNode<T>* parents(NULL);
		if (r->left == NULL && r->right == NULL)
		{
			return NULL;
		}
		else if (r->left == NULL && r->right != NULL)
		{
			return r->right;
		}
		else if (r->left != NULL && r->right == NULL)
		{
			return r->left;
		}
		else
		{
			s = r->right;
			while(s->left!=NULL)
			{ 
				parents = s;
				s = s->left;
			}
			r->key = s->key;
			if (s == r->right)
			{
				r->right = s->right;
			}
			else
			{
				parents->left = s->right;
			}
			return r;
		}
	}
	void treePrint(cNode<T>* t, int step)
	{
		step++;
		for (int i = 1; i < step; i++)
		{
			cout << "    ";
		}
		cout << t->key << endl;
		if (t->left != NULL)
		{
			treePrint(t->left, step);
		}
		if (t->right != NULL)
		{
			treePrint(t->right, step);
		}
	}
	cNode<T>* root;
};