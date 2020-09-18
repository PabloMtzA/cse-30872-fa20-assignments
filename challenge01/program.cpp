// Challenge 01
// Pablo Martinez-Abrego Gonzalez


#include <iostream>
#include <string>
#include<limits>

using namespace std;

// Function that checks how many times s2 can be formed with s1
int check_words(string s1, string s2) {
	int s2i = 0;
	int count = 0;

	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == s2[s2i] && s2i <= s2.size()) {
			s1.erase(i, 1);
			s2i++;
			i = -1;
		} else if (s2i > s2.size() - 1) {
			count++;
			s2i = 0;
		}
	}
	return count;
}

// Function that reads in line by line
void read_words(string s1, string s2) {
	while (cin >> s1 >> s2) {
		if (s1.empty()) {
			break;
		}

		int count = check_words(s1, s2);
		cout << count << endl;
	}
}

// Main Function
int main() {
	string s1;
	string s2;

	read_words(s1, s2);
}
