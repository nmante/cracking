#include <iostream>
#include "ds/bst/bstree.hpp"


/*
 * Problem:
 * 	You have two very large binary trees: T1, with millions of nodes, and T2, 
 * 	with hundreds of nodes. Create an algorithm to decide if T2 is a subtree
 * 	of T1
 *
 * start: 350pm
 */

bool isIdentical(Node<int> *root1, Node<int> *root2){
	if(!root1 && !root2){
		return true;
	}

	if(!root1 || !root2){
		return false;
	}

	return root1->data == root2->data 
		&& isIdentical(root1->left, root2->left)
		&& isIdentical(root1->right, root2->right);
}

bool isSubTree(Node<int> *root1, Node<int> *root2){
	if(!root2) return true;

	if(!root1) return false;

	if(isIdentical(root1, root2))
		return true;


	/*
	if(root1->data == root2->data){
		bool subTreesEqual = isSubTree(root1->left, root2->left) 
			&& isSubTree(root1->right, root2->right);
		if(subTreesEqual) return true;
	}else{
		return false;
	}
	*/

	return isSubTree(root1->left, root2) 
			|| isSubTree(root1->right, root2);
}

void test(BSTree<int> &bst, BSTree<int> &bst2){
	bool areSubtrees = isSubTree(bst.root, bst2.root);
	std::cout << "------------------------------" << std::endl;

	std::cout << " =========== TREE 1 ==========" << std::endl;
	bst.prettyInOrderPrint(bst.root);
	std::cout << " =========== TREE 2 ==========" << std::endl;
	bst2.prettyInOrderPrint(bst2.root);

	std::string res = areSubtrees ? "Tree 2 is a subtree of Tree 1" : 
	       "Tree 2 is not a subtree of Tree 1";	

	std::cout << res << std::endl;
	std::cout << "------------------------------" << std::endl;
}

int main(){
	BSTree<int> bst;
	bst.insert(bst.root, 10);
	bst.insert(bst.root, 5);
	bst.insert(bst.root, 2);
	bst.insert(bst.root, 1);
	bst.insert(bst.root, 3);
	bst.insert(bst.root, 15);
	bst.insert(bst.root, 12);
	bst.insert(bst.root, 11);
	bst.insert(bst.root, 13);
	bst.insert(bst.root, 18);
	bst.insert(bst.root, 14);
	bst.insert(bst.root, 20);

	BSTree<int> bst2;
	bst2.insert(bst2.root, 15);
	bst2.insert(bst2.root, 12);
	bst2.insert(bst2.root, 11);
	bst2.insert(bst2.root, 13);
	bst2.insert(bst2.root, 18);
	bst2.insert(bst2.root, 14);
	bst2.insert(bst2.root, 20);
	test(bst, bst2);	

	BSTree<int> bst3;
	bst3.insert(bst3.root, 12);
	bst3.insert(bst3.root, 11);
	bst3.insert(bst3.root, 13);
	bst3.insert(bst3.root, 18);
	bst3.insert(bst3.root, 14);
	bst3.insert(bst3.root, 20);
	test(bst, bst3);	
	
	BSTree<int> bst4;
	bst4.insert(bst4.root, 12);
	bst4.insert(bst4.root, 11);
	bst4.insert(bst4.root, 13);
	bst4.insert(bst4.root, 14);
	test(bst, bst4);	

	return 0;
}

/*
 * Solution 1:
 * 	- We need to determine if tree2 is a subtree of tree2
 * 	- What does it mean for tree2 to be a subtree
 *
 * 	- starting at any node in tree1 if the root and all children in 
 * 	right and left subtrees equal the root in tree2 and all it's
 * 	children, then tree2 is a subtree
 *
 * 	Steps:
 * 		- if either node is null return false
 * 		- compare both roots
 * 			- if they are equal
 * 				- recurse and compare the left subtrees
 * 				- recurse and compare the right subtrees 
 * 				- if both of these cases are true, you're done
 * 			- if they aren't
 * 				- compare the left tree of tree1 to tree2
 * 				- compare the right tree of tree1 to tree2 
 * 				- if either of these cases are true you're done
 *
 * 	Drawbacks:
 * 		For millions of nodes, we may run out of stack space. Even 
 * 		though these trees are on the stack, it's possible the shear
 * 		amount of function calls would be too much memory
 *
 * Solution 2:
 * 	- May need iterative solution
 * 	- Compilers can optimize for iterative solution
 *
 * 	- Can convert trees into strings via a traversal
 * 	- If we tree2 string is a substring of tree1 string, then it's a subtree
 *			
 *
 */
