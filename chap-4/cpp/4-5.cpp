#include <iostream>
#include "ds/bst/bstree.hpp"

/*
 * Problem:
 * 	Write an algorithm to find the next node (e.g. in-order successor)
 * 	of a given node in a binary search tree where each node has a link
 * 	to it's parent.
 *
 * start: 947pm
 * end: 1020pm
 */

Node<int> *findLeftMostChild(Node<int> *node); 
Node<int> *findNextNode(Node<int> *root);
Node<int> *findAncestor(Node<int> *root);

int main(){
	BSTree<int> bst;
	bst.insert(bst.getRoot(), 4);
	bst.insert(bst.getRoot(), 2);
	bst.insert(bst.getRoot(), 6);
	bst.insert(bst.getRoot(), 1);
	bst.insert(bst.getRoot(), 3);
	bst.insert(bst.getRoot(), 5);

	Node<int> *iOS = findNextNode(bst.root);
	bst.prettyInOrderPrint(bst.getRoot());
	std::cout << "Next Node of: " << bst.root->data << ", is: " << iOS->data << std::endl;

	iOS = findNextNode(bst.root->left);
	std::cout << "Next node of: " << bst.root->left->data << ", is: " << iOS->data << std::endl;
	
	iOS = findNextNode(bst.root->left->right);
	std::cout << "Next node of: " << bst.root->left->right->data << ", is: " << iOS->data << std::endl;
	return 0;
}

Node<int> *findLeftMostChild(Node<int> *node){
	if(!node){
		return nullptr;
	}

	if(node->left)
		return findLeftMostChild(node->left);

	return node;

}
Node<int> *findAncestor(Node<int> *node){
	if(!node){
		return nullptr;
	}

	if(node->parent)
		return findAncestor(node->parent);

	return node;
}

Node<int> *findNextNode(Node<int> *root){
	if(!root){
		return nullptr;
	}

	if(root->right){
		return findLeftMostChild(root->right);
	}else if(root->parent){
		if(root->parent->left == root){
			// I'm the left child
			return root->parent;
		}else if(root->parent->right == root){
			return findAncestor(root->parent);
		}
	}

	return nullptr;
}

/*
 * Solution:
 * 	In a tree, the in order successor is the left most child
 * 	of the 'node's right child
 *
 * 					4
 * 			2				6
 * 		1		3		5	
 *
 * 	in order successor of that tree is 5
 *
 * 	- given a node
 * 	- check if it has a right child
 * 		- if it does, find left most node of right child
 * 		- if it doesn't return null
 */
