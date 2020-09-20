// Challenge 10
// Pablo Martinez-Abrego Gonzalez

#include <iostream>
#include <string>

using namespace std;

// Functions
void lego_bricks(int n1, int n2, int n3, int n4) {
  if (n2 % 2 == 0) {
    n2 = n2 / 2;
  } else {
    n2 = (n2 + 1) / 2;
    if(n1 >= 2) {
      n1 = n1 - 2;
    } else {
      n1 = 0;
    }
  }
  if (n1 >= n3) {
    n1 = n1 - n3;
    n1 = (n1 + 3) / 4;
  } else {
    n1 = 0;
  }
  cout << (n1 + n2 + n3 + n4) << endl;
}

// Function that reads in line by line
void read_numbers() {
	int n1, n2, n3, n4;
	while (cin >> n1 >> n2 >> n3 >> n4) {
    lego_bricks(n1, n2, n3, n4);
	}
}

// Main Function
int main() {
	read_numbers();
}
