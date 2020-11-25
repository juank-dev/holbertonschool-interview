#!/usr/bin/python3
"""
Project: Rain
"""


def rain(walls):
    """Function: calculate how much water will be retained
    after it rains.
    """
    if len(walls) == 0:
        return 0
    x, rain, count = 0, 0, 0
    walls.append(0)
    walls.append(0)

    while x < len(walls) - 1:
        if walls[x] <= walls[x + 1]:
            x += 1
            continue
        y = x + 2
        z = 1
        while y < len(walls) - 1:
            if walls[x] <= walls[y]:
                store = (walls[x] * z) - sum(walls[x + 1:y])
                rain += store
                break
            y += 1
            z += 1
        x += y - 1
    return rain
