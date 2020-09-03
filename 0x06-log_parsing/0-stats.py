#!/usr/bin/python3
"""Log parsing Write a script that reads stdin line by
    line and computes metrics"""

if __name__ == '__main__':
    import sys

    size, count = 0, 1

    my_dict = {"200": 0, "301": 0, "400": 0, "401": 0,
               "403": 0, "404": 0, "405": 0, "500": 0}

    try:
        """Validation computes metrics and print stadistics"""
        for line in sys.stdin:
            word = line.split()
            try:
                size += int(word[-1])
                for status in my_dict.keys():
                    if (word[-2] == status):
                        my_dict[status] += 1
                if count == 10:
                    print("File size: {}".format(size))
                    sorted(my_dict)
                    for status, variable in my_dict.items():
                        if variable != 0:
                            print("{}: {}".format(status, variable))
                    count = 0
            except:
                pass
            count += 1
    except KeyboardInterrupt:
        """Keyboard interrupt"""
        print("File size: {}".format(size))
        for status, variable in my_dict.items():
            if variable != 0:
                print("{}: {}".format(status, variable))
        raise
    print("File size: {}".format(size))
    for status, variable in my_dict.items():
        if variable != 0:
            print("{}: {}".format(status, variable))
