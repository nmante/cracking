#include <iostream>
#include "ds/bst/bstree.hpp"
#include <vector>
#include <map>

/*
 * Problem:
 * 	You are given a binary tree in which each node contains a value.
 * 	Design an algorithm to print all paths which sum up to that value.
 * 	Note that it can be any path in the tree - it does not have to start 
 * 	at the root.
 *
 * start - 551pm
 */

std::map<int, std::vector<std::vector<int> > > allPathsMap;
std::vector<std::vector<int> > allPathsList;
std::vector<int> allValuesList;
void printPathsHelper(Node<int> *node, std::vector<int> currentPathList){

	if(node == 0){
		return;
	}
	
	allValuesList.push_back(node->data);
	// Path sum until this point
	std::vector<int> newPath;
	if (currentPathList.size() != 0){
		newPath = currentPathList;
		newPath.push_back(node->data);
	}else{
		newPath = {node->data}; // std::vector<int>(node->data);
	}
	if(newPath.size() > 1){
		allPathsList.push_back(newPath);
	}
	
	printPathsHelper(node->left, newPath); 
	printPathsHelper(node->right, newPath);

}

void printPaths(Node<int> *root){
	//Node<int> *root = bst.getRoot();
	
	// Move through each node
	Node<int> *tmp = root;
	printPathsHelper(tmp, {});

	for(auto list : allPathsList){
		int sum = 0;
		for(auto data: list){
			sum += data;
		}
		allPathsMap[sum].push_back(list); 
	}

	for(auto value : allValuesList){
		if (allPathsMap.count(value) > 0) {
			for(auto list : allPathsMap[value]){
				std::cout << "Value: " << value;
				std::cout << ", Path: [ ";
				for(auto nodeValue : list){
					std::cout << nodeValue << " -> ";
				}
				std::cout << "END" << std::endl;
			}

		}
	}

}


int main(){
	Node<int> *root = new Node<int>(5);
	root->left = new Node<int>(10);
	root->left->left = new Node<int>(1);
	root->left->right = new Node<int>(3);

	root->right = new Node<int>(0);
	root->right->left = new Node<int>(16);
	root->right->right = new Node<int>(18);

	printPaths(root);

	return 0;
}

/*
 * Solution
 *
 * 	- Tree is not bidirectional
 * 	- are values in tree distinct?
 *
 * 	- As we move through the tree, keep track of the nodes we're
 * 	currently visiting
 * 	- if those nodes add up to the value, store that path 
 *
 * 	- do this for all nodes in tree
 * 	- cannot include the node in the path
 *
 * 	- store list of values, O(n), maybe sort O(n log n)
 * 		[5, 10, 0, 1, 3, 16, 18]
 * 	- for each value in list
 * 		- traverse tree and keep track of currentPathSum
 * 			- if currentPathSum + currentNode < value 
 * 				- update sum
 * 				- add node value to currentPathList
 * 			- if currentPathSum + currentNode == value
 * 				- done summing
 * 				- add node value to currentPathList
 * 				- add currentPathList to allLists for that value
 * 			- otherwise
 * 				- break traversal
 *
 * 					5
 * 			10				0
 * 		1		3		16		18
 *
 * Solution 2
 * 	- traverse tree, each time you encounter a valid node, create a new path that has all the previous nodes too (aka, a copy of the old list from the previous call)
 * 	- store path in path list
 * 	- can do this recursively
 * 	- while traversing, store node value in a global list
 * 	- now that you have all the node values, and all the paths
 * 	  simply iterate through the paths and values, and create a map of <value> : <paths> 
 */

