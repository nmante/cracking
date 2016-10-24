#ifndef __LINKEDLIST_HPP__
#define __LINKEDLIST_HPP__

#include "node.hpp"
#include <iostream>

template<class T>
class LinkedList {

private:
	Node<T> *head;

public:
	LinkedList<T>(Node<T> *head);
	LinkedList<T>(T data); 
	
	// Insertion & traversion
	void prepend(T data);
	Node<T> *find(T data);
	Node<T> *traverse();
	Node<T> *append(T data);
	Node<T> *insertBefore(T key, T newData);
	Node<T> *insertAfter(T key, T newData);
	Node<T> *remove(T data);
	Node<T> *remove(Node<T> *node);

	Node<T> *getHead() { return head; }

	void printList();
	template<class A>
	friend std::ostream& operator <<(std::ostream& out, const LinkedList<A> &ll);

};

#include "linkedlist.cpp"

#endif // __LINKEDLIST_HPP__
