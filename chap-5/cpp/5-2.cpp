#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/*
 * Problem: Given a decimal number (e.g., 3.72) that is passed in as a string,
 * 	    print the binary representation. If the number can not be represented 
 * 	    accurately in binary, print "ERROR".
 *
 * Solution:
 * 	5 % 2 = 
 */
std::vector<std::string> split(const std::string &text, char sep) {
	std::vector<std::string> tokens;
	std::size_t start = 0, end = 0;
	while ((end = text.find(sep, start)) != std::string::npos) {
		tokens.push_back(text.substr(start, end - start));
		start = end + 1;
	}
	tokens.push_back(text.substr(start));
	return tokens;
}

void printBinaryRepr(std::string numberString){
	// Nii's solution
	// Get number before decimal
	std::vector<std::string> parts = split(numberString, '.'); 
	if(parts.size() < 1){
		return;
	}

	// Convert that to binary	
	int integer = std::stoi(parts[0]); 
	std::string integerString = "";
	while(integer > 0){
		int r = integer % 2;
		integer /= 2;
		integerString = std::to_string(r) + integerString;
	}
	
	if(parts.size() < 2){
		std::cout << integerString << std::endl;
		return;
	}
	// Get number after decimal
	std::string ds = parts[1];
	if(ds.length() > 32) {
		std::cout << "ERROR" << std::endl;
		return;
	}
	//int decimal = std::stoi(parts[1]); 
	std::string decimalString = "";
	for(int i = 0; i < (int)ds.length(); i++){
		if(ds[i] - '0' > 4){
			decimalString += "1";
		}else{
			decimalString += "0";
		}
	}
	std::cout << integerString << "." << decimalString << std::endl;
	
}

void printBinary(std::string n) {
	// This is solution from cracking the coding interview
	// Initially it was in Java. I translated it to c++
	// Doesn't seem like this solution is working properly
	int intPart = std::stoi(split(n, '.')[0]); 
	double decPart = std::stod(split(n, '.')[1]); 
	std::string int_string = "";

	while (intPart > 0) {
		int r = intPart % 2; 
		std::cout << "r: " << r << std::endl;
		intPart >>= 1;
		int_string = std::to_string(r) + int_string;
	}
	
	std::string dec_string = ""; 
	while (decPart > 0) {
		if (dec_string.length() > 32){ 
			std::cout << "ERROR" << std::endl; 
			return;
		}

		if (decPart == 1) {
			dec_string += std::to_string((int)decPart);
			break; 
		}
		
		double r = decPart * 2; 
		if(r >= 1){
			dec_string += "1";
			decPart = r - 1; 
		}else{
			dec_string += "0";
			decPart = r; 
		}
	}

	std::cout << int_string << "." << dec_string << std::endl; 
}

int main(){
	std::cout << "Nii solution" << std::endl;
	printBinaryRepr("69.625");
	printBinaryRepr("53.721");
	printBinaryRepr("0.1");
	printBinaryRepr("0.1011328839281899284");
	
	std::cout << "Cracking Solution" << std::endl;
	printBinary("0.1321");
	printBinary("0.10111899284");
	return 0;
}
