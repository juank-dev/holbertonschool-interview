#!/usr/bin/python3
"""Log parsing Write a script that reads stdin line by
    line and computes metrics"""

import sys

size, count = 0, 0
var200, var301, var400, var401 = 0, 0, 0, 0
var403, var404, var405, var500 = 0, 0, 0, 0
my_dict = {"200": var200, "301": var301, "400": var400, "401": var401,
           "403": var403, "404": var404, "405": var405, "500": var500}

if __name__ == '__main__':
    try:
        for line in sys.stdin:
            word = line.split()
            size += int(word[-1])
            if count == 10:
                print("File size: {}".format(size))
                for status, variable in my_dict.items():
                    if variable != 0:
                        print("{}: {}".format(status, variable))
                count = 0
            for status in my_dict.keys():
                if (word[-2] == status):
                    my_dict[status] += 1

            count += 1
    except KeyboardInterrupt:
        print("File size: {}".format(size))
        for status, variable in my_dict.items():
            if variable != 0:
                print("{}: {}".format(status, variable))
        exit(0)
