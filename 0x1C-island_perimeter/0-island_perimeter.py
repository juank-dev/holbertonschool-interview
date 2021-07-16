#!/usr/bin/python3
"""Task 0x1c island_perimeter function """


def island_perimeter(grid):
    """  returns the perimeter  """

    def edges(matrix):
        """ detect number of edges"""
        count = 0
        for row in matrix:
            row = [0] + row + [0]
            for i in range(1, len(row)):
                count += row[i] != row[i-1]
        return count

    gridTwo = [[] for _ in range(len(grid[0]))]
    for row in grid:
        for i, item in enumerate(row):
            gridTwo[i].append(item)

    return edges(grid) + edges(gridTwo)