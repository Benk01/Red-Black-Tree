#ifndef REDBLACKTREE_H

#define REDBLACKTREE_H
#include "RedBlackNode.h"
#include "InventoryRecord.h"

using namespace std;

template <typename T>
class RedBlackTree {

public:
	RedBlackTree();
	~RedBlackTree();
	bool isEmpty();
	void insert(T);
	RedBlackNode<T>* BSTinsert(RedBlackNode<T>* root, RedBlackNode<T>* newNode);
	void remove(T);
	void clear();
	void printInOrder();
	RedBlackNode<T>* getRoot() { return root; }
	void setRoot(RedBlackNode<T>* newRoot) { root = newRoot; }
	void rotateRight(RedBlackNode<T>* head);
	void rotateLeft(RedBlackNode<T>* head);
	void inOrder(RedBlackNode<T>* head);
	int getColor(RedBlackNode<T>* node)  {
		if (node == nullptr)
			return BLACK;
		return node->color;
	}

	void update(RedBlackNode<T>*, int);

private:
	RedBlackNode<T>* root;
};

#endif