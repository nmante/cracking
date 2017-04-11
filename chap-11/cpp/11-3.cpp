#include <iostream>
#include <fstream>
#include <stdint.h>
#include <string>
#include <vector>

/*
 * Problem 11-3
 * Given an input file with four billion integers, provide an algo
 * to generate an integer which is not contained in the file. 
 * Assume you have 1 GB of memory.
 *
 */

/*
 * Solution1
 * 	1 integer, 32 bit, 4 bytes
 * 	1 GB, 1000MB, 1000000KB, 1000000000B, 250,000,000 integers in memory at a time
 * 	Means to look at all numbers, we would have to repeat process 16 times
 *
 * 	Range of integers is -(2^31 - 1) .. 2^31 - 1
 *
 *	- Will have to look at every number in list
 *	- Can Sort the numbers
 *	- Then linearly look through them
 *	- If there is a gap between two sequential numbers, return a number in between
 *	the two
 *		- when looking at number at index i
 *		- if abs(num[i] - num[i + 1]) > 1
 *			- return num[i] + 1 if num[i] smaller, otherwise num[i+1] + 1
 *
 * 	- How do we deal with the memory constraint?
 * 	- You don't need all of the numbers in memory! 
 * 		- you can keep k numbers in memory
 * 		- keep track of how many numbers processed so far
 * 		- any time you pick from the file, remove that line
 * 		- any time you need to take a number from our in memory list,
 * 		remove it, but add it to the end of the file 
 *
 * 	FILE
 * 		1
 * 		5
 * 		2
 * 		4
 * 		100	
 *
 * 	inmem
 * 		1
 *
 * 		1, 5 (pick 5 from file)
 *
 * 		1, 2 (pick 2 from file, put 5 at end)
 *
 * 		1, 2 (pick 4 from file, put 4 at end)
 *
 * 		1, 2 (pick 100 from file, put 100 at end)
 *
 * 	- The result should just be the minimum, minus 1 (aka 0)!
 * 	- Special Case
 * 		- INT_MIN
 * 		- Pluck INT_MIN from heap, if difference between that 
 * 		and next min heap > 1, return INT_MIN + 1
 * 		- repeat until you find a diff > 1
 *
 *
 * Solution2
 * 	- 1 GB of memory to store numbers
 * 	- 1 GB is 1 billion bytes, 1 byte is 8 bits
 * 	- 8 billion bits total
 * 	- The range of INT is -2^31 + 1 <-> 2^31 - 1
 * 	- Thus, there are just over 4 billion integers possible 
 * 	- Can map all integers to a bit vector (64 bit integer 
 * 	- offset by int_max (i.e. INT_MIN should be zero, INT_MAX should be 
 * 	unsigned_int_max) 
 * 	
 */

// Open a file
// initialize 8billion bit array
// Iterate line by line through file
	// For each line
	// convert to a integer
	// turn on the bit corresponding to integer
// Iterate through bit vector
	// first 0 is missing integer
	// return value


void findInteger(std::string &filename){
	std::ifstream integerFile(filename);
	std::string line;
	std::string::size_type sz;
	std::vector<uint8_t> bitVector(0xFFFFFFFF/8, 0);
	
	if(!integerFile.is_open()){
		return;
	}

	while( std::getline(integerFile, line) ){
		uint32_t val = std::stoul(line, &sz);
		std::cout << "Val: " << val << std::endl;
		bitVector[val / 8] |= 1 << (val % 8); 
	}

	integerFile.close();
	for(unsigned i = 0; i < bitVector.size(); i++){
		for(unsigned j = 0; j < 8; j++){
			if((bitVector[i] & (1 << j)) == 0){
				std::cout << "Found integer: " << (unsigned)i * 8 + j << std::endl;
				return;
			}
		}
	}

	std::cout << "Couldn't find integer" << std::endl;
	return;
}

int main(int argc, char *argv[]){
	std::string filename = "ints.txt";
	if(argc > 1){
		filename = argv[1];
	}
	findInteger(filename);
	return 0;
}

