#include "bstree.hpp"
#include <iomanip>

template <class T>
bool BSTree<T>::search(Node<T> *node, T data){
	if(!node){
		return false;
	}
	if(node->data == data){
		return true;
	}
	return search(node->left, data)
		|| search(node->right, data); 
}

template <class T>
void BSTree<T>::insert(Node<T> *node, T data){
	if(!root){
		root = new Node<T>(data);
		return;
	}
	if(!node){
		return;
	}
	if(data < node->data){
		Node<T> *left = node->left;
		if(left){
			insert(left, data);
		}else{
			node->left = new Node<T>(data);
		}
		
	}else{
		Node<T> *right = node->right;
		if(right){
			insert(right, data);
		}else{
			node->right = new Node<T>(data);
		}
	}

}

template <class T>
void findMin(Node<T> *node){
	if(!node){
		return;
	}
	if(node->left){
		findMin(node->left);
	}else{

	}

}	
template <class T> 
bool BSTree<T>::remove(T data){
	/*
	 * This is the top level function for removing
	 * It will call the removeNode function if necessary
	 *
	 * Logic:
	 * 	Few cases
	 * 	1. Empty tree
	 * 	2. Root is the value
	 * 	3. value is below root
	 *
	 */
	
	if(this->root == NULL){
		return false;
	}else{
		Node<T> *removedNode = NULL;
		if(this->root->data == data){
			Node<T> tmpRoot(0);
			tmpRoot.left = this->root;
			removedNode = this->root->remove(&tmpRoot, data);
			root = tmpRoot.left;
		}else{
			removedNode = this->root->remove(NULL, data);
		}
		if(removedNode){
			delete removedNode;
			return true;
		}
		return false;
	}

}

template <class T>
void BSTree<T>::inOrderPrint(Node<T> *node){
	if(!node){
		return;
	}
	inOrderPrint(node->left);
	std::cout << node->data << " "; 
	inOrderPrint(node->right);
}

template <class T>
void BSTree<T>::postOrderPrint(Node<T> *node){
	if(!node){
		return;
	}
	postOrderPrint(node->left);
	postOrderPrint(node->right);
	std::cout << node->data << " ";
}

template <class T>
void BSTree<T>::preOrderPrint(Node<T> *node){
	if(!node){
		return;
	}
	std::cout << node->data << " ";
	preOrderPrint(node->left);
	preOrderPrint(node->right);

}

template <class T>
void BSTree<T>::prettyInOrderPrint(Node<T> *node, int indent){
	if(!node){
		return;
	}

	prettyInOrderPrint(node->left, indent + 4);
	if(indent){
		std::cout << std::setw(indent) << ' ';
	}
	std::cout << node->data << std::endl;
	prettyInOrderPrint(node->right, indent + 4);

}


template <class T>
void BSTree<T>::prettyPostOrderPrint(Node<T> *node, int indent){
	if(!node){
		return;
	}
	
	prettyPostOrderPrint(node->left, indent + 4);
	prettyPostOrderPrint(node->right, indent + 4);
	if(indent){
		std::cout << std::setw(indent) << ' ';
	}
	std::cout << node->data << std::endl;
}

template <class T>
void BSTree<T>::prettyPreOrderPrint(Node<T> *node, int indent){
	if(!node){
		return;
	}

	if(indent){
		std::cout << std::setw(indent) << ' ';
	}
	std::cout << node->data << std::endl;
	prettyPreOrderPrint(node->left, indent + 4);
	prettyPreOrderPrint(node->right, indent + 4);
	

}
