#include "node.hpp"
#include <iostream>

template <class T>
Node<T> * Node<T>::remove(Node<T> *parent, T data){
	if(data < this->data){
		// Value to delete may be in left sub tree
		if(this->left){
			return this->left->remove(this, data);
		}
	}else if(data > this->data){
		// Value to delete may be in right sub tree
		if(this->right){
			return this->right->remove(this, data);
		}
	}else{
		if(this->left && this->right){
			// Find the in order successor (IOS) then overwrite the value of 
			// matching node with the IOS value 
			T minValue = this->right->findMin();
			this->data = minValue;

			// Now delete the IOS node in the lower part of the tree
			return this->right->remove(this, minValue);
		}else if(parent->left == this){
			// 'this' is the left child of the 'parent'
			// and 'this' has at most one child
			// move the child of 'this' to be the parent's left child
			parent->left = (this->left) ? this->left : this->right;

			// Return 'this' so we can delete it from the tree
			return this;
		}else if(parent->right == this){
			// 'this' is the right child of the 'parent'
			// and 'this' has at most one child
			// move the child of 'this' to be the parent's right child
			parent->right = (this->left) ? this->left : this->right;

			// Return 'this' so we can delete it from the tree
			return this;
		}
	}

	return NULL;
}

template <class T>
T Node<T>::findMax(){
	if(!this->right){
		return this->data;
	}
	return this->right->findMax();
}

template <class T>
T Node<T>::findMin(){
	if(!this->left){
		return this->data;
	}
	return this->left->findMin();
}

template <class T>
void Node<T>::print(){
	std::string leftStr = (left) ? std::to_string(left->data) : "NULL";
	std::string rightStr = (right) ? std::to_string(right->data) : "NULL";

	std::cout << "Node : {" << std::endl;
	std::cout << '\t' << "data: " << data << std::endl;
	std::cout << '\t' << "left: " << leftStr  << std::endl;
	std::cout << '\t' << "right: " << rightStr  << std::endl;
	std::cout << "}" << std::endl;
}

