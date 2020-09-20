// Challenge 09
// Pablo Martinez-Abrego Gonzalez

#include <iostream>
#include <string>

using namespace std;

// Functions
void binary_strings(string s, int n, int k) {
  int count = 0;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      count++;
    }
  }

  if (s.size() == n) {
    if (count == k) {
      cout << s << endl;
    }
    return;
  }

  binary_strings(s + '0', n, k);
  binary_strings(s + '1', n, k);
}

// Function that reads in line by line
void read_numbers() {
	string s1, s2;
	int n1, n2;
  cin >> s1 >> s2;
	while (true) {
		n1 = stoi(s1);
		n2 = stoi(s2);
    string s;

		binary_strings(s, n1, n2);

    if (!(cin >> s1 >> s2)) {
      break;
    } else {
      cout << endl;
    }
	}
}

// Main Function
int main() {
	read_numbers();
}
