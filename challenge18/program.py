#!/usr/bin/env python3

## Challenge 18
## Pablo Martinez-Abrego Gonzalez

## Template from Lecture 19-A

import collections
import sys

# Graph Structure

Graph = collections.namedtuple('Graph', 'edges degrees')

# Read Graph

def read_graph():
    edges   = collections.defaultdict(set)
    degrees = collections.defaultdict(int)

    for line in sys.stdin:
        l = [char for char in line.rstrip()]

        for t, s in enumerate(l):
            if t + 1 < len(l) and l[t + 1] not in edges[s]:
                edges[s].add(l[t + 1])
                degrees[l[t + 1]] += 1
                degrees[s]

    return Graph(edges, degrees)

# Topological Sort

def topological_sort(graph):
    frontier = [v for v, d in graph.degrees.items() if d == 0]
    visited  = []

    while frontier:
        vertex = frontier.pop()
        visited.append(vertex)

        for neighbor in graph.edges[vertex]:
            graph.degrees[neighbor] -= 1
            if graph.degrees[neighbor] == 0:
                frontier.append(neighbor)

    return visited

# Main Execution

def main():
    graph    = read_graph()
    vertices = topological_sort(graph)
    print(''.join(vertices))

if __name__ == '__main__':
    main()
