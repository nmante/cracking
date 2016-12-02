#include "linkedlist.hpp"
#include <iostream>

template <class T>
LinkedList<T>::LinkedList(Node<T> *head){
	this->head = head;
}

template <class T>
LinkedList<T>::LinkedList(T data){
	this->head = new Node<T>(data);
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &ll){
	if(!ll.head){
		return;
	}
	Node<T> *tmp = ll.head;
	Node<T> *tmp2 = NULL;
	while(tmp){
		if(!this->head){
			this->head = new Node<T>(tmp->data);
			tmp2 = this->head;
		}else{
			tmp2->next = new Node<T>(tmp->data);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

template <class T>
void LinkedList<T>::prepend(T data){
	Node<T> *node = new Node<T>(data);
	node->next = this->head;
	this->head = node;
}

template <class T>
Node<T> *LinkedList<T>::traverse(){
	if(this->head == 0){
		std::cout << "List is empty. Nothing to traverse" << std::endl;
		return 0;
	}
	Node<T> *last = this->head;

	while(last->getNext()){
		last = last->getNext();
	}

	return last;
}

template <class T>
Node<T> *LinkedList<T>::find(T data){
	if(this->head == 0){
		std::cout << "List is empty" << std::endl;
		return 0;
	}
	Node<T> *tmp = this->head;
	while(tmp){
		if(tmp->getData() == data){
			return tmp;
		}
		tmp = tmp->getNext();

	}
	return 0; 
}

template <class T>
Node<T> *LinkedList<T>::append(T data){
	Node<T> *node = new Node<T>(data);
	if(this->head == 0){
		this->head = node;
		return this->head;
	}

	Node<T> *last = this->traverse();
	last->next = node;
	return node;
}

template <class T>
Node<T> *LinkedList<T>::insertBefore(T key, T newData){
	Node<T> *node = this->find(key);

	// Key doesn't exist
	if(node == 0){
		this->prepend(newData);
		return this->head;
	}

	// Key is at beginning of list
	Node<T> *tmp = this->head;
	if(tmp->getData() == key){
		this->prepend(newData);
		return this->head;
	}

	// Key is in the middle
	while(tmp->getNext()){
		if(tmp->getNext()->getData() == key){
			Node<T> *oldNext = tmp->getNext();
			Node<T> *newNext = new Node<T>(newData);
			tmp->next = newNext;
			newNext->next = oldNext;
			return newNext;
		}
		tmp = tmp->getNext();
	}

	return 0;
}

template <class T>
Node<T> *LinkedList<T>::insertAfter(T key, T newData){
	Node<T> *node = this->find(key);

	// Key doesn't exist
	if(node == 0){
		this->prepend(newData);
	}

	// Found the key
	Node<T> *newNode = new Node<T>(newData);
	newNode->next = node->getNext();
	node->next = newNode;

	return newNode;

}

template <class T>
void LinkedList<T>::printList(){
	Node<T> *tmp = this->head;
	while(tmp){
		std::cout << tmp->getData() << " -> "; 
		tmp = tmp->getNext();
	}
	std::cout << "NULL" << std::endl;
}

template<class T>
std::ostream& operator <<(std::ostream& out, const LinkedList<T> &ll){
	Node<T> *tmp = ll.head;
	while(tmp){
		out << tmp->getData() << " -> "; 
		tmp = tmp->getNext();
	}
	out << "NULL" << std::endl;
	return out;
}

