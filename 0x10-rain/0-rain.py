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
        z, tmp = 1, 0
        while y < len(walls) - 1:
            if walls[x] <= walls[y]:
                store = (walls[x] * z) - sum(walls[x + 1:y])
                rain += store
                tmp = 0
                break
            else:
                tmp += 1
                if walls[y] > 0:
                    max = walls[y]
            y += 1
            z += 1
        if tmp:
            rain += (max * tmp - 1)
        x = y - 1
    return rain
