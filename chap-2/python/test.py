#!/usr/bin/env python
from linkedlist import LinkedList

def main():
    ll = LinkedList(4)
    ll.append(5)
    print ll
    node = ll.find(5)
    print node


if __name__ == "__main__":
    main()
