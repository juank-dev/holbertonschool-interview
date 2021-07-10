#!/usr/bin/python3
""" Task 0 => Change comes from within Given a pile of coins of different values,
determine the fewest number of coins needed to meet a given amount total."""


def makeChange(coins, total):
	""" Prototype: def makeChange(coins, total)
		Return: fewest number of coins needed to meet total
		If total is 0 or less, return 0
		If total cannot be met by any number of coins you have, return -1
	"""
	if total < 1:
		return 0
	coins.sort()
	coins.reverse()
	fewestNumber = 0
	for coin in coins:
		if total <= 0:
			break
		buffer = total // coin
		fewestNumber += buffer
		total -= (buffer * coin)
	if total != 0:
		return -1
	return fewestNumber
