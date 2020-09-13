// Challenge 07
// Pablo Martinez-Abrego Gonzalez

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Check uniqueness of 5-digit permutations
bool check_numbers(int n, int d) {
  int nsize = to_string(n).length();
  int dsize = to_string(d).length();

  // Add zero at end for comparison purposes
  if (nsize == 4) {
    n = n * 10;
  }
  if (dsize == 4) {
    d = d * 10;
  }

  if (nsize < 4 || dsize < 4) {
    return false;
  }

  string nstring = to_string(n);
  for (int i = 0; i < nstring.size(); i++) {
    for (int j = i+1; j < nstring.size(); j++) {
      if (nstring[i] == nstring[j]) {
        return false;
      }
    }
  }
  string dstring = to_string(d);
  for (int i = 0; i < dstring.size(); i++) {
    for (int j = i+1; j < dstring.size(); j++) {
      if (dstring[i] == dstring[j]) {
        return false;
      }
    }
  }

  for (int i = 0; i < nstring.size(); i++) {
    for (int j = 0; j < dstring.size(); j++) {
      if (nstring[i] == dstring[j]) {
        return false;
      }
    }
  }

  return true;
}

void perms(int n) {
  bool found = false;
  const int MIN_DENOM = 01234;
  const int MAX_NUM = 98765;

  int denom = MIN_DENOM;
  int numer = 0;
  int count = 0;

  while (numer <= MAX_NUM) {
    numer = denom * n;
      if check_numbers(numer, denom)) {
        found = true;
        int nsize = to_string(numer).length();
        int dsize = to_string(denom).length();

        if (nsize == 4) {
          cout << "0" << numer << " / " << denom++ << " = " << n << endl;
        } else if (dsize == 4) {
          cout << numer << " / " << "0" << denom++ << " = " << n << endl;
        } else {
          cout << numer << " / " << denom++ << " = " << n << endl;
        }
    }
    denom++;
  }

  if (!found) {
    cout << "There are no solutions for " << n << "." << endl;
  }
}


void read_number() {
	int n;
  bool first = true;
  cin >> n;
	while (n != 0) {
		if (n == 0) {
			break;
		}

    perms(n);
    cin >> n;
    if (n!= 0) {
      cout << endl;
    }
	}
}

// Main Function
int main() {
	read_number();
}
