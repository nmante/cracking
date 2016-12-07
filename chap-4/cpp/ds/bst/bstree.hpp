#ifndef __BSTREE_HPP__
#define __BSTREE_HPP__ 

#include "node.hpp"

/*
 * Nii Mante
 * Binary Search Tree implementation
 */

template <class T>
class BSTree {
	Node<T> *root = NULL;
public:
	BSTree() {}
	BSTree(T data) {
		root = new Node<T>(data);
	}

	Node<T> *getRoot() { return root; } 

	// Search
	bool search(Node<T> *node, T data);
	
	// Insert
	void insert(Node<T> *node, T data);
	
	// Delete
	bool remove(T data);
	
	// In Order Print
	void inOrderPrint(Node<T> *node);
	
	// Pre Order Print
	void preOrderPrint(Node<T> *node);
	
	// Post Order Print
	void postOrderPrint(Node<T> *node);

	// Pretty Print
	void prettyInOrderPrint(Node<T> *node, int indent = 0);

	void prettyPreOrderPrint(Node<T> *node, int indent = 0);

	void prettyPostOrderPrint(Node<T> *node, int indent = 0);


};

#include "bstree.tpp"

#endif // __BINARYTREE_HPP__
