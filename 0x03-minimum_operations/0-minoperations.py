#!/usr/bin/python3
"""
In a text file, there is a single character H. Your text editor can
execute only two operations in this file: Copy All and Paste. Given
a number n, write a method that calculates the fewest number of operations
 needed to result in exactly n H characters in the file.
"""


def minOperations(n):
    """ Calculates the fewest number of operations needed
        to result in exactly n H characters in the file
    """
    count = 0
    copy = 1
    tmp = 0

    while copy < n:
        if n % copy == 0:
            tmp = copy
            copy *= 2
            count += 1
        else:
            copy += tmp
        count += 1
    return count
