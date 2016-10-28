#include "stack.hpp"

template <class T>
Node<T> *Stack<T>::pop() {
	Node<T> *result = 0;
	if (top){
		result = new Node<T>(top->data, top->next);
		Node<T> *toDelete = top;
		top = top->next; 
		delete toDelete;
		return result;
	}
	return result;
}

template <class T>
void Stack<T>::push(T data) {
	Node<T> *newNode = new Node<T>(data, this->top); 
	top = newNode;
}

template <class T>
T Stack<T>::peek(){
	return top ? top->data : 0; 
}

template <class A>
std::ostream& operator <<(std::ostream &out, const Stack<A> &s){
	Node<A> *top = s.top;
	if(!top){
		out << "Stack empty" << std::endl;
	}else{
		out << "Stack" << std::endl;
		out << " === " << std::endl;
		while(top){
			out << "| " << top->data << std::endl;
			top = top->next;
		}

		out << " === " << std::endl;
	}
	return out;
}
