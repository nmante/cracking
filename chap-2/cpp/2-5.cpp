#include <iostream>
#include "ll/linkedlist.hpp"
#include <map>

/*
 * Dictionary Solution Start time: 358pm
 * Dictionary Solution End time: 415pm 
 *
 * Two runners solution start: 419pm
 * Two runners solution end: 
 *
 * 
 * Problem: Given a circular linked list implement an algorithm which returns
 * a node at the beginning of the loop
 *
 * Definition:
 * 	Circular linked list: A (corrupt) linked list in which a node's net pointer points 
 * 	to an earlier node; this leads to a loop in the list
 *
 * Example:
 * 	Input: A -> B -> C -> D -> E -> C [same C from earlier]
 * 	Output: C
 */

template <class T>
Node<T> *returnLoopNode(LinkedList<T> &ll);

template <class T>
Node<T> *returnLoopNodeNoBuffer(LinkedList<T> &ll);

int main(){
	LinkedList<int> ll(5);
	ll.append(6);
	ll.append(7);
	ll.append(8);
	ll.append(9);
	ll.append(10);

	Node<int> *head = ll.getHead();
	Node<int> *tail = ll.find(10);
	tail->next = head->next->next->next;

	Node<int> *loopNode = returnLoopNode(ll);

	std::cout << "Loop Node" << std::endl;
	std::cout << loopNode << std::endl;
	std::string result = loopNode != 0 ? std::to_string(loopNode->data) : "No Loop";
	std::cout << result << std::endl;

	Node<int> *loopNode2 = returnLoopNodeNoBuffer(ll);

	std::cout << "Loop Node" << std::endl;
	std::cout << loopNode2 << std::endl;
	std::string result2 = loopNode2 != 0 ? std::to_string(loopNode2->data) : "No Loop";
	std::cout << result2 << std::endl;
	
	return 0;
}

template <class T>
Node<T> *returnLoopNode(LinkedList<T> &ll){
	Node<T> *current = ll.getHead();
	std::map<Node<T> *, int> nodeCountMap;


	while(current){
		if(nodeCountMap.find(current) == nodeCountMap.end()){
			nodeCountMap[current] = 0;
		}
		nodeCountMap[current] = nodeCountMap[current] + 1;
		if(nodeCountMap[current] > 1){
			return current;
		}
		current = current->getNext();
	}

	return 0;
}

template <class T>
Node<T> *returnLoopNodeNoBuffer(LinkedList<T> &ll){
	// Keep track of two pointers
	// One moves at a 'slow' speed (one node jump per loop)
	// The other moves at a 'fast' speed (two node jumps per loop)
	// Eventually, the nodes will intersect (their addresses will be equal)
	// When this happens, reset one of the nodes to the head
	// Then move the two at the same pace/speed
	// This intersection will be the loop start 
	
	Node<T> *runnerOne = ll.getHead();
	Node<T> *runnerTwo = ll.getHead();

	while(runnerOne && runnerTwo){
		runnerOne = runnerOne->next;
		runnerTwo = (runnerTwo->next == 0) ? 0 : runnerTwo->next->next;
		if(runnerOne == runnerTwo){
			break;
		}
	}

	// Either of these are null, then you can't have a loop 
	if(!runnerTwo || !runnerOne){
		return 0;
	}

	// Move one pointer back to the beginning of the list
	// Then move both pointers at an equal pace. They will intersect at
	// The loop start
	runnerOne = ll.getHead();
	while( runnerOne != runnerTwo){
		runnerTwo = runnerTwo->next;
		runnerOne = runnerOne->next;
	}
		
	return runnerTwo;
}

/*
 * Solution:
 * 	One possible solution
 * 	- Keep track of data members you've seen
 * 	- One further step (keep track of addresses you've seen)
 * 	- Duplicate addresses mean you've seen a loop
 * 	- The duplicate is the loop
 * 	- O(n) time, O(n) space
 *
 * 	Without extra buffer?
 * 	- You could use two pointers
 * 	- One pointer moves at 1 node per jump
 * 	- The other pointer moves at 2 nodes per jump
 * 	- If your pointers ever match, then you've got a cycle
 */




