#include <iostream>

/*
 * Problem 8-7
 * Given an infinite number of quarters, dimes, nickels and pennies,
 * write code to calculate the number of ways of representing n cents.
 */

// Non unique method
int numberOfWays(int N){
	if(N < 0){
		return 0;
	}
	if(N == 0){
		return 1;
	}

	return numberOfWays(N - 25) + numberOfWays(N - 10) + numberOfWays(N - 5) + numberOfWays(N - 1);
}

int makeChange(int n, int denom){
	int next_denom = 0;
	switch (denom) {
	case 25:
		next_denom = 10;
		break;
	case 10:
		next_denom = 5;
		break;
	case 5:
		next_denom = 1;
		break;
	case 1:
		return 1; 
	}
	int ways = 0; 
	for(int i = 0; i*denom <= n; i++){
		ways += makeChange(n - i * denom, next_denom); 
	}
	return ways;
}
void test(int N){
	int num = numberOfWays(N);
	std::cout << "============" << std::endl;
	std::cout << "Number of ways to represent " << N << " cents is: " << num << std::endl;

	num = makeChange(N, 25);
	std::cout << "Cracking: Number of ways to represent " << N << " cents is: " << num << std::endl;
	std::cout << "============" << std::endl;
}
int main(int argc, char *argv[]){
	test(25);
	test(10);
	test(5);
	test(1);
	test(7);
	return 0;
}
