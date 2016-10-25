#include <iostream>
#include <string>

/*
 * Problem:
 * 	You have a method isSubstring -> it checks if string1 is substring of string2
 *
 * 	Write code to check if s2 is a rotation of s1
 * 	Example:
 * 		'waterbottle' is a rotation of 'erbottlewat'
 */

void test(std::string, std::string);
bool isRotation(std::string, std::string);
bool isRotation2(std::string, std::string);

int main(int argc, char *argv[]){
	test("waterbottle", "erbottlewa");
	test("erbottlewat", "waterbottle");
	test("main", "inma");
	return 0;
}

void test(std::string s1, std::string s2){
	if(isRotation2(s1,s2)){
		std::cout << s1 << " is a rotation of " << s2 << std::endl;
	}else{
		std::cout << s1 << " is not a rotation of " << s2 << std::endl;
	}

}

bool isRotation2(std::string s1, std::string s2){
	if(s1.length() == s2.length() && s1.length() > 0){
		std::string s2s2 = s2 + s2;
		std::cout << s2s2 << std::endl;
		return (s2s2.find(s1) != std::string::npos);

	}
	return false;

}

bool isRotation(std::string s1, std::string s2){
	// They must be the same length
	if(s1.length() != s2.length()){
		return false;
	}
	int index = 0;	
	for(int i = 0; i < (int)s1.length(); i++){
		std::string piece = s1.substr(i, s1.length() - i);
		if(s2.find(piece) != std::string::npos){
			// piece is a substring of s2
			index = i;
			break;
		}
	}
	std::string piece1 = s1.substr(0, index);
	std::string piece2 = s2.substr(s2.length() - index, s2.length());

	if(piece1 == piece2){
		return true;
	}

	return false;
}

/*
 * Solution:
 * 	Iterate through string 1
 * 		keep track of index we're at in string1
 * 		call isSubstring with remainder of string1 on all string2
 * 		if remainderString1 is substring of string2
 * 			exit loop
 *
 * 	compare the piece1 substring of string1 to 
 * 	piece1 = string1[:index]
 * 	piece2 = strign2[length - index:] 
 * 	if they are equal
 * 		return true
 *
 * 	return false otherwise
 * 	
 */


