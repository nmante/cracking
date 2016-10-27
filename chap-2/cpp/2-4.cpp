#include <iostream>
#include "ll/linkedlist.hpp"
#include <math.h>

/*
 * Iterative Start time: 450pm
 * Iterative End time: 459pm 
 *
 * Iterative Start time: 505pm
 * Iterative End time: 520pm
 * Problem: You have two numbers represented by a linked list, where each node contains
 *	a single digit. The digits are stored in reverse order, such that the 1's digit
 *	is at the head of the list. Write a function that adds the two numbers and returns
 *	the sum as a linked list
 */

template <class T>
LinkedList<T> addLinkedListNumbers(LinkedList<T> &list1, LinkedList<T> &list2);

//template <class T>
//LinkedList<T> addLinkedListNumbersRecursive(Node<T> *node1, Node<T> *node2, int position);

int main(){
	LinkedList<int> ll(5);
	ll.append(2);
	std::cout << "List 1: " << ll << std::endl;

	LinkedList<int> ll2(4);
	ll2.append(5);
	std::cout << "List 2: " << ll2 << std::endl;

	LinkedList<int> llSum = addLinkedListNumbers(ll, ll2);
	std::cout << "Sum: " << llSum << std::endl;

	/*int position = 0;
	LinkedList<int> llSum2 = addLinkedListNumbersRecursive(ll.getHead(), ll2.getHead(), position); 
	std::cout << "Sum recursive: " << llSum2 << std::endl;
	*/
	
	return 0;
}

template <class T>
LinkedList<T> addLinkedListNumbers(LinkedList<T> &list1, LinkedList<T> &list2){
	T sum = 0;
	Node<T> *list1Tmp = list1.getHead();
	Node<T> *list2Tmp = list2.getHead();
	int position = 0;

	while(list1Tmp || list2Tmp){
		if(list1Tmp){
			sum += list1Tmp->data*pow(10,position);
			list1Tmp = list1Tmp->next;
		}
		if(list2Tmp){
			sum += list2Tmp->data*pow(10,position);
			list2Tmp = list2Tmp->next;
		}
		position += 1;
	}

	LinkedList<T> result(sum % 10);
	sum /= 10;
	do {
		T digit = sum % 10;
		result.append(digit);
		sum /= 10;

	}while(sum > 0);

	return result;
}
/*
template <class T>
T addLinkedListNumbersRecursive(Node<T> *node1, Node<T> *node2, int position){
	T sum = 0;

	// If both nodes are null, we're at the end of each list
	// Bottom out, and return 0 for this sum
	if(!node1 && !node2){
		return 0;
	}else{
		// Three cases: both lists have values
		// list1 has a value, and list2 is null
		// list2 has a value, and list1 is null

		if(node1 && node2){
			sum += node1->data*pow(10, position)
				+ node2->data*pow(10, position)
				+ addLinkedListNumbersRecursive(node1->next, node2->next, position+1);
		}else if(node1){
			Node<T> *n = 0;
			sum += node1->data*pow(10, position)
				+ addLinkedListNumbersRecursive(node1->next, n, position + 1); 
		}else if(node2){
			Node<T> *n = 0;
			sum += node2->data*pow(10, position)
				+ addLinkedListNumbersRecursive(n, node2->next, position + 1);
		}
	}

	return sum;
}
*/
/*
 * Solution:
 * 	3 -> 2 -> 1 -> 5 is the number 5123
 *
 * 	4 -> 5 -> 6 is the number 654
 *
 * 	Addition of these two is
 *
 * 		(3 * 1 + 2 * 10 + 1 * 100 + 5*1000) + (4 * 1 + 5 * 10 + 6 * 100)
 *
 * 	- In other words, as we move through the linked list, we multiply the data
 * 	member by 10^position
 *
 * 	- position starts at 0 at the head, increment as we traverse the list 
 *
 * 	- Traverse both linked lists in while loop
 * 	- Make sure at least one of them is not null
 * 	- Keep track of position in the lists 
 * 	- Add multiplication of 10^position and data member to total sum 
 */


