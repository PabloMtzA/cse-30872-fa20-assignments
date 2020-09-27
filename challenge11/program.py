## Challenge 11
## Pablo Martinez-Abrego Gonzalez
## Template from Lecture 16


#!/usr/bin/env python3

import sys

# Functions
def compute_table(n):
    # Initialize table to 0's
    table = [0] * (n + 1)

    square_roots = []
    i = 1
    while i ** 2 <= n:
        square_roots.append(i**2)
        i += 1

    # Initialize base cases (ie. coins)
    for square in square_roots:
        table[square] = 1

    # For each entry i in table, compute the following recurrence relation:
    #
    #   table[i] = min(table[i - square] + 1 for square in squares_roots if (i - coin) >= 0)
    for i in range(1, n + 1):
        if not table[i]:
            table[i] = min(table[i - square] + 1 for square in square_roots if (i - square) >= 0)

    print(table[n])

def main():

    # Lookup solutions in table
    for n in map(int, sys.stdin):
        compute_table(n)

# Main execution

if __name__ == '__main__':
    main()
