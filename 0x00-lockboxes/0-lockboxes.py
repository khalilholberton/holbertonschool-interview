#!/usr/bin/python3
"""
def canUnlockAll()
"""


def canUnlockAll(boxes):
    """
    Return True if all boxes can be opened, else return False
    """
    try:
        ky = boxes[0]
        f_level = range(1, len(boxes))
        for count in f_level:
            if count in ky:
                ky = ky + boxes[count]
        try:
            for count in range(1, len(boxes)):
                if count in ky:
                    ky = ky + boxes[count]
                    list(set(ky))
                    x = 1
        except Exception:
            pass
        s_level = range(1, len(boxes)-1)
        for count in s_level:
            if count not in ky:
                x = 0
        if x == 1:
            return True
        else:
            return False
    except Exception:
        pass
