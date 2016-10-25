#include <iostream>
#include <vector>
#include <typeinfo>


/*
 * Start time 4:10pm
 * Problem: 
 * 	Given an image represented by an NxN matrix where each 
 * 	pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees.
 * 	Can you do this in place?
 */

typedef std::vector< std::vector<int> > vec2d;
void rotateImage(int *image[]);
void printImage(vec2d image);
void rotateImageVec(vec2d image);

int main(int argc, char *argv[]){
	vec2d nonSquareImage{ 
		{1, 3, 10, 5}, 
		{11, 32, 50, 9} 
	};
	vec2d nonSquareImage2{
		{1,2},
		{3,4},
		{5,6},
		{7,8},
		{9,10}
	};

	vec2d squareImage{
		{1, 3, 10, 5}, 
		{11, 32, 50, 9}, 
		{10, 5, 20, 30},
		{6, 7, 2, 20}
	};

	//rotateImage(image);
	rotateImageVec(nonSquareImage);
	rotateImageVec(nonSquareImage2);
	rotateImageVec(squareImage);

	return 0;

}

void rotateImageVec(vec2d image){
	
	if(image.size() < 1){
		std::cout << "Image has no pixels" << std::endl;
		return;
	}
	// Original image has 'origWidth' columns and 'origWidth' rows
	int origWidth = image.at(0).size();
	int origHeight = image.size();

	// Create new image buffer with 'origWidth' rows and 'origHeight' columns
	vec2d image2(origWidth, std::vector<int>(origHeight));

	for(int col = 0; col < origWidth; col++){
		for(int row = 0; row < origHeight; row++){
			image2[col][row] = image[origHeight - row - 1][col];
		}
	}

	std::cout << "Original Image" << std::endl;
	printImage(image);

	std::cout << "Rotated Image" << std::endl;
	printImage(image2);

}

void printImage(vec2d image){
	std::cout << "======" << std::endl;
	for(auto & rowVec : image){
	       for(auto & pixel: rowVec){
		       std::cout << pixel << " ";

	       }	       
	       std::cout << std::endl;
	}
	std::cout << "======" << std::endl;
	std::cout << std::endl;
}

/*
	 * Solution:
	 * 	Need to rotate image 90 degrees
	 * 	Let's try moving from top row to see if there's a pattern
	 *
	 * 	a b c d
	 * 	e f g h
	 * 	i j k l
	 * 	m n o p
	 *
	 *
	 *
	 * 	x,y positions
	 * 	a -> (0,0) -> (3,0) 
	 * 	b -> (1,0) -> (3,1)
	 * 	c -> (2,0) -> (3,2)
	 * 	d -> (3,0) -> (3,3) 
	 *
	 * 	
	 * 	e -> (0,1) -> (2,0) 
	 * 	f -> (1,1) -> (2,1)
	 * 	g -> (2,1) -> (2,2)
	 * 	h -> (3,1) -> (2,3) 
	 *
	 * 	(x,y) -> (width - y - 1, x)
	 *
	 *	m -> (0,3) -> (4 - 3 - 1, 0) -> (0, 0) 
	 *	o -> (2,3) -> (4 - 3 - 1, 2) -> (0, 2)
	 *
	 *	Can do this in place by replacing
	 */
