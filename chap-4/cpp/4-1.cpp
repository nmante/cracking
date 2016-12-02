#include <iostream>
#include "ds/bst/bstree.hpp"
#include <cmath>
#include <algorithm>

/*
 * Problem: 
 * 	Implement a function to check if a tree is balanced. For the purposes of
 * 	this question, a balanced tree is defined to be a tree such that no two
 * 	leaf nodes differ in distance from the root by more than one.
 *
 * 	start: 603pm
 * 	end: 617pm
 */

template <class T>
int maxDepth(Node<T> *root){
	if(!root){
		return 0;
	}
	std::cout << "data: " << root->data << std::endl;
	return 1 + std::max(maxDepth(root->left), maxDepth(root->right)); //( (left > right) ? left : right ); 

}

template <class T>
int minDepth(Node<T> *root){
	if(!root){
		return 0;
	}
	return 1 + std::min(minDepth(root->left), minDepth(root->right)); //( (left > right) ? left : right ); 
}

template <class T>
bool isBalanced(Node<T> *root){
	if(!root){
		return true;
	}
	return (maxDepth(root) - minDepth(root) <= 1); 
}

int main(){
	BSTree<int> bst;
	bst.insert(bst.getRoot(), 4);
	bst.insert(bst.getRoot(), 6);
	bst.insert(bst.getRoot(), 2);
	bst.insert(bst.getRoot(), 1);
	bst.insert(bst.getRoot(), 10);
	bst.insert(bst.getRoot(), 11);
	//bst.insert(bst.getRoot(), 3);
	bst.prettyInOrderPrint(bst.getRoot());
	std::cout << "maxDepth: " << maxDepth(bst.getRoot()) << std::endl;
	std::cout << "minDepth: " << minDepth(bst.getRoot()) << std::endl;
	std::string balanced = isBalanced(bst.getRoot()) ? "True" : "False";
	std::cout << "Balanced: " << balanced << std::endl; 
	return 0;
}


/*
 * Solution:
 * 	- Essentially we need to check the depth/num levels of one side of the tree
 * 	- and check the depth/num levels of the other side of the tree
 *
 * 	- create a function, that takes maxdepth of a branch
 * 	- create a function, isBalanced that checks if diff between maxdepth-left and
 * 	maxdepth-right is more than one
 *
 */

