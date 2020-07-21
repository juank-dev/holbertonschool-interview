#!/usr/bin/python3


def canUnlockAll(boxes):
    """Lockboxes Holberton Interview"""
    num_box = 0
    keys = {0}
    if boxes is None:
        return False
    for x in boxes:
        if num_box not in keys:
            return False
        for y in x:
            keys.add(y)
        num = 0
        for w in boxes:
            if num in keys:
                for z in w:
                    keys.add(z)
            num += 1
        num_box += 1
    return True
