#!/usr/bin/python3
"""The N queens puzzle is the challenge of placing N
non-attacking queens on an N×N chessboard.
Write a program that solves the N queens problem."""

import sys
import math

"""Validation"""
if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)

try:
    number = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    exit(1)

if number < 4:
    print("N must be at least 4")
    exit(1)


def solveBoard(board, row, rowmask, ldmask, rdmask):

    n = len(board)

    """ All_rows_filled is a bit mask
        having all N bits set """
    all_rows_filled = (1 << n) - 1

    """ If rowmask will have all bits set, means
     queen has been placed successfully
     in all rows and board is diplayed"""
    if (rowmask == all_rows_filled):
        printAxis(board)

    safe = all_rows_filled & (~(rowmask | ldmask | rdmask))

    while (safe > 0):

        p = safe & (-safe)
        col = (int)(math.log(p)/math.log(2))
        board[row][col] = 1

        solveBoard(board, row+1, rowmask | p,
                   (ldmask | p) << 1, (rdmask | p) >> 1)

        safe = safe & (safe-1)

        board[row][col] = 0


def printAxis(board):
    """all position board is diplayed"""
    my_list = list()
    x, y = 0, 0
    for row in board:
        for col in row:
            if col == 1:
                my_list.append([x, y])
            y += 1
        y = 0
        x += 1
    print(my_list)


def nqueens(size):
    """N queens puzzle, create board N * size"""
    n = size
    board = []

    for i in range(n):
        row = []
        for j in range(n):
            row.append(0)
        board.append(row)

    rowmask = 0
    ldmask = 0
    rdmask = 0
    row = 0

    solveBoard(board, row, rowmask, ldmask, rdmask)


"""function N Queens"""
nqueens(number)
