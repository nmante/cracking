#include <iostream>
#include <vector>

/*
 * Problem 9-3
 * Given a sorted array of n integers that has been rotated an unknown
 * number of times, give an O(log n) algorithm that finds an element in the
 * array. You may assume that the array was originally sorted in 
 * increasing order.
 */

// Binary search on rotated array
int findIndex(int val, std::vector<int> arr){
	int lo = 0, hi = arr.size() - 1;

	while(lo <= hi){
		int mid = (hi + lo)/2;
		if(arr[mid] == val){
			// we found the value
			return mid;
		}else if(arr[lo] <= arr[mid]){
			// is the left half sorted
			if(val > arr[mid]){
				lo = mid + 1;
			}else if(val >= arr[lo]){
				hi = mid - 1;
			}else{
				lo = mid + 1;
			}
		}else if(val < arr[mid]){
			hi = mid - 1;
		}else if(val <= arr[hi]){
			lo = mid + 1;
		}else{
			hi = mid - 1;
		}
		
	}
	return -1;
}


int main(int argc, char *argv[]){
	int ind = findIndex(5, {15, 16, 19, 20, 21, 22, 25, 1, 3, 4, 5});
	
	std::cout << "Index: " << ind << std::endl;
	int ind2 = findIndex(16, {15, 16, 19, 1, 3, 4, 5});
	std::cout << "Index: " << ind2 << std::endl;
	return 0;
}
