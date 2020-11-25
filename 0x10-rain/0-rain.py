#!/usr/bin/python3
"""
Project: Rain
"""

def validation(new_list: list):
    """Validate a list"""
    count = 0
    first_list = []
    for x in new_list:
        if x > 0 or count != 0:
            first_list.append(x)
            count += 1
    count = 0
    second_list = []
    for y in reversed(first_list):
        if y > 0 or count != 0:
            second_list.append(y)
            count += 1
    return second_list

def rain(walls):
    """Function: Calculate how much water will be retained
    after it rains.
    """
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
