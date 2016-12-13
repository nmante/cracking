#include <iostream>
#include "ds/bst/bstree.hpp"
#include <vector>

/*
 * Problem:
 * 	Given a sorted (increasing order) array, write an algorithm to 
 * 	create a binary tree with minimal height
 *
 * start 1235am
 */

void printVec(std::string first, std::vector<int> &v){
	std::cout << first << " ";
	for(auto e : v){
		std::cout << e << ", ";
	}
	std::cout << std::endl;
}

void treeFromArrayHelper(std::vector<int> &subArray, Node<int> *&root){
	if(subArray.size() == 0){
		return;
	}

	int index = subArray.size()/2;
	root = new Node<int>(subArray[index]);

	std::vector<int> left(&subArray[0], &subArray[index]);
	std::vector<int> right(&subArray[index+1], &subArray[subArray.size()]);
	treeFromArrayHelper(left, root->left); 
	treeFromArrayHelper(right, root->right);  
	
}


BSTree<int> treeFromArray(std::vector<int> &array){
	
	BSTree<int> bst;
	treeFromArrayHelper(array, bst.root);
	bst.prettyInOrderPrint(bst.getRoot());
	return bst;
}

int main(){
	std::vector<int> arr{1, 3, 10, 11, 50, 51, 52};
	treeFromArray(arr);
	return 0;
}

/*
 * Solution:
 * 	- Array is sorted
 * 	- To create minimal height tree, the amount of left children
 * 	should be roughly the same as the amount of right children
 * 	- We can recursively divide the array
 * 	- Each time we divide, the central element becomes a node
 * 	- The left side of the array becomes the left child
 * 	- The right side of the array becomes the right child 
 * 	- Stop when we have an array of one and return that value 
 *
 */
