#ifndef __STACK_HPP__
#define __STACK_HPP__
#include <iostream>
#include <ostream>
#include "node.hpp"

template <class T>
class Stack {

private:
	Node<T> *top = NULL;

public:
	Stack(){};
	Stack(T data){ top = new Node<T>(data); }
	~Stack(){}
	
	Node<T> *pop();
	T popData();
	void push(T data);
	T peek();
	bool empty();

	template <class A>
	friend std::ostream& operator << (std::ostream &out, const Stack<A> &s);
};

#include "stack.cpp"
#endif // __STACK_HPP__
