#!/bin/python3
import math
import sys
def find_factor(num):
    if num <= 3:
        if num >= 0:
            return num
    if num % 2 == 0:
        return 2
    if num % 3 == 0:
        return 3
    end = int(math.sqrt(num))
    for i in range(5, end + 1, 6):
        if num % i == 0:
            return i
        if num % (i + 2) == 0:
            return i + 2
    return None

def print_fact(num):
    fact = find_factor(num)
    if fact is None:
        print(f'{num}=1*{num}')
    else:
        fact2 = int(num / fact)
        print(f'{num}={fact2}*{fact}')

def main():
    file_path = sys.argv[1]
    with open(file_path, "r") as file:
        for line in file:
            print_fact(int(line))
main()
