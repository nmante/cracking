#include <iostream>
#include <vector>

/*
 * Problem 8-2
 * Imagine a robot sitting on the upper left hand corner of an NxN grid. 
 * The robot can only move in two directions. How many possible paths are
 * there for the robot?
 */

typedef std::vector< std::vector<int> > mat2d;

int numPaths(int row, int col, mat2d &grid){
	// Should be sum of num paths going right and num paths going down
	// Should stop once we've reached the end 
	if(row == (int)grid.size() - 1 || col == (int)grid.size() - 1){
		return 1;
	}
	
	return numPaths(row + 1, col, grid) + numPaths(row, col + 1, grid);
}

void test(mat2d &grid){
	int numP = numPaths(0, 0, grid);
	std::cout << "Given a grid with size N = " << grid.size() << std::endl;
	std::cout << "The number of paths is: " << numP << std::endl;
}

mat2d createGrid(int N){
	mat2d grid(N, std::vector<int>(N, 0));
	return grid;
}


int main(int argc, char *argv[]){
	mat2d g1 = createGrid(4);
	mat2d g2 = createGrid(6);
	mat2d g3 = createGrid(10);
	std::vector<mat2d> grids({g1, g2, g3});
	for(auto g : grids){
		test(g);
	}
	
	return 0;
}
