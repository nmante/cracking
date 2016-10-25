#Linked Lists

[source](https://www.cs.cmu.edu/~adamchik/15-121/lectures/Linked%20Lists/linked%20lists.html)

##Intro

Linked lists are datastructures that contain a data item as well as a pointer to the next item in the list. This data item and pointer combination is referred to as a Node.

![image](images/linked-list.png)

###Useful facts
- **Head:** Entry point of linked list 
- **Tail:** Last node of linked list (has next pointing to *null*)
- It's a dynamic data structure, not fixed size

###Types of Linked Lists

- Singly linked (figure above)
- Doubly linked - contain links to *previous* and *next* nodes

![image](images/doubly-linked-list.png)

###The classes

As mentioned before linked lists contain nodes

- Python

		class Node:
			def __init__(self, data=None, next=None):
				self.data = data
				self.next = next
- C++

		template
		class Node<T>{
		private:
			T data;
			Node<T> *next;
		
		public:
			Node<T>(T dat){ data = dat; }
			Node<T>(T dat, Node<T> *node){
				data = dat;
				next = node;
			}
			~Node<T>(){ next = NULL; }
			Node<T> *getNext(){ return next; }
			T getData(){ return data; }
			void setNext(Node<T>* _next){ next = _next; } 
		};
		
The code above is the base for creating a linked list node. There are other methods that we can define for doing operations on the list.

- addFirst/prepend
- traverse
- addLast/append
- insertAfter
- insertBefore
- Delete
- shallow/deep copying

##Applications

What's the point in linked lists?

- Polynomial Algebra
- Can be used to implement stacks, queues
- Can be used for chaining in hash tables
- Operating systems use them for process queues, waiting queues
- Sparse matrices
- more,


