#!/usr/bin/env python
"""
    Write a method to replace all spaces in a string with '%20'

    Solution:
        Iterate through entire string
        When we see a character that's a space,
        place three new characters %20 in it's place
        
        Possible mishap: As we go through we increase length of string
            keep track of how many times we've inserted

        hello world

        hello%20world <- updated reference of word

        handle cases with space at beginning and end of string
"""

def replaceSpaces(word):

    numInsertions = 0
    for i, char in enumerate(word):
        if char == ' ':
            # End of string
            index = i + 2*numInsertions
            if index < len(word) - 1:
                word = word[:index] + "%20" + word[index+1:] 
            elif index == len(word) - 1:
                word = word[:index] + "%20" 
            elif index == 0:
                word = "%20" + word[1:]

            numInsertions += 1

    return word

def test(word):
    print "Original text: " + word
    print "Replaced text: " + replaceSpaces(word)

def main():
    test("hello world")
    test(" hello")
    test(" hello ")
    test(" hello world ")

if __name__ == "__main__":
    main()
