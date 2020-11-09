// Challenge 22
// Pablo Martinez-Abrego Gonzalez

// Should have done it in python, realized it too late hahaha
// Sorry for the huge mess

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Read and seperate the arguments
// Push them to a vector that will be returned
vector<string> read_line(string &s) {
  vector<int> in;
  vector<string> expressions;
  string tempString;

  if (s.size() == 1) {
    expressions.push_back(s);
  }

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      in.push_back(i);
    } else if (s[i] == ')') {
      int it = in.back() + 1;
      in.pop_back();
      for (int j = it; j < i; j++) {
        string sym(1, s[j]);
        tempString.append(sym);
      }
      expressions.push_back(tempString);
      tempString.clear();
    }
  }
  return expressions;
}

// Perform operations unless its only the number, then return it
// Otherwise return answer
int arithmetic(string expression) {
  char op = expression[0];
  if (op != '+' && op != '-' && op != '/' && op != '*') {
    return stoi(expression);
  }

  expression.erase(0, 2);

  string n;
  int start = 0;
  int end;
  vector<int> numbers;

  for (int i = 0; i < expression.size(); i++) {
    if (expression[i] == ' ' || i == expression.size()-1) {
      end = i - 1;
      if (i == expression.size()-1) {
        end = i;
      }
      for (int j = start; j < end+1; j++) {
        n = n + expression[j];
      }
      numbers.push_back(stoi(n));
      n.clear();
      start = end + 2;
    }
  }

  int answer = 0;
  if (op == '+') {
    for (int i = 0; i < numbers.size(); i++) {
      answer += numbers[i];
    }
  }
  if (op == '-') {
    answer = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
      answer = answer - numbers[i];
    }
  }
  if (op == '*') {
    answer = 1;
    for (int i = 0; i < numbers.size(); i++) {
      answer *= numbers[i];
    }
  }
  if (op == '/') {
    answer = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
      answer = answer / numbers[i];
    }
  }

  return answer;
}


// Main execution
int main() {
	string line;
  string expression;
  int answer;
  string tempString;
	while (getline(cin, line)) {
		vector<string> expressions = read_line(line);
    if (line.size() == 1) {
      cout << expressions[0] << endl;
      continue;
    }
    for (int i = 0; i < expressions.size(); i++) {
      expression = expressions[i];
      answer = arithmetic(expression);
      expression.insert(0, "(");
      expression.push_back(')');
      for (int j = i+1; j < expressions.size(); j++) {
        tempString = expressions[j];
        if (tempString.find(expression) != string::npos) {
          size_t pos = tempString.find(expression);
          tempString.replace(pos, expression.length(), to_string(answer));
          expressions[j] = tempString;
        }
      }
    }
    cout << answer << endl;
	}
}
