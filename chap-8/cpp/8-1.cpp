#include <iostream>
#include <vector>
#include <map>

/*
 * Problem 8-1
 * Write a method to generate the nth Fibonacci number
 */


int fibonacci(int n, std::map<int, int> &memo){
	if(n < 0){
		return 0;
	}
	if(n == 0 || n == 1){
		memo[n] = n;
		return n;
	}
	if(memo.count(n) == 1){
		return memo[n];
	}
	memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo); //memo[n - 1] + memo[n - 2];
	return memo[n]; 
}

void test(int n){
	std::map<int, int> memo;
	int fib = fibonacci(n, memo);

	std::cout << "The " << n << " Fibonacci number is: " << fib << std::endl;

}


int main(int argc, char *argv[]){
	std::vector<int> a({1, 3, 10, 11, 5});
	for(auto el : a){
		test(el);
	}
	return 0;
}
