#ifndef __NODE_HPP__
#define __NODE_HPP__

template <class T>
class Node {
public:
	Node<T> *left = nullptr;
	Node<T> *right = nullptr;
	Node<T> *parent = nullptr;
	T data;

public:
	Node(T data): data(data){}
	Node(T data, Node<T> *left, Node<T> *right)
		: data(data),
		left(left),
		right(right)
	{}
	~Node(){
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	Node<T> *remove(Node<T> *parent, T data);
	T findMin();
	T findMax();
	void print();
	
	
};

#include "node.tpp"
#endif // __NODE_HPP__
