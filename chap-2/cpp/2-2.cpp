/*
 * Problem: Implement an algorithm to find the nth to last element of a singly linked list
 * October 24th, 2016
 *
 * Start time: 240pm
 * End Time: 258pm
 *
 * Recursive solution: 305pm
 * End time: 325pm 
 *
 * Advantages of iterative v recursion
 * 	Could run out of stack space with recursive solution
 */
#include <iostream>
#include "ll/linkedlist.hpp"

template <class T>
Node<T> *findNthToLast(LinkedList<T> &ll, int n);

template <class T>
Node<T> *findNthToLastRecursive(Node<T> *node, int n, int &i);

int main(int argc, char *argv[]){
	int n = 1;
	if(argc == 2){
		n = atoi(argv[1]);
	}

	LinkedList<int> ll(4);
	ll.append(5);
	ll.append(6);
	ll.append(7);
	
	Node<int> *result = findNthToLast(ll, n);
	if(result)
		std::cout << n << " to last node data: " << result->data << std::endl;
	else
		std::cout << "There is no: `" << n << "` to last element" << std::endl;

	int i = 0;
	result = findNthToLastRecursive(ll.getHead(), n, i);
	if(result)
		std::cout << n << " to last node data: " << result->data << std::endl;
	else
		std::cout << "There is no: `" << n << "` to last element" << std::endl;

	return 0;
}

template <class T>
Node<T> *findNthToLast(LinkedList<T> &ll, int n){
	Node<T> *resultNode = ll.getHead();
	Node<T> *fullLengthNode = ll.getHead();
	int index = 0;
	
	// Traverse list
	while(fullLengthNode){
		// increment resultNode counter until n == index
		// Once index does == n, then you can start moving the result node
		if(index == n){
			resultNode = resultNode->next;
		}else{
			index++;
		}

		fullLengthNode = fullLengthNode->next;

	}
	// If  
	if(n > index || n < index)
		return 0;

	return resultNode;
}

template <class T>
Node<T> *findNthToLastRecursive(Node<T> *node, int n, int &i){
	// Recursively shrink list
	// On each traversal, iterate through list
	// If number of traversals equals n, return that node
	// Otherwise shrink the list

	//int i = 0;
	Node<T> *result = node;
	if(node){

		result = findNthToLastRecursive(node->next, n, i);
		std::cout << "i: " << i << std::endl;
		if(++i == n){
			result = node;
		}
	}
	return result;
}

/*
 * Solution:
 * 	Goal is to find the nth to last node
 *
 * 	a -> b -> c -> d -> e -> NULL
 *
 * 	- We don't know length of LL before hand
 * 	Solution 1
 * 		- We could iterate the entire length to find how many nodes
 * 		- Then iterate that length - `n` - 1
 * 	Solution 2
 * 		- Or we could keep two separate pointers
 * 		- One pointer that goes all the way to the end
 * 		- Another pointer that goes to length - `n` - 1 index
 * 	
 *
 * 	
 */
