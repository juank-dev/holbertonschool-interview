#!/usr/bin/python3
import sys
from signal import signal, SIGINT
size, count = 0, 1


signal(SIGINT, handler)
var200, var301, var400, var401, var403, var404, var405, var500 = 0, 0, 0, 0, 0, 0, 0, 0
status_list = [var200, var301, var400, var401, var403, var404, var405, var500]
for line in sys.stdin:
    word = line.split()
    size += int(word[-1])
    if count == 10:
        print("File size: {}".format(size))
        if var200 != 0:
            print("200: {}".format(var200))
        if var301 != 0:
            print("301: {}".format(var301))
        if var400 != 0:
            print("400: {}".format(var400))
        if var401 != 0:
            print("401: {}".format(var401))
        if var403 != 0:
            print("403: {}".format(var403))
        if var404 != 0:
            print("404: {}".format(var404))
        if var405 != 0:
            print("405: {}".format(var405))
        if var500 != 0:
            print("500: {}".format(var500))
        count = 1
    if (int(word[-2]) == 200):
        var200 += 1
    elif (int(word[-2]) == 301):
        var301 += 1
    elif (int(word[-2]) == 400):
        var400 += 1
    elif (int(word[-2]) == 401):
        var401 += 1
    elif (int(word[-2]) == 403):
        var403 += 1
    elif (int(word[-2]) == 404):
        var404 += 1
    elif (int(word[-2]) == 405):
        var405 += 1
    elif (int(word[-2]) == 500):
        var500 += 1

    count += 1
