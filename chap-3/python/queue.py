"""
    Nii Mante
    Queue implementation 
"""
from node import Node

class Queue:
    def __init__(self, data = None):
        if data:
            self.first = Node(data)
            self.last = self.first
        else:
            self.first = None
            self.last = None

    def __str__(self):
        tmp = self.first
        out_str = "Queue\n"
        out_str = out_str + "====\n"
        while tmp:
            out_str = out_str + str(tmp.data) + "\n"
            tmp = tmp.next_node

        out_str = out_str + "\n====\n"
        return out_str
            

    def enqueue(self, data):
        """
            Push an item to the end of the queue
        """
        if self.last:
            self.last.next_node = Node(data)
        else:
            self.last = Node(data)

    def dequeue(self):
        """
            Pop an item from the beginning of the queue
        """
        result_node = Node(self.first.data) 
        self.first = self.first.next_node
        return result_node
