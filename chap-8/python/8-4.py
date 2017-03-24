#!/usr/bin/env python
from __future__ import print_function
import argparse

"""
     example
"""

def create_parser():
    parser = argparse.ArgumentParser()
    parser.add_argument('-w', '--words', nargs='+', help="A list of space separated words to generate permutations for")
    return parser

def permutations(word):

    def permutationsHelper(w):
        size = len(w)
        if size == 0:
            return [""] 
        perms = [] 
        for i in range(0, size):
            temps = [w[i] + res for res in permutationsHelper(w[:i] + w[i+1:])]
            for temp in temps:
                perms.append(temp)
        return perms

    gPerms = permutationsHelper(word)
    print("Number of Permutations: " + str(len(gPerms)))
    for perm in gPerms:
        print(perm)


def driver(words):
    
    for word in words:
        print("=====================")
        permutations(word)
        print("=====================")

def main():
    parser = create_parser()
    args = parser.parse_args()
    if args.words and len(args.words) > 0:
        driver(args.words)
    else:
        driver(["abc", "hello"])
    

if __name__ == "__main__":
    main()
