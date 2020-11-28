#!/usr/bin/python3
"""
Project: Rain
"""


def validation(new_list: list) -> list:
    """Validate a list"""
    count = False
    first_list = []
    for x in new_list:
        if x <= 0 and count is False:
            continue
        first_list.append(x)
        count = True
    
    count = False
    second_list = []
    for y in reversed(first_list):
        if x <= 0 and count is False:
            continue
        second_list.append(x)
        count = True
    return second_list


def rain(walls):
    """Function: Calculate  how much water will be retained
    after it rains.
    """
    if len(walls) == 0:
        return 0

    count = 0
    maximo = max(walls)
    rain = 0
    for x in range(maximo):
        new_list = validation(walls)

        for w in new_list:
            if w <= 0:
                rain += 1
        walls = [element - 1 for element in new_list]
    return rain
