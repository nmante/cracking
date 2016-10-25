#include <iostream>
#include <vector>
#include <set>
/*
 * Problem:
 * 	Write an algorithm such that if an element in an MxN matrix is 0, it's
 * 	entire row is set to 0
 */

typedef std::vector< std::vector<int> > vec2d;

void zeroMatrix(vec2d matrix);
void printMatrix(vec2d matrix);

int main(int argc, char *argv[]){

	vec2d matrix{
		{10, 3, 2, 1},
		{5, 0, 7, 3},
		{3, 10, 1, 50}
	};
	zeroMatrix(matrix);

	return 0;
}

void zeroMatrix(vec2d matrix){

	// Make sure we have elements
	
	if(matrix.size() < 1){
		std::cout << "Matrix doesn't have elements" << std::endl;
		return;
	}
	// Iterate through all items
	// Unavoidable because you have to verify if an item is a
	// zero
	
	printMatrix(matrix);
	int height = matrix.size();
	int width = matrix.at(0).size();
	std::set<int> zeroRows;
	std::set<int> zeroCols;


	// You have to set the row and column of that element to zero
	// If you do that right away, then as you move through rows
	// you'll see zeroes that you did earlier
	//
	// Keep track of original zeroes, then zero later
	// keep a list/buffer to store zero coordinates
	
	for(int row = 0; row < height; row++){
		for(int col = 0; col < width; col++){
			// If we see a zero in this row,
			// Zero out the entire row
			if(matrix[row][col] == 0){
				zeroRows.insert(row);
				zeroCols.insert(col);
			}
		}
	}
	for(auto &row : zeroRows){
		matrix[row] = std::vector<int>(width);
		
	}
	for(int row = 0; row <  height; row++){
		for(auto &col : zeroCols){
			matrix[row][col] = 0;
		}
	}

	printMatrix(matrix);
}

void printMatrix(vec2d matrix){
	int width = matrix[0].size();
	int height = matrix.size();
	std::cout << "=======" << std::endl;
	for(int row = 0; row < height; row++){
		for(int col = 0; col < width; col++){
			std::cout << matrix[row][col] << " ";
		}
		std::cout << std::endl;
	}	
	std::cout << "=======" << std::endl;
	std::cout << std::endl;

}

/*
 * Solution:
 *
 * 	What kind of numbers? int, float?
 * 	Negative?
 *
 * 	You have to look at every item once
 * 	O(MxN) to look through all items
 *
 * 	Once you find a zero, you have to assign all items in row
 * 	O(M^2xN)
 *
 *
 * Solution2:
 * 	Is there a faster way?
 *
 *
 */	
 
