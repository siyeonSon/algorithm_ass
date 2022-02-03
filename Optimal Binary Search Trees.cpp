#include <iostream>
using namespace std;
float** A;
int** R;
int n;

float sum(float* P, int i, int j) {
	float s = 0;
	for (int l = i; l <= j; l++) {
		s += P[l];
	}
	return s;
}

void pprint(float** A) {
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 0; j <= n; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

void pprint(int** R) {
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 0; j <= n; j++) {
			cout << R[i][j] << " ";
		}
		cout << endl;
	}
}

void optsearchtree(int n, float* P, float* minavg, int** R) {
	int i, j, k, diagonal;
	float min;

	A = new float* [n + 2];
	for (int i = 0; i < n + 2; i++)
		A[i] = new float[n + 1];

	for (i = 1; i <= n + 1; i++)
		for (j = 0; j <= n; j++) {
			R[i][j] = 0;
			A[i][j] = 0;
		}

	for (i = 1; i <= n; i++) {
		A[i][i - 1] = 0;
		A[i][i] = P[i];
		R[i][i] = i;
		R[i][i - 1] = 0;
	}
	A[n + 1][n] = 0; R[n + 1][n] = 0;

	for (diagonal = 1; diagonal <= n - 1; diagonal++) {
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;
			min = A[i][i - 1] + A[i + 1][j] + sum(P, i, j);
			for (k = i; k <= j; k++) {
				if (min >= A[i][k - 1] + A[k + 1][j] + sum(P, i, j)) {
					min = A[i][k - 1] + A[k + 1][j] + sum(P, i, j);
					A[i][j] = min;
					R[i][j] = k;
				}
			}
		}
	}
	*minavg = A[1][n];
}

int main(void) {
	float minavg;

	cin >> n;
	float* P = new float[n + 1];
	for (int i = 0; i < n; i++)
		cin >> P[i + 1];

	R = new int* [n + 2];
	for (int i = 0; i < n + 2; i++)
		R[i] = new int[n + 1];

	optsearchtree(n, P, &minavg, R);

	cout << endl << ">> A" << endl;
	pprint(A);
	cout << endl << ">> R" << endl;
	pprint(R);

	cout << endl << ">> Answer : " << minavg;
	return 0;
}
