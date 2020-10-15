#!/usr/bin/python3
"""
This module conatins the function validUTF8
"""


def validUTF8(data):
    """validUTF8"""
    val = 0
    for y in data:
        x = 1 << 7
        if not val:
            while x & y:
                val = val + 1
                x >>= 1
            if not val:
                continue
            try:
                if val == 1 or val > 4:
                    return False
            except Exception:
                pass
        else:
            try:
                if y >> 6 != 0b10:
                    return False
            except Exception:
                pass

        val = val - 1
    return val == 0
