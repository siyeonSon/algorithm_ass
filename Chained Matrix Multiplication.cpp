#include <iostream>
using namespace std;

int n;
int** P;
int** M;

int** Matrix(int n) {
	int** M = new int* [n];
	for (int i = 0; i < n; i++)
		M[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			M[i][j] = 0;
	return M;
}

void pprint(int** P) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				cout << P[i][j] << " ";
			else {
				if (P[i][j] == 0) cout << "  ";
				else cout << P[i][j] << " ";
			}
		}
		cout << endl;
	}
}

int minmult(int n, int* d, int** P) {
	int i, j, k, diagonal, minimum;
	M = Matrix(n + 1);

	for (diagonal = 1; diagonal <= n - 1; diagonal++)
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;
			minimum = M[i][i] + M[i + 1][j] + d[i - 1] * d[i] * d[j];
			for (k = i; k <= j - 1; k++) {
				if (minimum >= M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j]) {
					M[i][j] = minimum = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
					P[i][j] = k;
				}
			}
		}
	return M[1][n];
}


void order(int i, int j) {
	int k = 0;
	if (i == j) cout << "A" << i;
	else {
		k = P[i][j];
		cout << "(";
		order(i, k);
		order(k + 1, j);
		cout << ")";
	}
}

int main() {
	
	cin >> n;  // 행렬의 개수

	int* d = new int[n + 1];
	for (int i = 0; i <= n; i++)
		cin >> d[i];  // 행렬들의 열의 개수

	P = Matrix(n + 1);
	cout << endl << "최소 곱셈 횟수 : " << minmult(n, d, P);

	cout << endl << endl << ">> P" << endl;
	pprint(P);

	cout << endl << endl << ">> M" << endl;
	pprint(M);
	
	cout << endl << endl << "최적의 순서 : ";
	order(1, 6);

	return 0;
}