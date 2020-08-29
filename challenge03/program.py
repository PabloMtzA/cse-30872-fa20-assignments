#!/usr/bin/env python3

# Challenge 03
# Pablo Martinez Abrego Gonzalez

import sys

# Find the pivot point to divide into two sub arrays
def search_pivot(v):
    start = 0
    end = len(v) - 1
    while start < end:
        middle = (start + end) // 2
        if v[middle] > v[end]:
            start = middle + 1
        else:
            end = middle - 1
        if v[middle] < v[middle+1] and v[middle] < v[middle-1]:
            return middle
    return start

# Binary Search in the subarray where target is located
def binary_search(v, start, end, target):
    if start > end:
        return -1
    middle = (start + end) // 2
    if v[middle] == target:
        return middle
    if target > v[middle]:
        return binary_search(v, middle + 1, end, target)
    return binary_search(v, start, middle - 1, target)

# Search in which sub array the target is and apply binary search
def search_target(v, target, pivot):
    end = len(v) - 1
    if target > v[end] and target <= v[pivot-1]:
        return binary_search(v, 0, pivot-1, target)
    return binary_search(v, pivot, len(v)-1, target)

# Main function
def main():
    line_num = 0
    for line in sys.stdin:
        line_num+= 1
        if line_num % 2 != 0:
            v = list(map(int, line.strip().split()))
        else:
            target = int(line.strip())
            pivot = search_pivot(v)
            index = search_target(v, target, pivot)
            if index != -1 and pivot != -1:
                print(str(target) + " found at index " + str(index))
            else:
                print(str(target) + " was not found")

if __name__ == '__main__':
    main()
