// Pablo Martinez-Abrego Gonzalez
// Challenge 06

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

// Function that reads in fruits into a vector
vector<string> read_fruits(string &s) {
	vector<string> fruits;
	stringstream ss(s);
	string fruit;

	while (ss >> fruit) {
		fruits.push_back(fruit);
	}

	return fruits;
}

// Function that finds the length and starting index of longest distinct sequence
void find_maximum_contiguous_array(vector<string> &fruits) {
	unordered_map<string, int> seen;
	int    cur_length  = 0;
	size_t max_length = 0;
	int max_index, last_in;
	int j = 0;

	for (size_t i = 0; i < fruits.size(); i++) {
		if (seen.count(fruits[i])) {
			last_in = seen[fruits[i]];
			if(j < last_in + 1) {
				j = last_in + 1;
			}
		}

		cur_length = i - j + 1;
		if (cur_length > max_length) {
			max_length = cur_length;
			max_index = j;
		}

		seen[fruits[i]] = i;
	}

	cout << max_length << ": ";
	int end = max_index + max_length;
	for (int i = max_index; i < end; i++) {
		if (i == end - 1) {
			cout << fruits[i] << endl;
		} else {
			cout << fruits[i] << ", ";
		}
	}
}

// Main execution
int main() {
	string line;
	while (getline(cin, line)) {
		auto fruits = read_fruits(line);
		find_maximum_contiguous_array(fruits);
	}
	return 0;
}
