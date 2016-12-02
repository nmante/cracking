#ifndef __NODE_HPP__
#define __NODE_HPP__

template <class T>
class Node {
public:
	Node<T> *left = NULL;
	Node<T> *right = NULL;
	T data;

public:
	Node(T data): data(data){}
	Node(T data, Node<T> *left, Node<T> *right)
		: data(data),
		left(left),
		right(right)
	{}
	~Node(){
		left = NULL;
		right = NULL;
	}
	Node<T> *remove(Node<T> *parent, T data);
	T findMin();
	T findMax();
	void print();
	
	
};

#include "node.cpp"
#endif // __NODE_HPP__
