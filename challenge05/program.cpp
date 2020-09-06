// Challenge 05
// Pablo Martinez-Abrego Gonzalez


#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Global Variable
unordered_map<unsigned int, int> numbers;

// Recursive function for returning count and adding to unordered_map
int check_max(unsigned int n, int count) {
	if (numbers.count(n)) {
		return numbers[n];
	}

	if (n == 1) {
		return 1;
	}

	if (!numbers.count(n)) {

		int nt;

		if (n % 2 == 1) {
			nt = 3*n + 1;
		} else {
			nt = n/2;
		}

		numbers.insert({ n, check_max(nt, count+1) + 1});
	}
	return numbers[n];
}


// Function that iterates through given integers
void check_numbers(unsigned int n1, unsigned int n2) {

	bool swapB = false;
	int max_count = 0;
	unsigned int max_number;

	if (n2 < n1) {
		swap(n2, n1);
		swapB = true;
	}

	for (int i = n1; i <= n2; i++){
		int temp = check_max(i, 1);
		if (temp > max_count) {
			max_number = i;
			max_count = temp;
		}
	}
	if (!swapB) {
		cout << n1 << " " << n2 << " " << max_number << " " << max_count << endl;
	} else {
		cout << n2 << " " << n1 << " " << max_number << " " << max_count << endl;
	}
}

// Function that reads in line by line
void read_numbers() {
	string s1, s2;
	unsigned int n1, n2;
	while (cin >> s1 >> s2) {

		if (s1.empty()) {
			break;
		}

		n1 = stoi(s1);
		n2 = stoi(s2);

		check_numbers(n1, n2);
	}
}

// Main Function
int main(){
	read_numbers();
}
