#include <iostream>
#include <stdint.h>
#include <vector>
#include <cmath>

/*
 * Problem 11-4
 * You have an array with all the numbers from 1 to N, where N
 * is at most 32000. The array may have duplicate entries and you 
 * do not know what N is. With only 4KB of memory available, how
 * would you print all duplicate elements in the array.
 *
 * 00000010 01100010
 * 
 */




void printDuplicates(std::vector<uint32_t> arr){
	// Can have a bit vector
	// 4KB of memory corresponds to 32000 bits
	// Iterate through array, set bit for current array value
	// if a bit is already set, just print that value
	std::vector<uint8_t> bitVector(4000, 0);
	for(int i = 0; i < (int)arr.size(); i++){
		int val = arr[i];
		if(bitVector[val / 8] & (1 << (val % 8))){
			std::cout << arr[i] << std::endl;
		}
		
		bitVector[val / 8] |= 1 << (val % 8);
	}
}

std::vector<uint32_t> randomVector(int N, int len){
	std::vector<uint32_t> result;
	for(int i = 0; i < len; i++){
		uint32_t val = std::rand() % N;
		result.push_back(val);
	}	
	return result;
}

void printVector(std::vector<uint32_t> &vec){
	std::cout << "Input Vector { ";
	for(auto &val : vec){
		std::cout << val << " ";
	}	
	std::cout << "}" << std::endl;
}

int main(int argc, char *argv[]){
	std::srand(std::time(NULL));
	uint32_t N = std::rand() % 32000 + 1;
	std::cout << "N: " << N << std::endl;
	int len = std::rand() % 1000 + 1;
	std::cout << "Length: " << len << std::endl;
	auto randVector = randomVector(N, len); 
	printVector(randVector);
	std::cout << "========== DUPLICATES ===========" << std::endl;
	printDuplicates(randVector);
	return 0;
}
