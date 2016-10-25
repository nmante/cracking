#include <iostream>

/*
 * Problem reverse a c style string
 *
 * Proposed solution
 *
 * 1:
 * 	Can iterate through each character up until midpoint of string
 * 	Swap each character with it's counter part (beginning of string with end (not null character), etc.)
 *
 * 	abcdef
 * 	fbcdea
 */


void reverseString(char *str);
int main(int argc, char *argv[]){
	char str[] = "cool";
	//len including null string
	reverseString(str);

	return 0;
}

void reverseString(char *str){

	char temp;
	int len = strlen(str);
	std::cout << len << std::endl;
	std::cout << str << std::endl;
	for(int i = 0; i < len/2; i++){
		temp = str[i];
		std::cout << "temp: " << temp << std::endl;
		str[i] = str[len/2 + 1 - i]; 
		str[len/2 + 1 - i] = temp;

	}
	std::cout << str << std::endl;

}
