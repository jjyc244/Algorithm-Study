#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

int run(const vector<int>& house, int left, int right, int C) {
	int max = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			sum += house[i];
			if (sum >= mid) {
				cnt++;
				sum = 0;
			}
		}
		if (cnt == C) {
			if (max < mid) { max = mid; }
			left = mid + 1; 
		}
		else if (cnt > C) {
			if (max < mid) { max = mid; }
			left = mid + 1;
		}

		else right = mid - 1;
	}
	return max;
}

int main() {
	int N, C;
	cin >> N >> C;
	vector<int> house(N, 0);
	for (int i = 0; i < N; i++) cin >> house[i];
	sort(house.begin(), house.end());

	// house 백터에 거리로 저장
	int tmp = house[0];
	for (int i = 0; i < N; i++){
		house[i] -= tmp;
		tmp = house[i] + tmp;
	}
	int left = 0;
	int right = accumulate(house.begin(), house.end(), 0);

	cout << run(house, left, right, C);
}