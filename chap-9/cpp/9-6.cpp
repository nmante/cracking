#include <iostream>
#include <vector>

/*
 * Problem 9-6
 *
 * Given a matrix in which each row and each column is sorted,
 * write a method to find an element in it.
 *
 *
 *
 *  1  2  5 10 11
 *  3  4  6 12 15
 * 45 46 48 50 60 
 *
 * Search on column
 * 	if num bigger
 * 		search bottom half
 * 	if num smaller
 * 		search top half
 */

typedef std::vector<std::vector<int> > mat2d;

bool find(mat2d &mat, int elem){
	int height = mat.size(); 
	int col = mat[0].size() - 1;
	// Start looking from top row, right most column
	// You essentially split the current row and row +1 into two halves
	// Choose which half to search based on normal binary search logic
	for(int row = 0; row < height && col >= 0;){ 
		if(elem == mat[row][col]){
			return true;
		}else if(elem < mat[row][col]){
			// It's less than the current element
			// So it's to the left of it 
			col--;
		}else{
			// It's bigger 
			row++;
		}
	}
	return false;
}


int main(int argc, char *argv[]){
	mat2d mat({
		{1, 2, 4, 10, 11},
		{3, 4, 6, 12, 15},
		{45, 46, 48, 50, 60}
	});
	std::vector<int> elems;
	if(argc > 1){
		for(int i = 1; i < argc; i++){
			elems.push_back(std::atoi(argv[i]));
		}
		
	}else{
		elems.push_back(60);
	}
	for(auto elem : elems){
		bool found = find(mat, elem);
		if(found){
			std::cout << "Found: " << elem << std::endl;
		}else{
			std::cout << "Didn't find: " << elem << std::endl;
		}
	}
	
	return 0;
}
