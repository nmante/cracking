#include <iostream>

// Determine if two strings are anagrams


bool areAnagrams(char *word1, char *word2);
void test(char *word1, char *word2){
	const char *result1 = areAnagrams(word1, word2) ? "true" : "false";
	std::cout << word1 << " and " << word2 << " anagrams? " << result1 << std::endl;
}
int main(int argc, char *argv[]){

	char word1[] = "draw", word2[] = "ward";
	char word3[] = "hello", word4[] = "hell";
	char word5[] = "anagram", word6[] = "nagaram";

	test(word1, word2);
	test(word3, word4);
	test(word5, word6);

	return 0;
}

bool areAnagrams(char *word1, char *word2){

	/*
	 * Questions:
	 *
	 * 	Are extra buffers allowed? Like a hash/dictionary/array?
	 * 	What character set? ASCII?
	 *
	 * Solution:
	 * 	1. Buffer/Dictionary Approach
	 *
	 * 	ward -> draw (example of two anagrams)
	 *
	 * 	- if two words are anagrams, they have identical character counts
	 * 	- create a buffer to store character counts
	 *
	 * 	First check if they are the same length
	 * 	Then iterate through all characters in both words (you need to look a
	 * 	at all characters)
	 *
	 * 	O(n) time with worst case O(n) space
	 *
	 * 	2. No buffer
	 *
	 * 	SORT the strings
	 *
	 * 	ward -> draw
	 *
	 *
	 */
	
	// Store character counts, indices are integer values of characters ('a' -> 97)
	int char_dict1[256] = {0};
	int char_dict2[256] = {0};

	int len1 = strlen(word1), len2 = strlen(word2);
	
	// Must have same length
	if (len1 != len2){
		return false;
	}
	
	// Sum up the character counts
	for (int i = 0; i < len1; i++){
		char_dict1[word1[i]]++;
		char_dict2[word2[i]]++;
	}

	// If the character counts for each character don't match up
	// then these words aren't anagrams
	for (int i = 0; i < 256; i++){
		if (char_dict1[i] != char_dict2[i]){
			return false;
		}
	}
	
	return true;

}
