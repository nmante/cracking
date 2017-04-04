#include <iostream>
#include <vector>

/*
 * Problem 9-7
 *
 * A circus designer needs to build a tower of people. The people stand on 
 * top of each others shoulders. Shorter and lighter people stand on the
 * heavier and taller people.
 * Each person must be BOTH shorter and lighter than the person below
 * him or her!
 *
 * Example 
 * 	Input: (ht, wt): (65, 100) (70, 150) (56, 90) (75, 190) (60, 95) (68, 110), (80, 140) 
 * 	Output1: (56, 90) (60,95) (65,100) (68,110) (70,150) (75,190)
 * 	Output2: (56, 90) (60,95) (65,100) (68,110) (80, 140)
 *
 *
 * Sort the list by height, then by weight
 * Find longest sequence that contains increasing heights and weights
 * 	- Build, store all increasing sequences
 * 	- As we build sequences, update the max length sequence 
 *
 *
 */

// Height weight tuple 
class HWTuple;

// Convenience type to store list of height weight tuples
typedef std::vector<HWTuple> HWList;

// Print a height weight tuple list
void printList(HWList &list);

// Merge Sort
void merge(HWList &list, int lo, int mid, int hi);
void mergeSortHelper(HWList &list, int lo, int hi);
void mergeSort(HWList &list);

// The solution
HWList buildTower(HWList &list);

// Convenience for building input tower
HWList makeList(std::vector<int> heights, std::vector<int> weights);

int main(){
	HWList list = makeList({65, 70, 56, 75, 60, 68, 80}, {100, 150, 90, 190, 95, 110, 140});
	std::cout << "Input tower: " << std::endl;
	printList(list);
	auto res = buildTower(list);
	std::cout << "result: " << std::endl;
	printList(res);
	return 0;
}

class HWTuple {
public:
	int height;
	int weight;
	HWTuple(int height, int weight) : height(height), weight(weight) {}
	bool operator < (const HWTuple &other){
		return (height < other.height && weight < other.weight) || 
			(height == other.height && weight < other.weight);
	}

};


// Merge Sort
void merge(HWList &list, int lo, int mid, int hi){
	// Create two temporary lists containing left and right halves 
	// of the main 'list'
	HWList tempLeft(list.begin() + lo, list.begin() + mid + 1);
	HWList tempRight(list.begin() + mid + 1, list.begin() + hi + 1);

	int i = 0, leftSize = tempLeft.size();
	int j = 0, rightSize = tempRight.size();
	int k = lo;
	
	// Insert the smaller person
	while(i < leftSize && j < rightSize){
		if(tempLeft[i] < tempRight[j]){
			list[k++] = tempLeft[i++];
		}else{
			list[k++] = tempRight[j++];
		}
	}	

	// Insert rest of left items
	while(i < leftSize){
		list[k++] = tempLeft[i++];
	}

	// Insert rest of right items
	while(j < rightSize){
		list[k++] = tempRight[j++];
	}
}

void mergeSortHelper(HWList &list, int lo, int hi){
	if(lo < hi){
		int mid = lo + (hi - lo)/2;
		mergeSortHelper(list, lo, mid); 
		mergeSortHelper(list, mid + 1, hi);
		merge(list, lo, mid, hi);
	}
}
void mergeSort(HWList &list){
	mergeSortHelper(list, 0, list.size() - 1);
}


HWList buildTower(HWList &list){
	// Sort list by height then weight
	mergeSort(list);
	HWList tower;

	std::vector<HWList> dp(list.size(), HWList({}));
	
	for(int i = 0; i < (int)list.size(); i++){
		for(int j = 0; j < i; j++){
			// add item to current sequence
			if(list[j] < list[i] && (dp[i].size() < dp[j].size() + 1)){
				dp[i] = dp[j];
			}

		}
		dp[i].push_back(list[i]);
		if(i > 0 && dp[i].size() > dp[i - 1].size()){
			tower = dp[i];
		}
	}
	return tower;
}


HWList makeList(std::vector<int> heights, std::vector<int> weights){
	if(heights.size() != weights.size()){
		std::cout << "Lists NOT same sizes" << std::endl;
		return {};
	}
	HWList list;
	for(int i = 0; i < (int)heights.size(); i++){
		list.push_back(HWTuple(heights[i], weights[i]));
	}
	return list;
}

void printList(HWList &list){
	for(auto el : list){
		std::cout << "(" << el.height<< ", " << el.weight<< ")";
	}
	std::cout << std::endl;
}


