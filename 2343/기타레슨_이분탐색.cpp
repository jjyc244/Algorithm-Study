#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

bool check(const vector<int>& lesson, int mid, int M, int& max) {
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
	if (sum > 0) M--;
	if (M == 0) {
		if (max > mid) {
			max = mid;
			return false;
		}
		else return true;
	}
	else if (M < 0) { 
		return true; 

	}
	else {
		if (max > mid) {
			max = mid;
		}
		return false;
	}
}

int run(const vector<int>& lesson, int left, int right, int M) {
	int min = right;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(lesson, mid, M, min)) {
			left = mid + 1;
		}
		else right = mid - 1;
	}
	return min;
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