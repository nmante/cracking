#!/usr/bin/env python
"""
Problem: design algorithm and write code to remove duplicate characters in a string
         without an extra buffer (one or two variables okay)

Solution:
        1. First detect duplicate characters
        2. Remove them in place (i.e. shift characters once done)

        Could possibly store indices of duplicates
        For each index move the character at index+1 over to left
        Special case (end of string) just collapse string don't look at next character

        "Hello World"

        If we want to do O(n), we need some sort of structure to store duplicates like a hash
        Or we can use bit vector

        current dup = l
        current index = 3

        what kind of variables (array, or just char/integer)


"""

def removeDuplicates(word):
    checker = 0
    num_shifts = 0
    print word
    for i in range(0, len(word)):
        i -= num_shifts
        num_shifts = 0
        if i >= len(word):
            break
        if word[i] == ' ':
            continue
        val = ord(word[i]) - ord('a')
        if (checker & (1 << val)) > 0:
            if i + 1 < len(word):
                word = word[:i] + word[i+1:] 
                num_shifts = 1
        checker |= (1 << val)

    print word


def main():
    removeDuplicates("hello")
    removeDuplicates("helloworld")

if __name__ == "__main__":
    main()

