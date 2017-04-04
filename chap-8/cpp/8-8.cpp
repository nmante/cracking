#include <iostream>
#include <vector>
#include <tuple>

/*
 * Problem 8-8
 * Write an algorithm to print all ways of arranging eight queens on a chess
 * board so that none of them share the same row, column or diagonal.
 */

typedef std::pair<int, int> Cell;
typedef std::vector<std::vector<bool> > Board;

bool isAttacked(Board &board, int row, int col){
	int boardHeight = board.size(), boardWidth = board[0].size();

	// check the vertical
	for(int r = 0; r < boardHeight; r++){
		if(board[r][col]){
			return true;
		}
	}

	// check the horizontal
	for(int c = 0; c < boardWidth; c++){
		if(board[row][c]){
			return true;
		}
	}

	// check the diagonal
	for(int i = 0; i < boardHeight; i++){
		for(int j = 0; j < boardWidth; j++){
			if(i - j == row - col){
				if(board[i][j]){
					return true;
				}
			}
			if(i + j == row + col){
				if(board[i][j]){
					return true;
				}
			}

		}
	}
	
	return false;
}
void printPath(std::vector<Cell> &path){
	for(int i = 0; i < (int)path.size(); i++){
		std::cout << "(" << path[i].first << ", " << path[i].second << "), ";
	}
	std::cout << std::endl;
}

bool printQueens(int numQueens, Board &board, std::vector<Cell> path){
	// Error handling
	if(numQueens < 0){
		return false;
	}
	// Base case
	if(numQueens == 0){
		// print the path
		printPath(path);
		return true;
	}

	// Look at every cell in board 
	int boardHeight = board.size(), boardWidth = board[0].size();
	for(int row = 0; row < boardHeight; row++){
		for(int col = 0; col < boardWidth; col++){
			// Place queen if cell not attacked
			if(isAttacked(board, row, col)){
				continue;
			}

			board[row][col] = true;

			// Add cell to path
			path.push_back(std::make_pair(row, col));
			
			// try placing
			if(printQueens(numQueens - 1, board, path)){
				return true;
			}
			
			// if placing doesn't work, remove from path
			board[row][col] = false;
			path.pop_back();
			
		}
	}

	return false;

}	

Board createBoard(int N){
	Board b(N, std::vector<bool>(N, false));
	return b;
}
int main(int argc, char *argv[]){
	Board b = createBoard(8);
	std::vector<Cell> path;
	printQueens(8, b, path); 

	return 0;
}
