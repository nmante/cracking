#include <iostream>
#include <vector>


/*
 * Problem 9-1
 * You are given two sorted arrays, A and B, and A has a large enough buffer
 * at the end to hold B. Write a method to merge B into A in sorted order.
 *
 * 4 5 10 12 15 _ _ _ _ _
 * 1 2 3 9 11
 *
 * 1 5 10 12 15 
 * 4 2 3 9 11
 *
 */

typedef std::vector<int> List;

void mergeArrays(List & a, List & b){
	// Each array is sorted
	// Simply iterate through the length of the shorter array
	// choose which item to insert (smaller one)
	// keep track of two counters
	
	int aPointer = a.size() - b.size() - 1;
	int bPointer = b.size() - 1;
	int listPointer = a.size() - 1;

	// iterate through lists until we reach the end of one
	while(true){
		if(aPointer < 0 && bPointer >= 0){
			a[listPointer--] = b[bPointer--];
		}else if(bPointer < 0 && aPointer >= 0){
			a[listPointer--] = a[aPointer--];
		}else{
			if(a[aPointer] > b[bPointer]){
				a[listPointer--] = a[aPointer--];
			}else{
				a[listPointer--] = b[bPointer--];
			}
		}
		
		if(aPointer == -1 && bPointer == -1){
			break;
		}
	}

}
void printList(List &a){
	for(auto el : a){
		std::cout << el << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char *argv[]){
	List a({4, 5, 10, 12, 15, -1, -1, -1, -1, -1});
	List b({1, 2, 3, 9, 11});
	printList(a);
	printList(b);
	
	mergeArrays(a, b);

	printList(a);
	return 0;
}
