#include <iostream>
#include <bitset>

/*
 * Problem: Given an integer, print the net smallest and next largest number that 
 * 	    have the same number of 1 bits in their binary representation.
 *
 * Examples:
 *
 * 	2(0010) -> 1(0001), 4(0100)
 *
 * 	3(0011) -> 5(0101),  
 *
 * 	17(10001) -> 12(01100), 18(10010)  
 *
 * 	45(101101) ->  (011110), (10 
 */

namespace solution1 {
	unsigned nextSmallestSameBits(unsigned a){
		return a;
	}

	unsigned nextLargestSameBits(unsigned a){
		unsigned c = (a & -a);
		unsigned r = a + c;
		return (((r ^ a) >> 2) / c) | r;
	}
	void test(unsigned orig){
		unsigned a = solution1::nextLargestSameBits(orig);
		unsigned b = solution1::nextSmallestSameBits(orig);
		std::cout << "Original: bin(" << std::bitset<16>(orig) << ") dec(" << orig << ") " << std::endl;
		std::cout << "Next Largest: bin(" << std::bitset<16>(a) << ") dec(" << a << ") " << std::endl;
		std::cout << "Next Smallest: bin(" << std::bitset<16>(b) << ") dec(" << b << ") " << std::endl;
	}
}

namespace solution2 {
	unsigned getBit(unsigned num, int bit){
		return (num & (1 << bit)) ? 1 : 0;  
	}
	unsigned setBit(unsigned num, int bit){
		unsigned result = num |= (1 << bit);
		return result;
	}	

	unsigned clearBit(unsigned num, int bit){
		unsigned result = num &= ~(1 << bit);
		return result;
	}

	unsigned nextLargestSameBits(unsigned num){
		return num;
	}

	unsigned nextSmallestSameBits(unsigned num){
		// Start from right most bit
		// if current bit is zero, and bit to left is 1
			// toggle both of these bits
		return num;
	}

	void clearTest(unsigned orig, int bit){
		std::cout << "======= Clear Test =======" << std::endl;
		unsigned result = clearBit(orig, bit);
		std::cout << "Clearing bit: " << bit << std::endl;

		std::cout << "Original: bin(" << std::bitset<16>(orig);
		std::cout << ") dec(" << orig << ") " << std::endl;

		std::cout << "Cleared: bin(" << std::bitset<16>(result);
		std::cout << ") dec(" << result << ") " << std::endl;
	}
	void test(unsigned orig){
		unsigned a = nextLargestSameBits(orig);
		unsigned b = nextSmallestSameBits(orig);
		std::cout << "Original: bin(" << std::bitset<16>(orig) << ") dec(" << orig << ") " << std::endl;
		std::cout << "Next Largest: bin(" << std::bitset<16>(a) << ") dec(" << a << ") " << std::endl;
		std::cout << "Next Smallest: bin(" << std::bitset<16>(b) << ") dec(" << b << ") " << std::endl;
	}
}

int main(int argc, char *argv[]){
	if(argc > 1){
		for(int i = 1; i < argc; i++){
			solution1::test(atoi(argv[i]));
			solution2::test(atoi(argv[i]));
		}
	}

	solution1::test(35);
	solution2::clearTest(73, 3);
	solution2::clearTest(74, 1);
	solution2::clearTest(73, 1);
	return 0;
}
