#include <iostream>
#include <vector>

/*
 * Problem 9-5
 */

int findIndex(std::string word, std::vector<std::string> &arr, int lo, int hi){
	// This is a modified binary search, since some strings maybe empty
	while(lo <= hi){
		// If there are "" at the end of the list, no need to search
		// Shrink the list until the last element is an actual word
		while(lo <= hi && arr[hi] == ""){
			--hi;
		}
		// Exit if the entire list was made of ""
		if(hi < lo){
			return -1;
		}
		
		// Find the midpoint and move it if the element is an empty string
		int mid = (lo + hi)/2;
		while(arr[mid] == ""){
			++mid;
		}

		// Do normal binary search now
		if(arr[mid] == word){
			return mid;
		}else if(word < arr[mid]){
			hi = mid - 1;
		}else{
			lo = mid + 1;
		}
	}
	return -1;
}


int main(){
	std::vector<std::string> arr({"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""});
	int ind = findIndex("ball", arr, 0, arr.size() - 1);
	std::cout << "index: " << ind << std::endl;
	return 0;
}
