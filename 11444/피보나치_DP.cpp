#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N = 10000;
	vector<long long> DP(N, 0);
	DP[0] = 0; DP[1] = 1;

	for (int i = 2; i < N; i++) {
		DP[i] = (DP[i - 1] + DP[i - 2]) % 1000000007;
	}

	int t;
	for (int i = 0; i < N; i++) {
		cout << i << "번쨰 피보나치 수 : " << DP[i] << endl;
	}


}