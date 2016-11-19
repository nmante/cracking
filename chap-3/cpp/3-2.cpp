#include <iostream>
#include "ds/node.hpp"
#include "ds/stack.hpp"

/*
 * Start: 434pm
 * Problem: 
 * 	How would you design a stack which, in addition to push and pop, also
 * 	has a function 'min' which returns the minimum element? Push, pop and min
 * 	should operate in 0(1) time
 */

template <class T>
class MinNode {

public:
	T data;
	T min;
	MinNode<T> *next;

	MinNode(T data): data(data) {}

};

template <class T>
class MinStack {
	MinNode<T> *top;

public:
	MinStack(T data){ top = new MinNode<T>(data); }

	void push(T data){
		MinNode<T> *node = new MinNode<T>(data);
		node->next = top;
		node->min = node->data < top->data ? node->data : top->data;
		top = node;
	}

	T pop(){
		T data = top->data;
		MinNode<T> *tmp = top;
		top = top->next;
		tmp->next = NULL;
		delete tmp;
		return data;
	}
	T peek(){

		if(top){
			return top->data;
		}
		std::cout << "Stack Empty" << std::endl;

		return -1;
	}

	T min(){
		if(top)
			return top->min;

		std::cout << "Stack empty" << std::endl;
		return -1;
	}

};


int main(){
	MinStack<int> a(4);
	a.push(3);
	a.push(20);
	a.push(1);

	std::cout << "Min: " <<  a.min() << std::endl;
	a.push(0);

	std::cout << "Min: " <<  a.min() << std::endl;
	a.push(50);

	std::cout << "Min: " <<  a.min() << std::endl;

	a.pop();
	a.pop();

	std::cout << "Min: " <<  a.min() << std::endl;

	a.pop();

	std::cout << "Min: " <<  a.min() << std::endl;

	return 0;
}

/*
 * Solution:
 *
 * 	Normal stack, push pop are 0(1)
 * 	Need to make min 0(1)
 *
 * 	
 *
 * 	- Operations need to be O(1)
 * 	- That eliminates sorting of any kind (O(nlogn))
 * 	- Need to play with data structures of the stack
 * 	- Implement this as a linked list
 * 	- Each Node keeps track of the min after it
 *
 *
 * 	1(1)
 * 	min is 1
 *
 * 	2(1) 1(1)
 * 	min still 1
 *
 * 	10(1) 2(1) 1(1)
 * 	min still 1
 *
 *
 *
 * 	Another example
 *
 * 	4(4)
 *
 * 	10(4) 4(4)
 *
 * 	1(1) 10(4) 4(4)
 *
 * 	- Every time you insert, you compare the current node to the min of the next node
 * 	- Thus, each node should keep track of what it's min is
 *
 */

