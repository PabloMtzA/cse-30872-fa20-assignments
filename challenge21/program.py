#!/usr/bin/env python3

## Challenge 21
## Pablo Martinez-Abrego Gonzalez

import sys

## Determine if carmichael
def carmichael(n):
    for i in range(2, n - 1):
        if pow(i, n, n) != i:
            return False

    primes = set(range(2, n + 1))
    for i in range(2, n + 1):
        for j in range(i*i, n + 1, i):
            if j in primes:
                primes.remove(j)
    if n in primes:
        return False

    return True

## Main
def main():
    for line in sys.stdin:
        n = int(line)
        if carmichael(n):
            print("The number %d is a Carmichael number." %n)
        else:
            print("%d is normal." %n)

if __name__ == '__main__':
    main()
