#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> DP(5000000, INT_MAX);
	DP[0] = 0;
	for (int i = 0; i < DP.size()/5; i++) {
		DP[3 * (i + 1) - 1] = min(DP[3 * (i + 1) - 1], DP[i] + 1);
		DP[2 * (i + 1) - 1] = min(DP[2 * (i + 1) - 1], DP[i] + 1);
		DP[i + 1] = min(DP[i+1], DP[i] + 1);
	}
	cout << DP[N - 1];
}