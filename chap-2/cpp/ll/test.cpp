#include <iostream>
#include "linkedlist.hpp"

int main(){
	LinkedList<int> ll(5);
	std::cout << "Initial list" << std::endl;
	std::cout << ll << std::endl;
	ll.insertAfter(5, 10);

	std::cout << "Inserted 10 after 5" << std::endl;
	std::cout << ll << std::endl;

	std::cout << "Inserted 20 before 5" << std::endl;
	ll.insertBefore(5, 20);
	std::cout << ll << std::endl;


	std::cout << "Prepended 3" << std::endl;
	ll.prepend(3);
	std::cout << ll << std::endl;

	std::cout << "Appended 37" << std::endl;
	ll.append(37);
	std::cout << ll << std::endl;

	LinkedList<int> ll2(ll);
	std::cout << "Copy: " << ll2 << std::endl;

	ll.append(4);
	std::cout << "Orig after appending 4: " << ll << std::endl;
	std::cout << "Copy after appending 4 to orig: " << ll2 << std::endl;
	return 0;
}
