#!/usr/bin/python3
"""
This module contains : def rain ()
"""


def rain(walls):
    """ rain
    """
    if not walls:
        return 0

    if len(walls) < 1:
        return 0

    r = 0
    l_walls = len(walls)

    for ctr in range(l_walls):
        left_limit = walls[ctr]
        for idx in range(ctr):
            left_limit = max(left_limit, walls[idx])
        right_limit = walls[ctr]

        for idx in range(ctr + 1, l_walls):
            x = walls[idx]
            right_limit = max(right_limit, x)
        res = min(left_limit, right_limit)
        r += res - walls[ctr]

    return r
