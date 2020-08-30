#!/usr/bin/env python3

import collections
import functools
import sys

# Structures

Person = collections.namedtuple('People', 'name rank suit')

# Functions
def compare_ranks(a, b):
    ar = a.rank
    br = b.rank
    if ar == 'A':
        ar = 14
    if br == 'A':
        br = 14
    if ar == 'K':
        ar = 13
    if br == 'K':
        br = 13
    if ar == 'Q':
        ar = 12
    if br == 'Q':
        br = 12
    if ar == 'J':
        ar = 11
    if br == 'J':
        br = 11
    if int(ar) > int(br):
        return 1
    elif int(ar) < int(br):
        return -1
    return 0

def main():
    sort_key1 = functools.cmp_to_key(compare_ranks)

    n = int(sys.stdin.readline())
    while n != 0:
        people = [Person(*sys.stdin.readline().split()) for i in range(n)]

        people = sorted(people, key=lambda p: p.suit, reverse=True)
        people = sorted(people, key=sort_key1, reverse=True)

        i = 1
        for person in people:
            if i != n:
                print(person[0] + ", ", end='')
            else:
                print(person[0])
            i += 1

        n = int(sys.stdin.readline())

# Main execution
if __name__ == '__main__':
    main()
