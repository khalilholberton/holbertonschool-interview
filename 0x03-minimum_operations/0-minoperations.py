#!/usr/bin/python3
"""
This module contains the func minOperations(n)
"""


def minOperations(n):
    """
    method that calculates the fewest number
    of operations needed to result in
    exactly n H characters in the file
    """

    num_H = 1
    counter = 0
    cp = 1

    if n < 2 or type(n) is not int:
        return 0

    while (n != num_H):
        if (n % num_H == 0):
            cp = num_H
            num_H *= 2
            counter += 2
        else:
            counter += 1
            num_H = num_H + cp

    return counter
