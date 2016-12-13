#include <iostream>
#include "ds/bst/bstree.hpp"
#include <vector>

/*
 * Problem:
 * 	Given a binary search tree, design an algorithm which creates a linked
 * 	list of all of the nodes at each depth( e.g., if you have a tree with
 * 	depth D, you'll have D linked lists).	
 *
 * start: 135am
 * end: 152am
 *
 */

void createLists(std::vector<std::vector<int> > &listOfLists, Node<int> *&root, int depth = 1){
	if(!root){
		return;
	}

	if(listOfLists.size() < (unsigned int)depth){
		listOfLists.push_back(std::vector<int>());
	}

	listOfLists[depth - 1].push_back(root->data);

	createLists(listOfLists, root->left, depth + 1);
	createLists(listOfLists, root->right, depth + 1);
}

void printListOfLists(std::vector<std::vector<int> > &v){
	for (auto vec : v){
		for(auto num : vec){
			std::cout << num << " -> ";
		}
		std::cout << "NULL" << std::endl;
	}
}

int main(){
	std::vector<std::vector<int> > v;
	BSTree<int> bst;
	bst.insert(bst.getRoot(), 10);
	bst.insert(bst.getRoot(), 4);
	bst.insert(bst.getRoot(), 14);
	//bst.insert(bst.getRoot(), 6);
	bst.insert(bst.getRoot(), 2);
	bst.insert(bst.getRoot(), 11);
	bst.insert(bst.getRoot(), 15);

	createLists(v, bst.root); 
	printListOfLists(v);
	return 0;
}

/*
 * Solution:
 * 	- While we go through the tree, we need to keep track of our current
 * 	depth/level in the tree
 * 	- When we reach a depth, we push the current node/leaf to the linked list 
 * 	for that depth
 * 	- We can keep a reference to a container of linked lists
 * 		- create one if it doesn't exist for that index/depth
 *
 */



