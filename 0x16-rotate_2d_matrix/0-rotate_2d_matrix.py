#!/usr/bin/python3
'''
This module contains the function rotate_2d_matrix
'''


def rotate_2d_matrix(matrix):
    '''
    rotate two dimension matrix 90 degrees clockwise
    '''
    rot = matrix[::-1]
    matZ = zip(*rot)
    rixL = [list(elem) for elem in matZ]

    for a, b in enumerate(rixL):
        matrix[a] = rixL[a]
