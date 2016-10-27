"""
    Linked List implementation
    Nii Mante
"""
from node import Node 

class LinkedList:

    def __init__(self, data=None):
        self.head = Node(data) 

    def __repr__(self):
        current = self.head
        out_str = "" 
        while current:
            out_str = out_str + str(current.get_data()) + " -> "
            current = current.get_next()

        out_str = out_str + " NULL"
        return out_str

    def __str__(self):
        current = self.head
        out_str = "" 
        while current:
            out_str = out_str + str(current.get_data()) + " -> "
            current = current.get_next()

        out_str = out_str + " NULL"
        return out_str


    def get_head(self):
        return self.head

    def prepend(self, data):
        """
            Add node to beginning of linked list
        """
        node = Node(data)
        node.set_next(self.head)
        self.head = node

    def append(self, data):
        """
            Add node to end of linked list
        """
        node = Node(data)
        current = self.head
        while current:
            if current.get_next() == None:
                current.set_next(node)
                break
            current = current.get_next()

    def find(self, data):
        """
            Search the linked list for a node with a matching
            Return the matching node
        """
        current = self.head
        while current:
            if current.get_data() == data:
                return current
            current = current.get_next()

        if current == None:
            print "Data: '" + data + "' is not in list."

        return None

    def delete(self, data):
        """
            Search the list for a node with matching data member,
            then remove it from the list
        """
        previous = None 
        current = self.head 
        deleted = False
        while previous:
            if current.get_data() == data:
                deleted = True 
                # Beginning of the list
                if previous == None:
                    self.head = current.get_next()
                else:
                    previous.set_next(current.get_next())

            previous = current
            current = current.get_next()

        if deleted == False:
            print "Item not deleted. '" + data + "' is not in the list"


    def size(self):
        current = self.head
        size = 0
        while current:
            size += 1
            current = current.get_next()

        return size



