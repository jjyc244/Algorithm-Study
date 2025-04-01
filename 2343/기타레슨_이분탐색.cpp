#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

bool check(const vector<int>& lesson, int mid, int M) {
	int sum = 0;
	for (int i = 0; i < lesson.size(); i++) {
		sum += lesson[i];
		if (sum == mid) {
			M--;
			sum = 0;
		}
		else if (sum > mid) {
			M--;
			i--;
			sum = 0;
		}
	}
	if (M <= 0) return true;
	return false;
}

int run(const vector<int>& lesson, int left, int right, int M) {
	int max = left;
	while (left < right) {
		int mid = (left + right) / 2;
		if (check(lesson, mid, M)) {
			max = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	return max;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> lesson(N, 0);
	for (int i = 0; i < N; i++) cin >> lesson[i];
	int left = *max_element(lesson.begin(), lesson.end());
	int right = accumulate(lesson.begin(), lesson.end(), 0);
	cout << run(lesson, left, right, M);
}