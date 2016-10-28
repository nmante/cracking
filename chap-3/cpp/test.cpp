#include <iostream>
#include "ds/stack.hpp"
#include "ds/queue.hpp"

int main(){
	Stack<int> s(5);
	std::cout << s.peek() << std::endl;
	std::cout << s << std::endl;
	s.pop();
	std::cout << s << std::endl;
	s.pop();
	std::cout << s << std::endl;

	Queue<int> q(5);
	q.enqueue(6);
	std::cout << q << std::endl;
	Node<int> val = q.dequeue();

	std::cout << "Dequeued: " << val.data << std::endl;

	std::cout << q << std::endl;
	
	return 0;
}
