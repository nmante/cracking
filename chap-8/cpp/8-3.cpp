#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

/*
 * Problem 8-3
 * Write a method that returns all subsets of a set
 */

/*
 * - Given a set
 * 	[0, 1, 2]
 *
 * - keep track of length
 * - keep track of start index
 * - every successful length subset should be added to global set
 *
 * - All subsets would be
 *   	[0, 1, 2]
 * 	[0]
 * 	[0, 1]
 * 	[0, 2]
 * 	[1]
 * 	[1, 2] 
 * 	[2]
 *
 * 	[0, 1, 2, 3]
 * 	[0, 1]
 * 	[0, 2]
 * 	[0, 3]
 * 	[0, 1, 2]
 * 	[0, 1, 3]
 *
 *
 * - we'll assume order doesn't matter
 * - so we need to do the combinations
 * - the process was
 * - take 
 *
 *
 */

typedef std::vector<std::vector<int> > SetList; 
typedef std::vector<int> Subset;

void printVec(std::vector<int> &list){
	int size = (int)list.size();
	std::cout << "{";
	for(int i = 0; i < size; i++){
		std::cout << list[i];
		if(i != size - 1){
			std::cout << ", ";
		}	
	}
	std::cout << "}" << std::endl;
}

/*
 * temp = 0
 * 010
 * &
 * 001
 * 0
 * temp = temp << 1
 * 010
 * & 
 * 010
 *
 * 
 */

SetList powerSet(std::vector<int> list){
	SetList setList;
	
	// The power set size is how many possible subsets there are
	int setSize = list.size();
	int powerSetSize = std::pow(2, setSize);
	
	// For each possible subset, generate a binary value
	// The binary value symbolizes what integer should be in the
	// sequence	
	for(int i = 0; i < powerSetSize; i++){
		// generate bit sequence
		std::cout << "{ ";
		std::vector<int> subset;
		for(int j = 0; j < setSize; j++){
			if(i & (1 << j)){
				subset.push_back(list[j]);
				std::cout << list[j] << " ";
			}	
		}
		std::cout << "}" << std::endl;
		setList.push_back(subset);

	}
	return setList;
}

Subset cloneSet(Subset list){
	Subset newSet;
	for(auto & el : list){
		newSet.push_back(el);
	}
	return newSet;
}

SetList allSubsets(Subset list, int currIndex){
	// base case
	SetList setList;
	if(currIndex == (int)list.size()){
		setList.push_back({});
		return setList; 
	}

	// for each set, in subsets
	// clone it, add item at 'currIndex' from 'list' to it 
	// add clone to subsets	
	setList = allSubsets(list, currIndex + 1);
	int item = list[currIndex];
	SetList additionalSets = setList;
	for(auto & set : setList){
		Subset newSet = cloneSet(set);
		newSet.push_back(item);
		additionalSets.push_back(newSet);
	}

	return additionalSets;
}

void testAllSubsets(Subset list){
	SetList subsets = allSubsets(list, 0);
	for(auto l : subsets){
		printVec(l);
	}
}
int main(){
	//powerSet({0,1,2});
	testAllSubsets({0, 1, 2});
	
	return 0;
}
