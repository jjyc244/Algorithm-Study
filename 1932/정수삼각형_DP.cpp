#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector <vector<int>> DP(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) { 
			int num;
			cin >> num;
			DP[i][j] += num;
			if (i != N - 1) {
				DP[i + 1][j] = max(DP[i + 1][j], DP[i][j]);
				DP[i + 1][j+1] = max(DP[i + 1][j+1], DP[i][j]);
			}
		}
	}
	cout << *max_element(DP[N - 1].begin(), DP[N - 1].end());
}