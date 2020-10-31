#!/usr/bin/env python3

## Challenge 17
## Pablo Martinez-Abrego Gonzalez

## Template from Lecture 19

import collections
import heapq
import sys
import math

# Build Graph
def read_graph(n):
	g = collections.defaultdict(dict)

	for i in range(n):
		source = tuple(map(float, sys.stdin.readline().split()))
		g[source] = {}

	for s in g.keys():
		for t in g.keys():
			if s != t:
				weight = math.sqrt(((s[0] - t[0]) ** 2) + ((s[1] - t[1]) ** 2))
				g[s][t] = weight
				g[t][s] = weight

	return g

# Compute MST
def compute_mst(g):
    frontier = []
    visited  = {}
    start    = list(g.keys())[0]

    heapq.heappush(frontier, (0, start, start))

    while frontier:
        weight, target, source = heapq.heappop(frontier)

        if target in visited:
            continue

        visited[target] = weight
        for neighbor, cost in g[target].items():
            heapq.heappush(frontier, (cost, neighbor, target))

    return visited

def min_path(m):
	min = 0
	for i in m.keys():
		min += m[i]

	print("{:.2f}".format(min))

# Main Execution
def main():
	n = int(sys.stdin.readline())
	while n:
		g = read_graph(n)
		m = compute_mst(g)
		min_path(m)
		n = int(sys.stdin.readline())

if __name__ == '__main__':
    main()
