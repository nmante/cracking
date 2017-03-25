#!/usr/bin/env python
from __future__ import print_function
import argparse

"""
     example
"""

def create_parser():
    parser = argparse.ArgumentParser()
    parser.add_argument('-n', '--nums', nargs='+', type=int, default=[1, 3, 4], help='A list of integers. The parentheses combination will be printed for each integer')
    return parser

def printParentheses(count):
    if count < 0:
        return
    parens = [' ' for i in range(2*count)]
    _printParentheses(count, count, parens, 0) 


def _printParentheses(leftRemaining, rightRemaining, paren_list, count):
    if leftRemaining < 0 or leftRemaining > rightRemaining:
        return

    if leftRemaining == 0 and rightRemaining == 0:
        print(''.join(paren_list))
    else:
        if leftRemaining > 0:
            paren_list[count] = '('
            _printParentheses(leftRemaining - 1, rightRemaining, paren_list, count + 1)
        if rightRemaining > leftRemaining:
            paren_list[count] = ')'
            _printParentheses(leftRemaining, rightRemaining - 1, paren_list, count + 1)

def driver(nums_list):
    for num in nums_list:
        print("==============")
        print("Count: " + str(num))
        printParentheses(num)
        print("==============")

def main():
    parser = create_parser()
    args = parser.parse_args()
    driver(args.nums)

if __name__ == "__main__":
    main()
