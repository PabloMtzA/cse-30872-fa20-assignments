// Challenge 15
// Pablo Martinez-Abrego Gonzalez

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int long_road(vector<vector<int>> edgeList, vector<int> visited, int curr) {
	int ans = 0;

	for (int i = 0; i < edgeList.size(); i++) {
		if (curr == edgeList[i][0] || curr == edgeList[i][1]) {
			if (visited[i] == 0) {
				visited[i] = 1;
				if (edgeList[i][0] == curr) {
					ans = max(ans, 1 + long_road(edgeList, visited, edgeList[i][1]));
				} else {
					ans = max(ans, 1 + long_road(edgeList, visited, edgeList[i][0]));
				}
				visited[i] = 0;
			}
		}
	}
	return ans;
}

int main() {
	int n, m, ue1, ue2;
	vector<int> temp;
	cin >> n >> m;

	while(n != 0 && m != 0) {
		vector<vector<int>> edgeList;

		for (int i = 0; i < m; i++) {
			cin >> ue1 >> ue2;
			temp = {ue1, ue2};
			edgeList.push_back(temp);
		}

		int ans = 0;
		vector<int> visited(25, 0);
		for (int i = 0; i < n; i++) {
			ans = max(ans, long_road(edgeList, visited, i));
		}
		cout << ans << endl;
		cin >> n >> m;
	}
}
