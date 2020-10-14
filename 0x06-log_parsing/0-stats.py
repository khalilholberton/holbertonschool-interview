#!/usr/bin/python3
"""
script that reads stdin line by line and computes metrics
"""


from sys import stdin

status = {'200': 0, '301': 0,
          '400': 0, '401': 0,
          '403': 0, '404': 0,
          '405': 0, '500': 0}
codes = ['200', '301',
         '400', '401',
         '403', '404',
         '405', '500']
y = 0
counter = 0

try:
    for line in stdin:
        counter = counter + 1
        coll = line.split(" ")
        sz = len(coll)
        if sz > 2:
            y = y + int(coll[-1])
            if coll[-2] in status:
                status[coll[-2]] = status[coll[-2]] + 1

        if counter % 10 == 0:
            print("File size: {}".format(y))
            for code in codes:
                if status[code]:
                    print("{}: {}".format(code, status[code]))
except Exception:
    pass
finally:
    print("File size: {}".format(y))
    for a, b in sorted(status.items()):
        if b != 0:
            print("{}: {}".format(a, b))
