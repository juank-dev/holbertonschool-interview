#!/usr/bin/python3
"""
Validate UTF-8
"""


def validUTF8(data):
    """
    validate UTF-8
    """
    for number in range(len(data)):
        tmp_num = data[number]
        tmp = tmp_num >> 7

        if (int("{0:b}".format(tmp)) == 0):
            continue
        tmp = tmp_num >> 5
        if(int("{0:b}".format(tmp)) == 110):
            tmp = data[number + 1] >> 6
            if(int("{0:b}".format(tmp)) == 10):
                number += 1
                continue
            else:
                return('False')
        tmp = tmp_num >> 4
        if(int("{0:b}".format(tmp)) == 1110):
            tmp = int("{0:b}".format(data[number + 1] >> 6))
            tmp_2 = int("{0:b}".format(data[number + 2] >> 6))
            if tmp == 10 and tmp_2 == 10:
                number += 2
                continue
            else:
                return('False')
        tmp = tmp_num >> 3
        if(int("{0:b}".format(tmp)) == 11110):
            tmp = int("{0:b}".format(data[number + 1] >> 6))
            tmp_2 = int("{0:b}".format(data[number + 2] >> 6))
            tmp_3 = int("{0:b}".format(data[number + 3] >> 6))

            if tmp == 10 and tmp_2 == 10 and tmp_3 == 10:
                number += 3
                continue
            else:
                return('False')
    return('True')
