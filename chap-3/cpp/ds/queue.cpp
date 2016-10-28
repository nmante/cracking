#include "queue.hpp"

template <class T>
void Queue<T>::enqueue(T data){
	if(this->last){
		Node<T> *newNode = new Node<T>(data);
		this->last->next = newNode;
		this->last = newNode;
	}
}

template <class T>
Node<T> Queue<T>::dequeue(){
	if(this->first){
		Node<T> result(this->first->data);
		Node<T> *toDelete = this->first;
		this->first = this->first->next;
		delete toDelete;
		return result;

	}
	return 0;
}

template <class A>
std::ostream & operator <<(std::ostream &out, const Queue<A> &q){
	
	if(!q.first){
		out << "Queue Empty" << std::endl;
	}else{
		out << "Queue" << std::endl;
		Node<A> *tmp= q.first;
		out << "First" << std::endl;
		out << "=====" << std::endl;
		while(tmp){
			out << tmp->data << std::endl;
			tmp = tmp->next;
		}
		out << "=====" << std::endl;
		out << "Last" << std::endl;
	}
	return out;
}
