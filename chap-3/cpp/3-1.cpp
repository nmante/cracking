#include <iostream>
#include "ds/stack.hpp"
/*
 * Start: 228pm
 * End: 
 *
 * Problem: Describe how you could use a single array to implement three stacks
 */
template <class T> 
class ArrayStack{

private:
	int numStacks;
	int *stackPositions;
	T *stackArray;
	int numItems;

public:
	ArrayStack(int n){ 
		numItems = n;
		numStacks = 3;
		stackPositions = new int[numStacks];
		stackArray = new T[n];
		for(int i = 0; i < numStacks; i++){
			stackPositions[i] = (i + 1)*n/3 - 1;
		}
		for(int i = 0; i < numItems; i++){
			stackArray[i] = -1;
		}
	}

	T pop(int stackIndex){
		int index = (stackIndex + 1);
		T result;
		if(stackPositions[stackIndex] < index*numItems/numStacks){
			
			
			stackArray[stackPositions[stackIndex]] = -1;
			result = stackArray[stackPositions[stackIndex]];
			// If we're not at the edge of the stack
			if(!(stackPositions[stackIndex] == index*numItems/numStacks - 1)){
				stackPositions[stackIndex]++;
			}else{
				std::cout << "Couldn't pop from stack number " << stackIndex + 1 << std::endl;;
				std::cout << "Returning -1" << std::endl;
				result = -1;
			}
		}
		return result;
	}

	void push(int stackIndex, T value){
		//int index = (stackIndex - 1) > 0 ? (stackIndex - 1) : 0;
		if(stackPositions[stackIndex] > stackIndex*numItems/numStacks - 1){
			stackArray[stackPositions[stackIndex]]= value;
			if(stackPositions[stackIndex] != stackIndex*numItems/numStacks){
				stackPositions[stackIndex]--;
			}else{
				std::cout << "Couldn't push " << value;
				std::cout << " on to stack number " << stackIndex + 1 << std::endl;
			}
		}
	}

	void printStack(){
		std::cout << "Stack" << std::endl;
		int index = 0;
		for(int i = 0; i < numItems; i++){
			std::cout << stackArray[i] << std::endl;
			if (i == (index + 1)*numItems/numStacks - 1){
				std::cout << std::endl;
				std::cout << " ------ " << std::endl;
				index++;
			}

		}
		std::cout << "End" << std::endl;
	}
};

int main(){
	ArrayStack<int> a(9);
	a.push(0, 3);
	a.push(0, 7);
	a.push(0, 10);

	a.push(1,10);
	a.push(1,2);
	a.push(1,4);

	a.push(2,9);
	a.push(2,20);
	a.push(2,50);
	a.printStack();

	a.pop(1);
	a.pop(1);
	a.pop(1);
	a.pop(1);
	a.pop(1);
	a.push(1, 20);
	a.push(1, 20);
	a.push(1, 20);
	a.push(1, 20);
	a.printStack();

	return 0;
}

/*
 *
 * Solution 1:
 *
 * 	Simply divide the array into three blocks
 * 	- The start of each stack is at i*n/3
 * 	- where n is the number of elements in the whole array
 * 	- and i is the stack index
 *
 * 	0*n/3, 1*n/3, 2*n/3
 *
 * 	- push (stack_index, value) 
 * 		- place a value into the 'back' of the stack segment 
 * 		- keep track of the top position as you push values 
 * 		(i.e. decrement the index from the next stacks beginning index - 1)
 * 		- (current_stack_index + 1)*n/3 - 1 is the start position when pushing
 * 		to any stack
 * 		- keep track of that position, decrement on push, call that position
 * 		stack_pointer
 *
 * 	- pop (stack_index) -> value
 * 		- Remove the value at the stack_pointer for the current stack_index
 * 		- decrement the stack pointer
 * 		- return the removed value
 *
 */

