// Challenge 02
// Pablo Martinez-Abrego Gonzalez


#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Function that checks wether HTML tags are balanced
bool check_balance(string s) {
	stack<char> left;

	// Push complete opening TAG to the stack
	for (int i = 0; i < s.size(); i++) {
		if(s[i] == '<' && s[i+1] != '/') {
			for(int j = i+1; j < s.size(); j++) {
				if(s[j] == '>') {
					break;
				}
				left.push(s[j]);
			}
		// Go to the last character of closing TAG to iterate backwards
		} else if (s[i] == '/' && s[i-1] == '<') {
			while (s[i] != '>' && i <= s.size()) {
				i++;
			}
			int temp = i--; // Temporary variable for i after iterating backwards

			// Iterate backwards to compare complete TAG to the TAG in stack
			while(true){
				if (i+1 > s.size() || i < 0 || left.empty()) {
					return false;
				}
				if (s[i] == left.top()) {
					left.pop();
					i--;
				} else {
					return false;
				}
				if (s[i] == '/') {
					i = temp;
					break;
				}
			}
		}
	}
	return left.empty();
}

// Main function
int main() {
	string line;

	while (getline(cin, line)) {
		cout << (check_balance(line) ? "Balanced" : "Unbalanced") << endl;
	}
}
