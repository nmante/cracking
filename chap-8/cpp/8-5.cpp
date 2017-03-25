#include <iostream>
#include <vector>

/*
 * Problem 8-5
 *
 * Implement an algorithm to print all valid (e.g., properly opened and closed)
 * combinations of n-pairs of parentheses
 */


void printParens(int leftRemaining, int rightRemaining, std::string str, int count){
	// More left remaining means we can't go further
	if(leftRemaining < 0 || leftRemaining > rightRemaining){
		return;
	}
	
	if(leftRemaining == 0 && rightRemaining == 0){
		std::cout << str << std::endl;
	}else{
		// Use a left paren if there's some remaining 
		if(leftRemaining > 0){
			str[count] = '(';
			printParens(leftRemaining - 1, rightRemaining, str, count + 1);
		}

		// If we have used less right parens than left, try using a right parens
		if(leftRemaining < rightRemaining){
			str[count] = ')';
			printParens(leftRemaining, rightRemaining - 1, str, count + 1);
		}
	}
	

}

void test(int n){
	std::string str(2*n, ' ');
	std::cout << "===========" << std::endl;
	printParens(n, n, str, 0);
	std::cout << "===========" << std::endl;
}
int main(int argc, char *argv[]){
	std::vector<int> nums;
	if(argc > 1){
		for(int i = 1; i < argc; i++){
			nums.push_back(std::atoi(argv[i]));
		}
	}else{
		nums = {1};
	}
	for(auto n : nums){
		test(n);
	}


	return 0;
}
