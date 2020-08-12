#!/usr/bin/python3
"""
In a text file, there is a single character H. Your text editor can
execute only two operations in this file: Copy All and Paste. Given
a number n, write a method that calculates the fewest number of operations
 needed to result in exactly n H characters in the file.
"""


def minOperations(n):
    """function that validate the number of Minimum Operations"""
    copy = 1
    count = 0
    minimo = []
    if n < 2:
        return 0
    for paste in range(1, n):
        count = 0
        copy = 1
        for number in range(n):
            if n == copy:
                minimo.append(count)
                break
            if copy > n:
                count -= paste + 1
                copy -= copy/(paste + 1) * paste
                copy += paste
                count += 1
                continue
            copy += copy * paste
            count += paste + 1
    return(min(minimo))
