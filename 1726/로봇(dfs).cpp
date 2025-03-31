#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct position {
	int m;
	int n;
	int r;

	position() {
		m = 0;
		n = 0;
		r = 0;
	}

	position(int m, int n, int r) {
		this->m = m;
		this->n = n;
		this->r = r;
	}
};
int r_add(int a, int b) {
	if ((a == 1 && b == 2) || (a == 2 && b == 1) || (a == 3 && b == 4) || (a == 4 && b == 3))return 2;
	else if (a == b)return 0;
	else return 1;
}
bool isinrange(int M, int N, int next_m, int next_n) {
	if (next_n < 0 || next_n >= N || next_m < 0 || next_m >= M)return false;
	return true;
}

int main() {
	
	int M, N;
	cin >> M >> N;
	vector<vector<int>> MN(M, vector<int>(N));
	vector<vector<int>> dist(M, vector<int>(N,0));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MN[i][j];
		}
	}

	stack<position> stk;
	position start;
	position end;
	cin >> start.m >> start.n >> start.r;
	cin >> end.m >> end.n >> end.r;
	start.m--; start.n--;
	end.m--; end.n--;

	stk.push(start);

	int dm[] = { 0,0,1,-1 };
	int dn[] = { 1,-1,0,0 };

	while (!stk.empty()) {
	
		int now_m = stk.top().m;
		int now_n = stk.top().n;
		int now_r = stk.top().r;

		stk.pop();
		for (int i = 0; i < 4; i++) {
			int next_m = now_m;
			int next_n = now_n;
			int next_r = now_r;
			for (int j = 0; j < 3; j++) {
				next_m += dm[i];
				next_n += dn[i];
				next_r = i + 1;
				if (isinrange(M, N, next_m, next_n)) {
					// 벽을 만나면 break;
					if (MN[next_m][next_n] == 1)break;

					// end 점을 만났을때
					else if (end.m == next_m && end.n == next_n) {
						int add_dist = r_add(now_r, next_r) + r_add(end.r, next_r) + 1;
						if (dist[end.m][end.n] == 0 || dist[end.m][end.n] > dist[now_m][now_n] + add_dist)dist[end.m][end.n] = dist[now_m][now_n] + add_dist;
					}

					//end 점, 벽을 안 만났을떼
					else {
						int add_dist = r_add(now_r, next_r) + 1;
						if (dist[next_m][next_n] == 0 || dist[next_m][next_n] > dist[now_m][now_n] + add_dist) {
							stk.push({ next_m,next_n,next_r });
							dist[next_m][next_n] = dist[now_m][now_n] + add_dist;
						}
					}
				}
			}
		}
	}
	if (start.m == end.m && start.n == end.n)dist[start.m][start.n] = r_add(start.r, end.r);
	cout << dist[end.m][end.n];
}