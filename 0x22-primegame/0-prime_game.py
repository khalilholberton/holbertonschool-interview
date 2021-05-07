#!/usr/bin/python3
"""
def Game module
"""


def isWinner(x, nums):
    """def game winner"""
    if not nums or x < 1:
        return None
    n = max(nums)
    find = [True for _ in range(max(n + 1, 2))]
    for k in range(2, int(pow(n, 0.5)) + 1):
        if not find[k]:
            continue
        for l in range(k * k, n + 1, k):
            find[l] = False
    find[0] = find[1] = False
    a = 0
    for k in range(len(find)):
        if find[k]:
            a += 1
        find[k] = a
    player = 0
    for n in nums:
        player += find[n] % 2 == 1
    if player * 2 == len(nums):
        return None
    if player * 2 > len(nums):
        return "Maria"
    return "Ben"