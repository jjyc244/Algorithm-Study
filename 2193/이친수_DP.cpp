#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long long> DP(N);
	if (N == 1)cout << 1;
	if (N >= 2) {
		DP[0] = 1; 
		DP[1] = 1;
		for (int i = 2; i < N;i++) {
			DP[i] = DP[i - 1] + DP[i - 2];
		}
		cout << DP[N - 1];
	}
}