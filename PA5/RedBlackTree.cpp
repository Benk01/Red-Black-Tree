#include "RedBlackTree.h"

template <typename T>
RedBlackTree<T>::RedBlackTree() {
	root = nullptr;
}

template <typename T>
RedBlackNode<T>* RedBlackTree<T>::BSTinsert(RedBlackNode<T>* head, RedBlackNode<T>* newNode) {

	if (head == nullptr) {
		return newNode;
	}
	else if (newNode->data < head->data) {
		head->left = BSTinsert(head->left, newNode);
		head->left->parent = head;
	}
	else if (newNode->data > head->data) {
		head->right = BSTinsert(head->right, newNode);
		head->right->parent = head;
	}

	return head;
}

template <typename T>
void RedBlackTree<T>::insert(T newData) {
	RedBlackNode<T>* newNode = new RedBlackNode<T>(newData);
	RedBlackNode<T>* parent = nullptr;
	RedBlackNode<T>* grandparent = nullptr;
	setRoot(BSTinsert(getRoot(), newNode));
	int temp;

	while (getColor(newNode->parent) == RED && getColor(newNode) == RED && newNode != getRoot()) {
		parent = newNode->parent;
		grandparent = newNode->parent->parent;
		if (parent == grandparent->right) {
			if (getColor(grandparent->left) == RED) {
				parent->color = BLACK;
				grandparent->left->color = BLACK;
				grandparent->color = RED;
				newNode = grandparent;
			}
			else {
				if (newNode == parent->left) {
					rotateRight(parent);
					newNode = parent;
					parent = newNode->parent;
				}
				rotateLeft(grandparent);
				temp = parent->color;
				parent->color = grandparent->color;
				grandparent->color = temp;
				newNode = parent;
			
			}
	
		}
		else {
			if (getColor(grandparent->right) == RED) {
				parent->color = BLACK;
				grandparent->right->color = BLACK;
				grandparent->color = RED;
				newNode = grandparent;
			}
			else {
				if (newNode == parent->right) {
					rotateLeft(parent);
					newNode = parent;
					parent = newNode->parent;
				}
				rotateRight(grandparent);
				temp = parent->color;
				parent->color = grandparent->color;
				grandparent->color = temp;
				newNode = parent;
			}
		}
	}
	 getRoot()->color = BLACK;	
}

template <typename T>
void RedBlackTree<T>::rotateRight(RedBlackNode<T>* head) {
	RedBlackNode<T>* temp = head->left;
	head->left = temp->right;

	if (head->left != nullptr) {
		head->left->parent = head;
	}

	temp->parent = head->parent;

	if (head->parent == nullptr) {
		setRoot(temp);
	}
	else if (head->parent->left == head) {
		head->parent->left = temp;
	}
	else {
		head->parent->right = temp;
	}

	temp->right = head;
	head->parent = temp;
}

template <typename T>
void RedBlackTree<T>::rotateLeft(RedBlackNode<T>* head) {
	RedBlackNode<T>* temp = head->right;
	head->right = temp->left;

	if (head->left != nullptr) {
		head->left->parent = head;
	}

	temp->parent = head->parent;

	if (head->parent == nullptr) {
		setRoot(temp);
	}
	else if (head->parent->left == head) {
		head->parent->left = temp;
	}
	else {
		head->parent->right = temp;
	}

	temp->left = head;
	head->parent = temp;
}

template <typename T>
void RedBlackTree<T>::inOrder(RedBlackNode<T>* head) {
	if (head == nullptr)
		return;

	inOrder(head->left);
	cout << head->data << " " << getColor(head) << endl;
	inOrder(head->right);
}

template <typename T>
void RedBlackTree<T>::update(RedBlackNode<T>* head, int searchId) {
	if (head == nullptr)
		return;

	update(head->left, searchId);
	if (searchId == (head->data).getId()) {
		string answerString;
		int answerInt;
		cout << head->data << " has been found. Enter new information." << endl;
		cout << "Enter item name: ";
		cin >> answerString;
		head->data.setType(answerString);
		cout << "\nEnter number of items: ";
		cin >> answerInt;
		head->data.setNumItems(answerInt);
		cout << "\nEnter item ID: ";
		cin >> answerInt;
		head->data.setId(answerInt);
		cout << "\n Your item has been updated" << endl;
		return;
	}
	update(head->right, searchId);
}


template class RedBlackTree<InventoryRecord>;