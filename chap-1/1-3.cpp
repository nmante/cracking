#include <iostream>
/*
 * Design algorithm to remove the duplicate characters
 * in a string without using an additional buffer. 
 * Can use additional buffer
 */


void removeDuplicates(char *str);

int main(int argc, char *argv[]){

	char str[] = "hello";
	char str2[] = "racecar";

	removeDuplicates(str);
	removeDuplicates(str2);

	return 0;
}

void removeDuplicates(char *str){

	/*
	 * Solution:
	 * 	hello
	 * 	h   
	 * 	e
	 * 	l dup i=3
	 *
	 * 	1: For each character, compare it to all preceding characters
	 * 	If that character is in the string, skip it for adding to the 
	 * 	resultant string
	 * 	O(n^2) - no memory buffer needed
	 *
	 *
	 * 	2: Buffer used
	 *
	 * 	orig-buf -> racecar
	 *
	 *	secd-buf -> r:0, a:1, c:2, e:3, c, a, r
	 *
	 *	For each character add it to dictionary if it doesn't exist
	 *	key is character, value is index. dict is not necessarily sorted by value
	 *	sorting would require O(n logn)	
	 *
	 *
	 * 	3: Buffer 2 
	 *
	 * 	orig-buf -> helloworld
	 *
	 * 	keep track of seen characters
	 * 	Use array instead of dictionary
	 *
	 * 	What kind of char set? if ascii, then max 256 array for array buffer
	 * 	Each index corresponds to letter
	 *
	 * 	What is value at index?
	 * 		Boolean
	 * 		Index of character in string
	 *
	 * 	If boolean, then we can use the boolean array to say if we've seen this character
	 * 	then we can use a similar tail method from the first solution 
	 *
	 * 	- Iterate over the string
	 * 	- once we see a character, set the value of the array at the 
	 * 	- character index to be true
	 *
	 * 	While iterating, if we have seen the current character skip it
	 * 	if we havent seen it, update the end of the string 
	 *
	 *
	 *
	 * 	
	 */
	
	int len = strlen(str);
	if (str == NULL){
		return;
	}
	if (len < 2) {
		return;
	}

	int tail = 0;
	bool char_set[256] = {false};

	std::cout << "Original: " << str << std::endl;

	// Start from the second character 
	for(int i = 0; i < len; i++){
		// Check if we've seen it
		if(!char_set[str[i]]){
			char_set[str[i]] = true;
			str[tail++] = str[i];
		}
	}
	str[tail] = '\0';

	std::cout << "Deduplicated: " << str << std::endl;
}
