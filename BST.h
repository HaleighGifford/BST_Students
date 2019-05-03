//*****************************************************************************************************

#ifndef BST_H
#define BST_H
#include <new>
#include <algorithm>
#include <cmath>
#include "node.h"

//*****************************************************************************************************

template <typename TYPE>
class BST
{
	private:
			Node<TYPE> * root;

			void _destruct(Node<TYPE> * pRoot);
			Node<TYPE> * _retrieve(Node<TYPE> * pRoot, const TYPE & dataOut) const;
			Node<TYPE> * _insert(Node<TYPE> * pRoot, const TYPE & dataIn);
			Node<TYPE> * _remove(Node<TYPE> * pRoot, const TYPE & dataOut);
			void _inorderTraverse(Node<TYPE> * pRoot, void(*process)(TYPE d)) const;
			int _getCount(Node<TYPE> * pRoot) const;
			int _getHt(Node<TYPE> * pRoot) const;
			bool _isComplete(Node<TYPE> * pRoot) const;
			bool _isBalanced(Node<TYPE> * pRoot) const;

	public:
			BST();
			~BST();
			bool retrieve(TYPE & dataOut) const;
			bool insert(const TYPE & dataIn);
			bool remove(TYPE & dataOut);
			bool update(const TYPE & dataIn);
			void inorderTraverse(void(*process)(TYPE d)) const;
			int getCount() const;
			int getHt() const;
			bool isEmpty() const;
			bool isFull() const;
			bool isComplete() const;
			bool isBalanced() const;

};

//*****************************************************************************************************

