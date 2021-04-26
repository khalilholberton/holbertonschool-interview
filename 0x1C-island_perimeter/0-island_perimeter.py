#!/usr/bin/python3
'''
island perimeter
'''


def island_perimeter(grid):
    '''island_perimeter'''
    if not grid:
        return 0
    s = 0
    try:
        for frt in range(len(grid)):
            for sec in range(len(grid[frt])):
                if grid[frt][sec] == 1:
                    if frt == 0 or grid[frt - 1][sec] == 0:
                        s += 1
                    if sec == 0 or grid[frt][sec - 1] == 0:
                        s += 1
                    if frt == len(grid) - 1 or grid[frt + 1][sec] == 0:
                        s += 1
                    if sec == len(grid[frt]) - 1 or grid[frt][sec + 1] == 0:
                        s += 1
        return s
    except:
        pass
