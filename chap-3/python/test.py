#!/usr/bin/env python

from queue import Queue
from stack import Stack

def main():
    q = Queue(5)
    q.enqueue(7)
    q.enqueue(10)

    print "Queue after enqueues: " + str(q)

    n = q.dequeue()
    print "Node dequeued: " + str(n)
    print "Queue after dequeue: " + str(q)

    s = Stack(3)
    s.push(7)
    s.push(9)
    s.push(25)

    print "Stack after enqueues: " + str(s)
    n2 = s.pop()

    print "Node popped: " + str(n2)
    print "Stack after dequeues: " + str(s)

if __name__ == "__main__":
    main()
