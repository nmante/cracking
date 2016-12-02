#ifndef __NODE_HPP__
#define __NODE_HPP__

template<class T>
class Node{
public:
	T data;
	Node *next;

public:
	Node<T>(T data, Node *next){
		this->data = data;
		this->next = next;
	}
	Node<T>(T data){
		this->data = data;
		this->next = 0;
	}
	Node<T>(Node<T> &n){
		this->data = n.data;
		this->next = new Node(n.data);
	}
	~Node<T>(){
		this->next = 0;
	}

	T getData(){ return data; }
	Node<T> *getNext(){ return next; }

};

#endif // __NODE_HPP__
