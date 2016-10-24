#include <iostream>
#include "ll/linkedlist.hpp"
#include <map>

/*
 * Problem:
 * 	Write code to remove duplicates from an unsorted list
 */

template <class T>
void removeDuplicatesWithBuffer(LinkedList<T> &ll);

template <class T>
void removeDuplicatesWithoutBuffer(LinkedList<T> &ll);

template <class T>
void testWithBuffer(LinkedList<T> &ll);

template <class T>
void testWithoutBuffer(LinkedList<T> &ll);

int main(){
	LinkedList<int> ll(5);
	ll.append(4);
	ll.append(10);
	ll.append(5);
	ll.append(5);
	ll.append(7);
	ll.append(8);
	ll.append(7);
	ll.append(7);

	LinkedList<int> ll2(1);
	ll2.append(2);
	ll2.append(3);
	ll2.append(3);

	testWithBuffer<int>(ll);
	testWithBuffer<int>(ll2);
	
	LinkedList<int> ll3(4);
	ll3.append(4);
	ll3.append(10);
	ll3.append(5);
	ll3.append(5);
	ll3.append(7);
	ll3.append(8);
	ll3.append(7);
	ll3.append(7);
	testWithoutBuffer<int>(ll3);

	LinkedList<int> ll4(4);
	testWithBuffer(ll4);

	return 0;
}

template <class T>
void testWithBuffer(LinkedList<T> &ll){
	std::cout << "Before deletion" << std::endl;	
	std::cout << ll << std::endl;
	removeDuplicatesWithBuffer(ll);

	std::cout << "After deletion" << std::endl;	
	std::cout << ll << std::endl;
}

template <class T>
void testWithoutBuffer(LinkedList<T> &ll){
	std::cout << "Before deletion" << std::endl;	
	std::cout << ll << std::endl;
	removeDuplicatesWithoutBuffer(ll);

	std::cout << "After deletion" << std::endl;	
	std::cout << ll << std::endl;
}

template<class A, class B>
void printMap(std::map<A, B> map){
	std::cout << "{" << std::endl;
	for(auto &elem : map){
		std::cout << elem.first << " : " << elem.second << "," <<  std::endl;
	}
	std::cout << "}" << std::endl;
}

template <class T>
void removeDuplicatesWithBuffer(LinkedList<T> &ll){

	// Store counts for linked list data members 
	std::map<int, int> duplicateMap;
	Node<T> *tmp= ll.getHead();
	while(tmp){
		int key = tmp->data;
		if(duplicateMap.find(key) == duplicateMap.end()){
			duplicateMap[key] = 0;
		}
		duplicateMap[key] += 1; 
		
		tmp = tmp->next;
		
	}
	//printMap(duplicateMap);
	
	// Remove any linked list nodes with counts higher than 1
	tmp = ll.getHead();
	while(tmp && tmp->next){
		int key = tmp->next->data;
		if(duplicateMap[key] > 1){
			Node<T> *toDelete = tmp->next;
			tmp->next = toDelete->next;
			delete toDelete;
			duplicateMap[key] -= 1;
		}else{
			tmp = tmp->next;
		}
	}
	//printMap(duplicateMap);

}

template <class T>
void removeDuplicatesWithoutBuffer(LinkedList<T> &ll){
	Node<T> *tmp = ll.getHead();
	Node<T> *tmp2 = 0;
	if(tmp){
		tmp2 = ll.getHead();
	}else{
		std::cout << "List empty" << std::endl;
		return;
	}

	// Compare a node, to all nodes following it
	// Delete any duplicates
	// Move onto next node 
	while(tmp){
		while(tmp2 && tmp2->next){
			if(tmp->data == tmp2->next->data){
				Node<T> *toDelete = tmp2->next;
				tmp2->next = toDelete->next;
				delete toDelete;
			}else{
				tmp2 = tmp2->next;
			}
			
		}

		tmp = tmp->next;
		tmp2 = tmp;
	}
}
/*
 * Solution:
 * 	a -> b -> c -> c -> NULL
 *
 * 	Our goal is to remove duplicates from an unsorted list
 *
 * 	Without a buffer we can:
 * 		- compare a node to all nodes after it
 * 		- once we see a duplicate remove it
 * 		- repeat this for all nodes until end of list
 * 		- [O(n^2) time]
 *
 * 	With a buffer [O(n) time and space]
 * 		- go through list in O(n) time
 * 		- store list of counts for each key (number of duplicates)
 * 		- go through list again and delete values until counts are 1
 *
 */


