#ifndef REDBLACKNODE_H

#define REDBLACKNODE_H
#define RED 0
#define BLACK 1

#include <iostream>
#include <string>
#include <stdio.h>
#include <stddef.h>


template <typename T>
class RedBlackNode {
public:
	RedBlackNode() {
		left = nullptr;
		right = nullptr;
		parent = nullptr;
		data = nullptr;
		color = RED;
	}
	RedBlackNode(T newData) {
		left = nullptr;
		right = nullptr;
		parent = nullptr;
		data = newData;
		color = RED;
	}
	~RedBlackNode();

	RedBlackNode* left;
	RedBlackNode* right;
	RedBlackNode* parent;
	T data;
	int color;

};

#endif