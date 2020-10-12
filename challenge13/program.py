#!/usr/bin/env python3

# Template from Lectures and Stack Overflow to build tree

import collections
import sys

Node = collections.namedtuple('Node', 'value left right')

# Classes
def buildTree(t, l, r):
    ''' Build the BST '''
    # Base cases
    if r - l < 0:
        return None
    if r - l < 1:
        return Node(t[r], None, None)

    m = -(-(r-l)//2) + l
    return Node(t[m], buildTree(t, l, m - 1), buildTree(t, m + 1, r))

# Functions
def min_height(root):
    ''' Use divide and conquer to print minimum height tree '''
    # Base: reached non-existent node, so simply return
    if root is None:
        return

    # Build a Queue for printing purposes
    q = []
    q.append(root)
    while q:
        i = len(q)
        p = []
        while i > 0:
            t = q.pop(0)
            p.append(t.value)

            if t.left:
                q.append(t.left)
            if t.right:
                q.append(t.right)
            i = i - 1

        print(*p, sep=' ')

# Main Execution

def main():
    for line in sys.stdin:
        # Construct BST
        values = []
        for value in map(int, line.split()):
            values.append(value)
        root = buildTree(values, 0, len(values) - 1)

        # Print min height tree
        min_height(root)

if __name__ == '__main__':
    main()
