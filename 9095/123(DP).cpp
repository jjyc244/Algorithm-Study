#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	vector<int> DP = { 1,2,4 };
	for (int i = 0; i < 10; i++) {
		int tmp;
		DP.push_back(DP[i + 2] + DP[i + 1] + DP[i]);
	}

	int T;
	cin >> T;
	queue<int> q;
	while (T--) {
		int n;
		cin >> n;
		q.push(DP[n - 1]);
	}

	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
}