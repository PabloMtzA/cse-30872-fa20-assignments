// Challenge 02
// Pablo Martinez-Abrego Gonzalez


#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check_balance(string s) {
	stack<char> left;

	for (int i = 0; i < s.size(); i++) {
		if(s[i] == '<' && s[i+1] != '/') {
			for(int j = i+1; j < s.size(); j++) {
				if(s[j] == '>') {
					break;
				}
				left.push(s[j]);
			}
		} else if(s[i] == '/') {
			while(s[i] != '>'){
				i++;
			}
			int temp = i--;
			while(true){
				if (s[i] == left.top()){
					left.pop();
					i--;
				}
				else {
					return false;
				}
				if(s[i] == '/') {
					i = temp;
					break;
				}
			}
		}
	}
	return left.empty();
}

int main() {
	string line;

	while (getline(cin, line)) {
		cout << (check_balance(line) ? "Balanced" : "Unbalanced") << endl;
	}
}
