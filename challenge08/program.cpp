// Challenge 08
// Pablo Martinez-Abrego Gonzalez

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// Globals
map<char, string> LETTERS = {
	{'0', "46"},
	{'1', "68"},
	{'2', "79"},
	{'3', "48"},
	{'4', "039"},
	{'5', ""},
	{'6', "017"},
	{'7', "26"},
	{'8', "13"},
	{'9', "24"},
};

// Functions
void phone_combinations(string numbers, int n) {
	if (numbers.size() == n) {
		cout << numbers <<  endl;
	} else {
		for (auto number : LETTERS[numbers.back()]) {
			phone_combinations(numbers + number, n);
		}
	}
}

// Main execution

int main() {
	string numbers;
	getline(cin, numbers);
	while (true) {
		int n = numbers[2] - 48;
		string s(1, numbers[0]);
		phone_combinations(s, n);

		getline(cin, numbers);
		if (numbers.empty()) {
			break;
		} else {
			cout << endl;
		}
	}

	return 0;
}
