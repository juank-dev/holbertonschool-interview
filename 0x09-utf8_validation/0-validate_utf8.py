#!/usr/bin/python3
"""
Validate UTF-8
"""


def validation(data, number, tmp, bytes):
    tmp_list = []
    try:
        for x in range(bytes):
            tmp_list.append(int("{0:b}".format(data[number + (x + 1)] >> 6)))

        for val in tmp_list:
            if val != 10:
                return(0)
        number += bytes
        return(number)
    except:
        return(-1)


def validUTF8(data):
    """
    validate UTF-8
    """
    for number in range(len(data)):
        tmp_num = data[number] & 255
        tmp = tmp_num >> 7

        if (int("{0:b}".format(tmp)) == 0):
            continue
        tmp = tmp_num >> 5
        if(int("{0:b}".format(tmp)) == 110):
            number = validation(data, number, tmp, 1)
            if number == -1 or number == 0:
                return('False')
            continue

        tmp = tmp_num >> 4
        if(int("{0:b}".format(tmp)) == 1110):
            number = validation(data, number, tmp, 2)
            if number == -1 or number == 0:
                return('False')
            continue

        tmp = tmp_num >> 3
        if(int("{0:b}".format(tmp)) == 11110):
            number = validation(data, number, tmp, 3)
            if number == -1 or number == 0:
                return('False')
            continue

    return('True')
