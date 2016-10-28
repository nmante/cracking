"""
    Nii Mante
    Stack implementation
"""

from node import Node

class Stack:

    def __init__(self, data):
        self.top = Node(data)


    def __str__(self):
        tmp = self.top
        out_str = "Stack\n"
        out_str = out_str + "====\n"
        while tmp:
            out_str = out_str + str(tmp.data) + "\n" 
            tmp = tmp.next_node

        out_str = out_str + "\n====\n"
        return out_str   

    def pop(self):
        if self.top:
            result = self.top
            self.top = self.top.next_node
            return result

        return None


    def push(self, data):
        new_node = Node(data)
        new_node.next_node = self.top
        self.top = new_node

