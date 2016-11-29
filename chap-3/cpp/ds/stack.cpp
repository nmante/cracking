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
T Stack<T>::popData(){
	Node<T> *result = pop();
	if(result){
		return result->getData();
	}
	return 0;
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

template <class T>
bool Stack<T>::empty(){
	return top == NULL ? true : false;
}

template <class A>
std::ostream& operator <<(std::ostream &out, const Stack<A> &s){
	Node<A> *t = s.top;
	if(!t){
		out << "Stack empty" << std::endl;
	}else{
		out << "Stack" << std::endl;
		out << " === " << std::endl;
		while(t){
			out << "| " << t->data << std::endl;
			t = t->next;
		}

		out << " === " << std::endl;
	}
	return out;
}
