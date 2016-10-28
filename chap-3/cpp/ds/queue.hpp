#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__
#include "node.hpp"
#include <ostream>

template <class T>
class Queue {

private:
	Node<T> *first;
	Node<T> *last; 

public:
	Queue(T data){ 
		first = new Node<T>(data);
		last = first;
	}
	~Queue(){
		Node<T> *tmp = first;
		while(tmp){
			Node<T> *toDelete = tmp;
			tmp = tmp->next;
			delete toDelete;
		}
		first = 0;
		last = 0;
	}

	void enqueue(T data);
	Node<T> dequeue();

	template <class A>
	friend std::ostream & operator <<(std::ostream &out, const Queue<A> &q);

};

#include "queue.cpp"
#endif // __QUEUE_HPP__
