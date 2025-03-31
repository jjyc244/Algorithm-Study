#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> scores(N);
	vector<int> DP(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> scores[i];
	}
	if (N > 2){
		DP[0] = scores[0];
		DP[1] = scores[0] + scores[1];
		DP[2] = max(scores[0] + scores[2], scores[1] + scores[2]);

		for (int i = 3; i < N; i++) {
			DP[i] = max(DP[i - 3] + scores[i - 1], DP[i - 2]) + scores[i];
		}

	cout << DP[N - 1];
	}
	else {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += scores[i];
		}
		cout << sum;
	}
}