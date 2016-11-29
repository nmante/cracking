#include <iostream>
#include "ds/stack.hpp"
/*
 * Start: 628pm
 * Problem:
 * 	Implement a MyQueue class which implements a queue using two stacks
 */

template <class T>
class MyQueue {
	Stack<T> stack1;
	Stack<T> stack2;

public:
	void enqueue(T data){
		stack1.push(data);
	}
	T dequeue(){
		T data = peek();
		if(!stack2.empty())
			stack2.pop();
		return data;
	}
	T peek(){
		if(!stack2.empty()) 
			return stack2.peek();
		while(!stack1.empty()){
			stack2.push(stack1.peek());
			stack1.pop();
		}
		return stack2.peek();
	}

};

int main(){
	MyQueue<int> q;
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(3);
	q.enqueue(2);

	return 0;
}

/* 
 * Solution:
 * 	Queue is fifo data structure
 * 	stack is filo
 *
 * 	queue operations
 * 		- enqueue (push to end of stack)
 * 		- dequeue (pop from beginning of stack)
 *
 * 	How to do this with two stacks
 * 		q -> 1 2 3
 *
 *
 * 	- Use stack1 to just hold values when we enqueue/add values
 * 	- When we want to dequeue values, it becomes a little more complicated
 * 		- Let's say we pushed 3, 2, then 1 into a queue
 *
 * 		q -> 1 2 3
 *
 * 	- Our desired dequeue operation would result in a value of 3, since 3 is the 
 * 	first value inputted (queue's are FIFO)
 *
 * 	- Using stack operations our stack1 would have all these values
 * 		- s1 -> 1 2 3
 * 	- To get access to 3, we would have to remove all values, and push them
 *
 * 		- s1 -> pop -> 2 3 
 * 		- s2 -> push -> 1 
 * 		- s1 -> pop -> 3
 * 		- s2 -> push -> 2 1
 * 		- s1 -> pop -> 
 * 		- s2 -> push -> 3 2 1
 *
 * 	- Now s2 contains our values in reverse order, and we can get access to 3!
 * 	- Now to dequeue, 3 from our queue, we just call pop on stack 2
 *
 *
 *
 *
 *
 */