template <typename TYPE>
BST<TYPE> ::BST()
{
	root = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
BST<TYPE> ::~BST()
{
	_destruct(root);
}

//*****************************************************************************************************

template <typename TYPE>
void BST<TYPE> ::_destruct(Node<TYPE> * pRoot)
{
	if (pRoot)
	{
		_destruct(pRoot->left);
		_destruct(pRoot->right);
		delete pRoot;
	}
}

//*****************************************************************************************************

template <typename TYPE>
bool BST<TYPE> ::retrieve(TYPE & dataOut)const
{
	bool success = false;
	Node<TYPE> * pFound;

	pFound = _retrieve(root, dataOut);

	if (pFound)
	{
		dataOut = pFound->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
Node<TYPE> * BST<TYPE> ::_retrieve(Node<TYPE> * pRoot, const TYPE & dataOut) const
{
	if (pRoot)
	{
		if (pRoot->data > dataOut)
			pRoot = _retrieve(pRoot->left, dataOut);
		else if (pRoot->data < dataOut)
			pRoot = _retrieve(pRoot->right, dataOut);
	}

	return pRoot;
}

//*****************************************************************************************************

template <typename TYPE>
bool BST<TYPE> ::insert(const TYPE & dataIn)
{
	bool success = false;
	Node<TYPE> * pFound;

	pFound = _retrieve(root, dataIn);

	if (!pFound)
	{
		root = _insert(root, dataIn);
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
Node<TYPE> * BST<TYPE> ::_insert(Node<TYPE> * pRoot, const TYPE & dataIn)
{
	if (pRoot)
	{
		if (pRoot->data > dataIn)
			pRoot->left = _insert(pRoot->left, dataIn);
		else
			pRoot->right = _insert(pRoot->right, dataIn);
	}
	else
		pRoot = new Node<TYPE>(dataIn);

	return pRoot;
}

//*****************************************************************************************************

template <typename TYPE>
bool BST<TYPE> ::remove(TYPE & dataOut)
{
	bool success = false;
	Node<TYPE> * pFound;

	pFound = _retrieve(root, dataOut);

	if (pFound)
	{
		dataOut = pFound->data;
		root = _remove(root, dataOut);
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
Node<TYPE> * BST<TYPE> ::_remove(Node<TYPE> * pRoot, const TYPE & dataOut)
{
	Node<TYPE> * pDel;
	Node<TYPE> * pMax;

	if (pRoot)
	{
		if (pRoot->data > dataOut)
			pRoot->left = _remove(pRoot->left, dataOut);
		else if (pRoot->data < dataOut)
			pRoot->right = _remove(pRoot->right, dataOut);
		else
		{
			if ((pRoot->left) && (pRoot->right))
			{
				pMax = pRoot->left;

				while ((pMax) && (pMax->right))
				{
					pMax = pMax->right;
				}

				pRoot->data = pMax->data;
				pRoot->left = _remove(pRoot->left, pMax->data);
			}
			else
			{
				pDel = pRoot;

				if (pRoot->left != nullptr)
					pRoot = pRoot->left;
				else
					pRoot = pRoot->right;

				delete pDel;
			}
		}
	}

	return pRoot;
}

//*****************************************************************************************************

template <typename TYPE>
bool BST<TYPE> ::update(const TYPE & dataIn)
{
	bool success = false;
	Node<TYPE> * pFound;

	pFound = _retrieve(root, dataIn);

	if (pFound)
	{
		pFound->data = dataIn;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
void BST<TYPE> ::inorderTraverse(void(*process)(TYPE d)) const
{
	_inorderTraverse(root, process);
}

//*****************************************************************************************************

template <typename TYPE>
void BST<TYPE> ::_inorderTraverse(Node<TYPE> * pRoot, void(*process)(TYPE d)) const
{
	if (pRoot)
	{
		_inorderTraverse(pRoot->left, process);
		process(pRoot->data);
		_inorderTraverse(pRoot->right, process);
	}
}

//*****************************************************************************************************

template <typename TYPE>
int BST<TYPE> ::getCount() const
{
	return (_getCount(root));
}

//*****************************************************************************************************

template <typename TYPE>
int BST<TYPE> ::_getCount(Node<TYPE> * pRoot) const
{
	int count = 0;

	if (pRoot)
		count = 1 + _getCount(pRoot->left) + _getCount(pRoot->right);

	return count;
}

//*****************************************************************************************************

template <typename TYPE>
int BST<TYPE> ::getHt() const
{
	return (_getHt(root) - 1);
}

//*****************************************************************************************************

template <typename TYPE>
int BST<TYPE> ::_getHt(Node<TYPE> * pRoot) const
{
	int ht = 0;

	if (pRoot)
		ht = max(_getHt(pRoot->left), _getHt(pRoot->right)) + 1;

	return ht;
}

//*****************************************************************************************************

template <typename TYPE>
bool BST<TYPE> ::isEmpty() const
{
	bool success = false;

	if (root == nullptr)
		success = true;

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool BST<TYPE> ::isFull() const
{
	bool success = false;
	Node<TYPE> * pTemp = new (nothrow) Node<TYPE>;

	if (pTemp == nullptr)
		success = true;

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool BST<TYPE> ::isComplete() const
{
	return (_isComplete(root));
}

//*****************************************************************************************************

template <typename TYPE>
bool BST<TYPE> ::_isComplete(Node<TYPE> * pRoot) const
{
	bool complete = true;

	if (pRoot)
	{
		if ((_getHt(pRoot->left)) == (_getHt(pRoot->right)))
			complete = _isComplete(pRoot->left) && _isComplete(pRoot->right);
		else
			complete = false;
	}

	return complete;
}

//*****************************************************************************************************

template <typename TYPE>
bool BST<TYPE> ::isBalanced() const
{
	return (_isBalanced(root));
}

//*****************************************************************************************************

template <typename TYPE>
bool BST<TYPE> ::_isBalanced(Node<TYPE> * pRoot) const
{
	bool balanced = true;

	if (pRoot)
	{
		if (abs((_getHt(pRoot->left) - _getHt(pRoot->right))) <= 1)
			balanced = _isBalanced(pRoot->left) && _isBalanced(pRoot->right);
		else
			balanced = false;
	}

	return balanced;
}

//*****************************************************************************************************

#endif
