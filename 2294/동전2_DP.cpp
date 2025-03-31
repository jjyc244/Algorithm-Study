#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> coins(n);
	vector<int> DP(k, -1);

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
		DP[coins[i] - 1] = 1;
	}

	for (int i = 0; i < k; i++) {
		int r = -1;
		for (int j = 0; j < n; j++) {
			if (i - coins[j] >= 0) {
				if (DP[i - coins[j]] != -1) {
					if (r == -1) r = DP[i - coins[j]] + 1;
					r = min(DP[i - coins[j]] + 1, r);
				}
			}
		}
		if (DP[i] == -1) DP[i] = r;
		else DP[i] = min(DP[i], r);
	}
	cout << DP[k - 1];
}