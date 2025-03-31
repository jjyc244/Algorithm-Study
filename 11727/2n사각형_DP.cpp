#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> DP(1000);
	DP[0] = 1; DP[1] = 3;
	for (int i = 2; i < N; i++) {
		DP[i] = DP[i - 1] + 2 * DP[i - 2];
		DP[i] %= 10007;
	}

	cout << DP[N - 1];
}