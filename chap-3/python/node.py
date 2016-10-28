"""
    Nii Mante
    Node implementation in Python
"""

class Node:
    def __init__(self, data=None, next_node=None):
        self.data = data
        self.next_node = next_node

    def __repr__(self):
        return 'Node data: (%d) Next Address: %s' % (self.data, hex(id(self.next_node)))

    def __str__(self):
        return 'Node data: (%d) Next Address: %s' % (self.data, hex(id(self.next_node)))

    def get_next(self):
        """
            Return the next node
        """
        return self.next_node

    def get_data(self):
        """
            Return the data member
        """
        return self.data

    def set_next(self, next_node):
        """
            Set the next node
        """
        self.next_node = next_node


