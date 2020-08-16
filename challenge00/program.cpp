// Challenge 00
// Pablo Martinez-Abrego Gonzalez


#include <iostream>
using namespace std;

// Got a template from StackOverflow on how to pass a 2D array to a function

// While we read the matrix, we are already performing the rotation
void read_rotate_matrix(int N, int *matrix) {
  int k = N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> *((matrix+j*N) + (k - 1));
    }
    k -= 1;
  }
}

// We simply print the matrix in order
void print_matrix(int N, int* matrix) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << *((matrix+i*N) + j);

      if (j < N-1) {
        cout << " ";
      }
    }

    if (i != N-1) {
      cout << endl;
    }
  }
}

int main() {
	int N = 1;
	bool first = true;

  while (N > 0) {
		cin >> N;

    // Formatting
		if(N == 0) {
			cout << endl;
			break;
		}

		int matrix[N][N];
    read_rotate_matrix(N, (int *)matrix);

    // Formatting
		if(first) {
			first = false;
		} else {
			cout << endl << endl;
		}

    print_matrix(N, (int *)matrix);
	}
}
