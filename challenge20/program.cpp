// Challenge 20
// Pablo Martinez-Abrego Gonzalez

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Globals
int graph[100][100];
int b[100];
int minimum;

// Read in Graph
void read_graph(int n, int connections) {
	int n1, n2, cap;
	for(int i = 1; i < n+1; i++) {
		for(int j = 1; j < n+1; j++) {
			graph[i][j] = 0;
		}
	}
	for(int i = 0; i < connections; i++) {
		cin >> n1 >> n2 >> cap;
		graph[n1][n2] += cap;
		graph[n2][n1] += cap;
	}
}

// Recursively find min
bool find_path_r(int n, int curr, int target) {
	if (curr == target) {
		return 1;
	}

	for(int i = 1; i < n+1; i++) {
		int temp = graph[curr][i];
		if (b[i] == 0 && temp > 0) {
			if (minimum > temp) {
				minimum = temp;
			}

			b[i] = curr;

			if (find_path_r(n, i, target)) {
				graph[curr][i] -= minimum;
				graph[i][curr] += minimum;
				return 1;
			}
		}
	}
		return 0;
}

int findMaxBand(int n, int source, int target) {
	int total = 0;
	while (true) {
		for(int i = 1; i < n+1; i++) {
			b[i] = 0;
		}

		minimum = INT_MAX;
		b[source] = 1;
		if ((find_path_r(n, source, target))) {
			return total;
		}
		total = total + minimum;
	}
}

// Main Execution
int main(){
	int network = 1;
	int total, n;
	int source, target, connections;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		cin >> source >> target >> connections;
		read_graph(n, connections);
		total = findMaxBand(n, source, target);
		cout << "Network " << network << ": Bandwidth is " << total << "." << endl;
		network++;
	}

}
