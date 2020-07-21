#!/usr/bin/python3


def canUnlockAll(boxes):
    """Lockboxes Holberton Interview"""
    num_box = 0
    keys = [0]
    if boxes is None or boxes == []:
        return False
    for x in boxes:
        if num_box not in keys:
            return False
        for y in x:
            if y < len(boxes):
                keys.append(y)
        for w in keys:
            for z in boxes[w]:
                if z not in keys:
                    if z < len(boxes):
                        keys.append(z)
        num_box += 1
    return True
