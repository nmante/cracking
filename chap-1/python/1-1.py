"""
    Implement an algorithm to determine if a string has all unique characters

    - Have to examine each character no matter what solution [ O(n) ]
    - Purely alphabetical, or can they be numerical as well?

    Consider character sets (ASCII)

    Solution 1:
        - store occurrences of existing characters
        - keep a count for characters we've seen
        - If at any point we experience a count above 1, then we know that the string 
        isn't all unique characters

        - we're using a data structure to store counts
            - could use an array where each index corresponds to character
            - be better to use dictionary/hash where keys are letters/characters
            - values are counts

    Solution 2:
        - Compare each letter to all other n letters
        - At worst [ O(n^2) ]

    Solution 3:
        - Take the string
        - Sort the letters [ O(nlogn) ] 
        - We can iterate through the letters in O(n) 
        - if letters at index i == index i+1 then characters aren't unique

    
"""
import argparse

def hash_solution(word):

    # Create a structure to hold counts
    char_counts = {}
    
    for char in word:
        if char in char_counts:
            print(char + " is already present in word: " + word)
            return False
        else:
            char_counts[char] = 1

    print("All characters are unique in word: " + word)
    return True

def sort_solution(word):
    sorted_word = ''.join(sorted(word))
    print("Sorted word is: " + sorted_word)

    for i in range(0, len(sorted_word) - 1):
        char = sorted_word[i]
        char_next = sorted_word[i+1]
        if char == char_next:
            print(char + " is already present in word: " + word)
            return False

    print("All characters are unique in word: " + word)
    return True


def test():
    print("Hash solution Tests") 
    hash_solution("aab")
    hash_solution("hell")
    hash_solution("car")
    hash_solution("main")

    sort_solution("aab")
    sort_solution("hell")
    sort_solution("car")
    sort_solution("main")


def main():
    test()

if __name__ == "__main__":
    main()


