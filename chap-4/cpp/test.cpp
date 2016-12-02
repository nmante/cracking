#include <iostream>
#include "ds/bst/bstree.hpp"
/*
 * Problem:
 */

template <class T> 
void allPrint(BSTree<T> &bst){
	std::cout << "In order Print" << std::endl;
	bst.prettyInOrderPrint(bst.getRoot());
	/*
	std::cout << "Post order Print" << std::endl;
	bst.prettyPostOrderPrint(bst.getRoot());
	
	std::cout << "Pre order Print" << std::endl;
	bst.prettyPreOrderPrint(bst.getRoot());
	*/
}

int main(){
	BSTree<int> bst;
	bst.insert(bst.getRoot(), 4);
	bst.insert(bst.getRoot(), 7);
	bst.insert(bst.getRoot(), 2);
	bst.insert(bst.getRoot(), 1);
	bst.insert(bst.getRoot(), 3);
	bst.insert(bst.getRoot(), 10);
	bst.insert(bst.getRoot(), 6);
	bst.inOrderPrint(bst.getRoot());
	std::cout << std::endl;
	bst.preOrderPrint(bst.getRoot());
	std::cout << std::endl;
	bst.postOrderPrint(bst.getRoot());
	std::cout << std::endl;

	allPrint(bst);	

	bst.remove(4);
	allPrint(bst);
	
	bst.remove(6);
	allPrint(bst);

	bst.remove(3);
	allPrint(bst);

	bst.remove(10);
	allPrint(bst);

	bst.remove(7);
	allPrint(bst);

	bst.remove(1);
	allPrint(bst);

	bst.remove(2);
	allPrint(bst);
	return 0;
}

/*
 * Solution:
 */
