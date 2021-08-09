#!/usr/bin/python3
"""Task 0 Pascal's Triangle """


def pascal_triangle(n):
    """ Returns a list of lists of integers
    representing the Pascal's triangle of n
    """
    integerList = []
    if n <= 0:
        return integerList

    integerList = [[1]]
    if n == 1:
        return integerList

    for row in range(1, n):
        left = -1
        right = 0
        listInt = []
        for column in range(row+1):
            integer = 0
            if left > -1:
                integer += integerList[row - 1][left]
            if right < row:
                integer += integerList[row - 1][right]
            left += 1
            right += 1
            listInt.append(integer)
        integerList.append(listInt)
    return integerList