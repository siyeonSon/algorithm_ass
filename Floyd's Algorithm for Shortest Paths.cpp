/* 과제 01 */
#include <iostream>
using namespace std;

int n, p, q;
int **D;
int **P;
int **W;

int **makeMatrix(int n)
{ // 2차원 배열 동적 할당
	int **M = new int *[n + 1];
	for (int i = 1; i <= n; i++)
	{
		M[i] = new int[n + 1];
	}
	return M;
}

void floyd(int n, int **W, int **D, int **P)
{ // Algorithm 3.2
	int i, j, k;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			P[i][j] = 0;
	D = W;
	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (D[i][k] + D[k][j] < D[i][j])
				{
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
				}
}

void Print(int **M)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << M[i][j] << " ";
		cout << endl;
	}
}

void path(int q, int r)
{
	if (P[q][r] != 0)
	{
		path(q, P[q][r]);
		cout << "v" << P[q][r] << " ";
		path(P[q][r], r);
	}
}

int main(void)
{
	cout << ">> VERTEX SIZE : ";
	cin >> n;

	D = makeMatrix(n);
	P = makeMatrix(n);
	W = makeMatrix(n);

	cout << endl
			 << ">> INPUT W" << endl;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> W[i][j];

	floyd(n, W, D, P);

	cout << endl
			 << ">> PRINT D" << endl;
	Print(W);
	cout << endl
			 << ">> PRINT P" << endl;
	Print(P);
	cout << endl
			 << endl;

	cout << ">> path(p, q) : ";
	cin >> p >> q;
	path(p, q);

	for (int i = 1; i <= n; i++)
		delete[] D[i], P[i], W[i];
	delete[] D, P, W;

	return 0;
}