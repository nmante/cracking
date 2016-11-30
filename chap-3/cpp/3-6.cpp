#include <iostream>
#include "ds/stack.hpp"
#include <climits>
/*
 * Problem:
 * 	Write a program to sort a stack in ascending order. You should not make any
 * 	assumptions about how the stack is implemented. The only functions
 * 	that should be used to write this program: push | pop | peek | isEmpty.
 *
 */

namespace nii{

template <class T>
int findMinIndex(Stack<T> s){
	// Find the index of the minimum value in the stack
	if(s.empty()){
		return INT_MAX;
	}
	T min = INT_MAX;
	int index = 0;
	int minIndex = index;
	Stack<T> storage;
	while(!s.empty()){
		int pop = s.pop()->getData();
		storage.push(pop);
		if(pop < min){
			min = pop;
			minIndex = index;
		}
		index++;
	}
	while(!storage.empty()){
		s.push(storage.pop()->getData());
	}
	return minIndex;
}

template <class T>
Stack<T> sortStack(Stack<T> s){
	Stack<T> auxStack;
	Stack<T> result;
	while(!s.empty()){
		// Find min index
		int index = findMinIndex(s);

		// Pop values until min index, and store them in auxillary stack 
		for(int i = 0; i < index; i++){
			auxStack.push(s.pop()->getData());
		}

		// Move the minimum value to the result stack
		int data = s.pop()->getData();
		result.push(data);

		// put the non min values back to original stack 
		while(!auxStack.empty()){
			s.push(auxStack.pop()->getData());
		}
	}
	return result;
}
}

namespace careercup {

template <class T>
Stack<T> sortStack(Stack<T> s){
	Stack<T> result;
	while(!s.empty()){
		T tmp = s.pop()->getData();
		while(!result.empty() && result.peek() > tmp){
			s.push(result.pop()->getData());
		}
		result.push(tmp);
	}
	return result;

}
}

int main(){
	Stack<int> s;
	s.push(3);
	s.push(4);
	s.push(1);
	s.push(10);
	s.push(9);

	std::cout << "Unsorted stack: " << s << std::endl;
	Stack<int> result = nii::sortStack(s);
	std::cout << "Sorted stack: " << result << std::endl;

	Stack<int> s2;
	Stack<int> emp = nii::sortStack(s2);
	std::cout << "Empty: " << s2 << std::endl;
	s2.push(3);
	emp = nii::sortStack(s2);
	std::cout << "ONe item: " << emp << std::endl;

	s2.push(6);
	emp = nii::sortStack(s2);
	std::cout << "Two item: " << emp << std::endl;

	Stack<int> s3;
	s3.push(3);
	s3.push(5);
	s3.push(10);
	s3.push(2);

	std::cout << "Stack 3 unsorted: " << s3 << std::endl;
	Stack<int> res = careercup::sortStack(s3);
	std::cout << "Stack 3 sorted: " << res << std::endl;

	return 0;
}

/*
 * Solution:
 * 	- Don't assume anything about implementation, so we don't know if it's linked list
 * 	array, etc.
 * 	- We can only use stack functions such as push, pop
 *
 * 	To sort we need to look at every element, at best case O(n) algorithm
 *
 * 	Brute force - no extra data structure - O(n^2) worst case
 * 		- Find min value's index
 * 		- pop values from stack until that index and store them on aux stack
 * 		- pop min value and put on a second stack
 * 		- pop values from aux stack back to original stack 
 * 		- repeat until original stack empty
 *
 */
