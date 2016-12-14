#include <iostream>
#include "ds/bst/bstree.hpp"

/*
 * Problem:
 * 	Design an algorithm and write code to find the first common ancestor of 
 * 	two nodes in a binary tree. Avoid storing additional nodes in a data structure.
 * 	NOTE: This is not necessarily a binary search tree.
 *
 * start: 1048 (slight break in between)
 * end: 1140
 */

bool search(Node<int> *node, int data){
	if(!node)
		return false;
	if(node->data == data)
		return true;

	return search(node->left, data) || search(node->right, data);
}

Node<int> *findCommonAncestor(Node<int> *root, int data1, int data2){
	if(!root){
		return nullptr;
	}
	bool case1 = search(root->left, data1) && search(root->right, data2);
	bool case2 = search(root->right, data1) && search(root->left, data2);
	bool case3 = search(root->right, data1) && search(root->right, data2);
	bool case4 = search(root->left, data1) && search(root->left, data2);
	if(case1 || case2)
		return root;
	else if(case3)
		return findCommonAncestor(root->right, data1, data2);
	else if(case4)
		return findCommonAncestor(root->left, data1, data2);
	
	return nullptr;

}

void test(BSTree<int> &bst, int data1, int data2){
	std::cout << "THE TREE" << std::endl;
	bst.prettyInOrderPrint(bst.getRoot());
	Node<int> *ca86 = findCommonAncestor(bst.root, data1, data2);
	std::cout << "Common ancestor of: " << data1 << ", and " << data2; 
	if(ca86){
		std::cout << " is " << ca86->data << std::endl;
	}else{
		std::cout << " NULL" << std::endl; 
	}	
}

int main(){
	Node<int> *root = new Node<int>(3);
	root->left = new Node<int>(10);
	root->right = new Node<int>(2);
	root->left->left = new Node<int>(1);
	root->left->right = new Node<int>(5);
	root->right->left = new Node<int>(6);
	root->right->right = new Node<int>(7);
	root->right->right->left = new Node<int>(8);

	BSTree<int> bst;
	bst.root = root;
	test(bst, 6, 8);
	test(bst, 1, 5);
	test(bst, 3, 2);
	test(bst, 1, 8);
	test(bst, 2, 7);

	return 0;
}

/*
 * Solution:
 * 	- A node is a common ancestor between two nodes (1 and 2), if the 
 * 	node 1 is in one sub tree, and node 2 is in the other
 *
 * 	- We can do this recursively
 * 	- Check if node 1 is left tree
 * 		- if it is check if node 2 is in right tree
 * 			- if node 2 isn't in right tree
 * 				- recurse down left tree
 * 			- if node 2 is in right tree
 * 				- you're done, return this NODE
 * 	- If node 1 isn't in left tree check if it's in right subtree
 * 		- if it is check if node 2 is in left tree
 * 			- if node 2 isn't in left tree 
 * 				- recurse down right tree
 * 			- if node 2 is in left tree
 * 				- you're done, return this node
 *
 * Implement search function
 * 	- does the 'check'
 *
 * Implement driver function
 * 	- does above logic
 *
 * This current complexity could blow up, for each node, your searching the children
 * N^2
 * 				
 */
