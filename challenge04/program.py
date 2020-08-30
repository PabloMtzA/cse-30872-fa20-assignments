#!/usr/bin/env python3

import collections
import functools
import sys

# Structures

Person = collections.namedtuple('People', 'name rank suit')

# Functions
def compare_ranks(a, b):
    atemp = a.rank
    btemp = b.rank
    if atemp == 'A':
        atemp = 14
    if btemp == 'A':
        btemp = 14
    if atemp == 'K':
        atemp = 13
    if btemp == 'K':
        btemp = 13
    if atemp == 'Q':
        atemp = 12
    if btemp == 'Q':
        btemp = 12
    if atemp == 'J':
        atemp = 11
    if btemp == 'J':
        btemp = 11
    if int(atemp) > int(btemp):
        return 1
    if int(atemp) < int(btemp):
        return -1
    return 0

def main():
    sort_key = functools.cmp_to_key(compare_ranks)

    num = int(sys.stdin.readline())
    while num != 0:
        people = [Person(*sys.stdin.readline().split()) for i in range(num)]

        people = sorted(people, key=lambda p: p.suit, reverse=True)
        people = sorted(people, key=sort_key, reverse=True)

        i = 1
        for person in people:
            if i != num:
                print(person[0] + ", ", end='')
            else:
                print(person[0])
            i += 1

        num = int(sys.stdin.readline())

# Main execution
if __name__ == '__main__':
    main()
