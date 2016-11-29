#include <iostream>
#include <vector>
#include "ds/stack.hpp"
#include <cstdlib>
//#include <stack>
/*
 * Problem: 
 * 	In Towers of Hanoi you have 3 rods and N disks of different sizes which
 * 	can slide onto any tower. The puzzle starts with disks sorted in ascending
 * 	ordre of size from top to bottom (e.g. each disk sits on top of an even
 * 	larger one). 
 *
 * 	Constraints
 * 	(A) Only one disk can be moved at a time.
 * 	(B) A disk is slid off the top of one rod onto the next rod.
 * 	(C) A disk can only be placed on top of a larger disk.
 * 	Write program to solve the tower of Hanoi using Stacks.
 */

namespace solution1 {

template <class T>
class Hanoi {
	int mNumDisks;
	int mNumRods;

	// Each rod is a stack. We'll store references to the rods in a vector
	std::vector<Stack<T> * > mRods; 

public:
	Hanoi(int numDisks) : mNumDisks(numDisks) {
		mNumRods = 3;

		// Initialize the start rod with 'numDisks'
		for(int i = 0; i < mNumRods; i++){
			Stack<T> * s = new Stack<T>();
			if(i == 0){
				for(int i = numDisks; i > 0; i--){
					s->push(i);
				}
			}
			mRods.push_back(s);
		}
	} 
	void move(int fromRodIndex, int toRodIndex){
		// Move data from one rod to another
		Stack<T> *fRod = mRods[fromRodIndex];
		Stack<T> *tRod = mRods[toRodIndex];
			
		T data = fRod->peek();
		std::cout << "Pushing: '" << data << "' from stack: " << fromRodIndex+1 << " to stack: " << toRodIndex+1 << std::endl;
		tRod->push(data);
		fRod->pop();
	}

	void print(){
		for(int i = 0; i < mNumRods; i++){
			std::cout << *mRods[i] << std::endl;
		}
	}
	
	void solve(int numDisks, int fromRodIndex, int toRodIndex, int bufferRodIndex){
		// The recursive solution for solving the Hanoi game
		if(numDisks > 0){
			// Move the top N - 1 disks from the start rod to the intermediate rod
			solve(numDisks - 1, fromRodIndex, bufferRodIndex, toRodIndex); 

			// Move the Nth rod to destination rod
			move(fromRodIndex, toRodIndex);

			// Move the N - 1 disks from the intermediate rod to the destination rod
			solve(numDisks - 1, bufferRodIndex, toRodIndex, fromRodIndex); 
		}	
	}
};

void solution1Driver(int argc, char *argv[]){
	int numDisks = 4;
	if(argc == 2){
		numDisks = atoi(argv[1]);
	}
	Hanoi<int> *h = new Hanoi<int>(numDisks);
	std::cout << "============= Unsolved ==============" << std::endl;
	h->print();
	h->solve(numDisks, 0, 2, 1);
	std::cout << std::endl;
	std::cout << "============= Solved ==============" << std::endl;
	h->print();
}

}

namespace solution2 {

// This solution is from Career Cup's github

void towerOfHanoi(Stack<int> *a, Stack<int> *buff, Stack<int> *dest, int n){
	if(n == 0){
		return;
	}
	// Move the top N - 1 disks from the start rod  to the intermediate rod
	towerOfHanoi(a, dest, buff, n-1);

	// Move the bottom disk to the destination rod
	(*dest).push((*a).peek());
	(*a).pop();

	// Move the N - 1 disks from the intermediate rod to the destination rod rod
	towerOfHanoi(buff, a, dest, n-1);
}

void solution2Driver(){
	Stack<int> primary, buffer, destination;
	int n = 10;
	for(int i = n; i > 0; i--)
		primary.push(i);

	towerOfHanoi(&primary, &buffer, &destination, 10);
	std::cout << "Destination stack after solving game." << std::endl;
	while(!destination.empty()){
		std::cout<<destination.peek()<<" ";
		destination.pop();
	}

}

}

int main(int argc, char *argv[]){
	std::cout << " **** Solution 1 **** " << std::endl;
	solution1::solution1Driver(argc, argv);
	
	std::cout << " **** Solution 2 **** " << std::endl;
	solution2::solution2Driver();
	
	return 0;
}

