#include <iostream>
#include "ll/linkedlist.hpp"

/*
 * Problem: Implement an algorithm to delete a node in the middle of a singly linked list,
 * given access to only that node.
 *
 * Start time: 256pm
 * End time: 313pm
 *
 */

template <class T>
void deleteNodeInMiddle(Node<T> *node);

template <class T>
void deleteNodeWithLeak(Node<T> *node);

int main(){

	LinkedList<int> ll(1);
	ll.append(2);
	ll.append(3);
	ll.append(4);
	ll.append(5);

	deleteNodeInMiddle(ll.getHead()->next->next);

	deleteNodeWithLeak(ll.getHead()->next);
	std::cout << ll << std::endl;
	return 0;
}

template <class T>
void deleteNodeInMiddle(Node<T> *node){
	if(node == 0 || node->next == 0){
		return;
	}

	// No memory leak, but requires traversal
	Node<T> *tmp = node;
	while(tmp){
		if(tmp->next){
			tmp->data = tmp->next->data;
			if(!tmp->next->next){
				Node<T> *toDelete = tmp->next;
				tmp->next = 0;
				delete toDelete; 
			}
		}
		tmp = tmp->next;
	}

}

template <class T>
void deleteNodeWithLeak(Node<T> *node){
	// Memory leak
	// This method is simpler, but you'll have an extra node
	// For example, if you have a list a -> b -> c -> d -> e -> NULL 
	// and you delete c with this method, your list will look like this
	//
	// a -> b -> d -> e -> NULL
	// 	     ^
	// 	     |
	// 	     c
	// Of course the head of your list is still 'a', and 'c' is not technically apart 
	// of the list, but now you can't get a reference to 'c' any more
	//
	// In garbage collected languages (e.g. Java) this is fine because even 
	// after deleting the list, the copy of 'c' will be eventually deleted
	// However, in c++ we need to take care of leaks. That's why I would choose the 
	// other method 'deleteNodeInMiddle'
	if(node == 0 || node->next == 0){
		return;
	}
	
	
	Node<T> *next = node->next;
	node->data = next->data;
	node->next = next->next;
}
/*
 * Solution:
 * 	
 * 	a -> b -> c -> d -> NULL
 *
 * 	Say we wanted to delete 'c', and we've only been given a pointer to
 * 	'c'
 *
 * 	Our standard deletion method won't work, we can't simply point the previous
 * 	node of 'c' to the next node of 'c' and delete 'c'
 *
 * 	Proposed solution:
 * 		- shift everything after 'c' over to the left
 * 		- simply overwrite data member of node at index "i"  with the data 
 * 		of node at index "i+1"
 *
 * 		- once we have done that for all remaining nodes, delete the end of the list
 *	
 *	Example:
 *
 * 	a -> b -> c -> d -> e -> NULL
 * 	delete c
 *
 *	c -> node
 *
 *	node->data = node->next->data // if node->next exists
 *	// repeat that step
 *
 *	if node->next is null then we're at the end of the list
 *
 *	that means we delete the node
 *
 *
 */
