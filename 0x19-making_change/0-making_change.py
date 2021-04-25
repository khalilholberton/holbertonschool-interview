#!/usr/bin/python3
'''
Fun makeChange
'''


def makeChange(coins, total):
    ''' Def make change '''
    if total <= 0:
        return 0
    ref = [total + 1]
    tot = (total + 1)
    res = ref * tot
    res[0] = 0
    try:
        for a in range(1, total + 1):
            for b in range(0, len(coins)):
                if coins[b] <= a:
                    res[a] = min(res[a], res[a - coins[b]] + 1)
        return -1 if res[total] > total else res[total]
    except:
        pass
