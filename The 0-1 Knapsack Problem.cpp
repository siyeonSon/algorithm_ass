#include <iostream>
#include <string>
using namespace std;

int n, W, maxprofit, numbest;
string* bestset;
string* include;
int* p, * w;
int profit2, weight2;

bool promising(int i) {
	int j, k;
	int totweight;
	float bound;

	if (weight2 >= W) return false;
	else if (i == n) return false;  // 생략
	else {
		j = i + 1;
		bound = profit2;
		totweight = weight2;
		while ((j <= n) && (totweight + w[j] <= W)) {
			totweight = totweight + w[j];
			bound = bound + p[j];
			j++;
		}
		k = j;
		if (k <= n) {
			bound = bound + (W - totweight) * p[k] / w[k];
			return bound > maxprofit;
		}
	}
}

void knapsack(int i, int profit, int weight) {
	if (weight <= W && profit > maxprofit) {
		maxprofit = profit;
		numbest = i;
		for (int j = 1; j < n + 1; j++) bestset[j] = include[j];
	}
	if (promising(i)) {
		include[i + 1] = "YES";
		profit2 = profit + p[i + 1];
		weight2 = weight + w[i + 1];
		knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);

		include[i + 1] = "NO";
		profit2 = profit;
		weight2 = weight;
		knapsack(i + 1, profit, weight);
	}
}

int main() {
	cin >> n >> W;
	p = new int[n + 1];
	w = new int[n + 1];
	bestset = new string[n + 1];
	include = new string[n + 1];

	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> w[i];
	}

	knapsack(0, 0, 0);

	int tmp_p = 0, tmp_w = 0;
	for (int i = 1; i <= n; i++) {
		if (bestset[i] == "YES") {
			tmp_p += p[i];
			tmp_w += w[i];
		}
	}

	cout << endl <<  "bestset >> ";
	for (int i = 1; i <= numbest; i++) {
		cout << bestset[i] << " ";
	}
	cout << endl << "total_p >> " << tmp_p;
	cout << endl << "total_w >> " << tmp_w;

	return 0;
}
