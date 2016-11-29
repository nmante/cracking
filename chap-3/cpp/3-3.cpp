#include <iostream>
#include "ds/stack.hpp"

/*
 * Problem: 
 * 	Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
 * 	Therefore, in real life, we would likely start a new stack when the previous stack 
 * 	exceeds some threshold. Implement a data structure SetOfStacks that mimics this.
 * 	SetOfStacks should be composed of several stacks and should create a new stack
 * 	once the previous one exceeds capacity. SetOfStacks.push() and .pop() should behave
 * 	identically to a single stack (e.g. pop() should return the same values as it would
 * 	if there were just a single stack).
 *
 * Start Time: 531pm
 */

template <class T>
class StackNode{
public:
	Stack<T> *stack;
public:
	StackNode<T> *next = NULL;
	StackNode(T data){ this->stack = new Stack<T>(data); }
};

template <class T>
class SetOfStacks{
public:
	int capacity;
	int currStackIndex = 0;
	int pushed = 0;
	StackNode<T> *currStackNode;
	SetOfStacks(T data, int capacity){ 
		this->capacity = capacity;
		currStackNode = new StackNode<T>(data);
		pushed = 1;
	}

	void push(T data){
		if(pushed == capacity){
			StackNode<T> *newStackNode = new StackNode<T>(data);
			newStackNode->next = currStackNode; 
			currStackNode = newStackNode;
			pushed = 1;
			currStackIndex++;
		}else{
			currStackNode->stack->push(data);
			pushed++;
		}
	}

	T pop(){
		if(pushed > 1){
			pushed--;
			return currStackNode->stack->pop()->getData();
		}
		if(pushed == 1){
			if(currStackNode->next){
				StackNode<T> *tmp = currStackNode;
				T data = tmp->stack->pop()->getData();
				currStackNode = currStackNode->next;
				tmp->next = NULL;
				delete tmp;
				pushed = capacity;
				currStackIndex--;
				return data;
			}else{
				pushed = 0;
				return currStackNode->stack->pop()->getData();
			}
			
		}
		
		return -1;
		
	}
	T popAt(int index){
		// For first stack, just do normal pop
		if(index == currStackIndex){
			return pop();
		}

		// For any other stack, you need to unstack all items, 
		// until you reach the desired stack
		// then pop at that stack
		// then restack the items
		
		SetOfStacks<T> newSetStack(-1, this->capacity);
		newSetStack.pop();
		int itemsPopped = 0;
		T returnData;

		while(true){
			if(currStackIndex == index){
				returnData = pop();	
				break;
			}else{
				T data = pop();
				newSetStack.push(data);
			}
			itemsPopped++;
		}

		while(itemsPopped > 0){
			T data = newSetStack.pop();
			push(data);
			itemsPopped--;
		}
		
		return returnData;
	}

	void print(){
		StackNode<T> *tmp = currStackNode;
		int counter = 1;
		std::cout << "--------- BEGIN SET --------" << std::endl;
		while (tmp) {
			std::cout << "STACK " << counter++ << std::endl; 
			std::cout << *(tmp->stack) << std::endl;
			tmp = tmp->next;
		}
		std::cout << "---------- END SET ---------" << std::endl;

	}



};


int main(){
	SetOfStacks<int> a(4, 4);
	a.push(4);
	a.push(5);
	a.push(6);
	a.push(3);
	a.push(20);
	a.push(23);
	a.push(245);
	a.print();

	a.popAt(0);
	a.print();



	return 0;
}

/*
 * Solution:
 *
 * 	Example - Capacity 4
 *
 * 	Push 3, 4, 5, 6, 7
 *
 * 	
 * 	6 5 4 3
 *
 * 	7
 *
 * 	Now push 10, 11
 *
 * 	6 5 4 3
 * 	11 10 7 
 *
 * 	Now pop 4 times
 *
 * 	We must keep track of our stacks
 * 	When we pop using the setofstack.pop these checks need to happen
 * 		- is curr stack empty
 * 			- if it is, remove it from set
 * 		- otherwise return the value from the pop operation
 *
 * 	When we push using setofstack.push these checks should happen
 * 		- is curr stack at capacity
 * 			- if it is, make a new stack
 * 			- put new value in new stack
 * 			- update what our current stack is
 *
 * 		- otherwise do normal push operation for current stack
 *
 * 	Essentially, create a new Node type, called StackNode
 * 		- it holds a next pointer to another stacknode
 * 		- it has it's own push pop operations as described above
 *
 *
 */

