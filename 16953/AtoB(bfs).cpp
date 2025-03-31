#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;

int main() {

	queue<pair<long long, long long>> q;
	int start, end;
	cin >> start >> end;

	//bfs Ω√¿€
	int min = INT_MAX;
	q.push({ start,0 });

	while (!q.empty()) {
		long long n = q.front().first;
		long long r = q.front().second;
		q.pop();
		if (n * 2 <= end) {
			if (n * 2 == end) min = min > r + 1 ? r + 1 : min;
			else q.push({ n * 2,r+1 });
		}
		if (n * 10 + 1 <= end) {
			if (n * 10 + 1 == end) min = min > r + 1 ? r + 1 : min;
			else q.push({ n * 10 + 1,r+1 });
		}
	}

	if (start == end) cout << 1;
	else if (min == INT_MAX) cout << -1;
	else cout << min + 1;
}