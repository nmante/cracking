#!/usr/bin/env python
from __future__ import print_function
import argparse

"""
     example
"""

def create_parser():
    parser = argparse.ArgumentParser()
    return parser

def bfs(graph, start, end):
    queue = [[start]]
    visited = set()

    while queue:
        # Gets the first path in the queue
        path = queue.pop(0)

        # Gets the last node in the path
        vertex = path[-1]

        # Checks if we got to the end
        if vertex == end:
            return path
        # We check if the current node is already in the visited nodes set in order not to recheck it
        elif vertex not in visited:
            # enumerate all adjacent nodes, construct a new path and push it into the queue
            for current_neighbour in graph.get(vertex, []):
                new_path = list(path)
                new_path.append(current_neighbour)
                queue.append(new_path)

            # Mark the vertex as visited
            visited.add(vertex)


def main():
    parser = create_parser()
    args = parser.parse_args()
    graph = {
        1: [2, 3, 4],
        2: [5, 6],
        3: [10],
        4: [7, 8],
        5: [9, 10],
        7: [11, 12],
        11: [13]
    }
    print(bfs(graph, 1, 13))

if __name__ == "__main__":
    main()
