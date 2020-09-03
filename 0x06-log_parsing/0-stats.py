#!/usr/bin/python3
import sys
from signal import signal, SIGINT


def handler(signal_received, frame):
    """Signal"""
    print('SIGINT or CTRL-C detected. Exiting gracefully')
    exit(0)


signal(SIGINT, handler)

size, count = 0, 1
var200, var301, var400, var401 = 0, 0, 0, 0
var403, var404, var405, var500 = 0, 0, 0, 0
my_dict = {"200": var200, "301": var301, "400": var400, "401": var401,
           "403": var403, "404": var404, "405": var405, "500": var500}


for line in sys.stdin:
    word = line.split()
    size += int(word[-1])
    if count == 10:
        print("File size: {}".format(size))
        for status, variable in my_dict.items():
            if variable != 0:
                print("{}: {}".format(status, variable))
        count = 1
    for status in my_dict.keys():
        if (word[-2] == status):
            my_dict[status] += 1

    count += 1