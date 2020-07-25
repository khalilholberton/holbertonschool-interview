#!/usr/bin/python3
"""
def canUnlockAll()
"""


def canUnlockAll(boxes):
    """
    Return True if all boxes can be opened, else return False
    """
    if type(boxes) is not list:
        return False
    if len(boxes) == 0:
        return False
    keys = boxes[0]
    for i in range(1, len(boxes)):
        if i in keys:
            keys += boxes[i]
    for i in range(len(boxes)):
        if i in keys:
            return True
        else:
            return False
