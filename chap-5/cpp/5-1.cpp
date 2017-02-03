#include <iostream>
#include <bitset>


/*
 * Start: 249pm
 * End: 306pm
 * 
 * Problem: You are given two 32-bit numbers, N and M, and two bit positions, i and j.
 * 	    Write a method to set all bits between i and j in N equal to M (e.g., M
 * 	    becomes a substring of N located at i and ending at j). 
 *
 * Solution:
 *
 * 	- Example 
 * 		input N = 10000000000, M = 10101, i = 2, j = 6
 * 		output: N = 10001010100
 *
 * 		10000000000
 * 		00001010100
 * 		-----------
 * 		10001010100
 *
 * 	- Example 2
 *
 *
 *
 * 		input N = 10001001000, M = 10101, i = 2, j = 6
 * 		output: N = 10001010100
 *
 * 		10001001000
 * 		00001010100
 * 		-----------
 * 		10001010100
 */

int mergeMandN(int n, int m, int i, int j){
	if(n < m){
		std::cout << "M must be smaller than N" << std::endl;
		return -1;
	}
	if(j < i){
		std::cout << "j must be larger than i" << std::endl;
		return -1;
	}
	// First we need to clear bits in N from interval i to j
	// & N with a number that has zeroes from i to j, and 1's everywhere
	// else
	
	int mask = ~0; // All 1's
	
	// first make everything after j'th 1, equal zero
	mask -= ((1 << j) - 1);

	// now make everything after i'th 0, equal 1
	mask += ((1 << i) - 1);

	std::cout << "mask: " << std::bitset<16>(mask) << std::endl;
	
	// Clear the j'th through i'th bits in N
	int tmpN = n & mask;

	// Set j'th through i'th bits in N to M
	int result = tmpN | (m << i); 

	return result;
}

void testScenarios(int n, int m, int i, int j){
	std::cout << "========" << std::endl;
	std::cout << "n is: " << std::bitset<16>(n) << ", m is: " << std::bitset<16>(m) << std::endl;
	std::cout << "i is: " << i << ", j is: " << j << std::endl;
	int result = mergeMandN(n, m, i, j);
	std::cout << "result is: " << std::bitset<16>(result) << std::endl;
	std::cout << "========" << std::endl;

}

int main(){
	testScenarios(0b10000000000, 0b00000010101, 2, 6);
	testScenarios(0b10001001000, 0b00000010101, 2, 6);


	return 0;
}

