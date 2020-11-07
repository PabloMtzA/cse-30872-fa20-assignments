#!/usr/bin/env python3

## Challenge 19
## Pablo Martinez-Abrego Gonzalez

## Template from Lecture 21-A

from collections import defaultdict
import sys

def read_graph():
    graph = defaultdict(list)
    u = sys.stdin.readline().rstrip()
    while u != '%':
        s, t = u.split()
        graph[int(s)].append(int(t))
        graph[int(t)].append(int(s))
        u = sys.stdin.readline().rstrip()

    for key in graph:
        graph[key].sort()

    return graph

# Find Circuit
def find_circuit(n, graph, start, vertex, visited, path):
    ''' Recursive DFS traversal '''
    # If we have returned to start, return path
    if path and start == vertex:
        if vertex in visited:
            if len(visited) == n:
                path.append(str(start))
                return path
            return []
        else:
            visited.add(vertex)

    # Visit each unvisited outgoing edge
    for neighbor in graph[vertex]:
        if neighbor in visited:
            continue

        # Mark visited
        visited.add(neighbor)

        # Add to path
        path.append(str(vertex))

        # Recurse
        if find_circuit(n, graph, start, neighbor, visited, path):
            return path

        # Remove from path
        path.pop(-1)

        # Unmark visited
        visited.remove(neighbor)

    # No circuit found, so return nothing (should never happen!)
    return []

# Main Execution
def main():
    n = int(sys.stdin.readline().rstrip())
    while(n and n != ''):
        graph = read_graph()
        if len(graph) != n:
            print('None')
        else:
            print(' '.join(find_circuit(n, graph, 1, 1, set(), [])))

        # Not the most ideal way but works
        inp = sys.stdin.readline().rstrip()
        if inp != '':
            n = int(inp)
        else:
            n = inp

if __name__ == '__main__':
    main()
