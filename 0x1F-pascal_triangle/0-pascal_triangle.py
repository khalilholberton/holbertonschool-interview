#!/usr/bin/python3
'''
pascal trinagle
'''


def pascal_triangle(g):
    '''pascal trinagle'''

    if g <= 0:
        return []

    ind = [[1]]
    if g == 1:
        return p

    try:
        for a in range(1, g):
            neg = -1
            s = 0
            h = []
            for ctr in range(a+1):
                res = 0
                if neg > -1:
                    res += ind[a - 1][neg]
                if s < a:
                    res += ind[a - 1][s]
                neg += 1
                s += 1
                h.append(res)
            ind.append(h)
        return ind
    except:
        pass
