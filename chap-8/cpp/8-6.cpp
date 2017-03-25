#include <iostream>
#include <vector>

/*
 * Problem 8-6
 * Implement the paint fill function that one might see on many image editing
 * programs. That is, given a screen (represented by a 2-d array of colors),
 * a point, and a new color, fill the surrounding area until you hit a border
 * of that color.
 *
  *
 *
 * b b b b b b
 * w w w w w w
 * w w w w w w
 * b w w w w w
 * b w w w w w
 * b w w w w w
 *
 *
 * color is b
 * click point (4, 3)
 *
 * b b b b b b
 * w w w w w w
 * w w w w w w
 * b w w w w w
 * b w w b w w
 * b w w w w w
 *
 *
 * b b b b b b
 * w w w w w w
 * w w w w w w
 * b w b b b w
 * b w b b b w
 * b w b b b w
 *
 * b b b b b b
 * w w w w w w
 * w w w w w w
 * b w b b b w
 * b w b b b w
 * b w b b b w
 *
 *
 * b b b b b b
 * w w w w w w
 * w b b b b b 
 * b b b b b b 
 * b b b b b b 
 * b b b b b b 
 *
 *
 * b b b b b b
 * w w w w w w
 * w b b b b b 
 * b b b b b b 
 * b b b b b b 
 * b b b b b b 
 *
 * keep track of walls for each square
 * square size can be from 1 - N
 * while recursing if any wall has color, stop
 * otherwise, fill walls
 * recurse with larger square
 */

enum Color {
	black,
	white,
	red,
	green,
	blue,
	yellow,
	orange,
	purple
};
typedef std::vector<std::vector<Color> > mat2d;


bool paintFill(mat2d &screen, int row, int col, Color origColor, Color newColor){
	// error handling
	if(screen.size() < 1){
		return false;
	}
	int screenHeight = screen.size();
	int screenWidth = screen[0].size();
	if(row < 0 || row >= screenHeight
	 || col < 0 || col >= screenWidth){
		return false;
	}

	// if any walls filled with color, stop
	if(screen[row][col] == origColor){
		screen[row][col] = newColor;
		paintFill(screen, row - 1, col, origColor, newColor); // top
		paintFill(screen, row + 1, col, origColor, newColor); // bottom
		paintFill(screen, row, col - 1, origColor, newColor); // left
		paintFill(screen, row, col + 1, origColor, newColor); // right
	}
		
	return true;
}
bool paintFill(mat2d &screen, int row, int col, Color newColor){ 
	return paintFill(screen, row, col, screen[row][col], newColor);
}

int main(int argc, char *argv[]){
	return 0;
}
