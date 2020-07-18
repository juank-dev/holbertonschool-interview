#!/usr/bin/python3


def canUnlockAll(boxes):
    """Lockboxes Holberton Interview"""
    num_box = 0
    keys = {0}
    for x in boxes:
        for y in x:
            keys.add(y)
        num = 0
        for w in boxes:
            if num in keys:
                for z in w:
                    keys.add(z)
            num += 1
        if num_box not in keys:
            return False
        num_box += 1
    return True
