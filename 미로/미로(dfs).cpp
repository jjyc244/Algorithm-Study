#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

bool isinrange(int M, int N, int now_m, int now_n, int dm, int dn) {
	if (now_m + dm < 0 || now_m + dm >= M || now_n + dn < 0 || now_n + dn >= N)return false;
	else return true;
}

int main() {
	int M, N;
	cin >> M >> N;

	vector<vector<char>> MN(M, vector<char>(N));
	vector<vector<int>> dist(M, vector<int>(N, 0));
	stack<pair<int, int>> stack;

	string tmp;
	pair<int, int> start;
	pair<int, int> end;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			MN[i][j] = tmp[j];
			if (MN[i][j] == '.' && (i == 0 || j == 0 || i == M - 1 || j == N - 1)) {
				start.first = i;
				start.second = j;
			}
		}
	}

	dist[start.first][start.second] = 1;
	stack.push(start);

	int dm[] = { 1,0,-1,0 };
	int dn[] = { 0,-1,0,1 };

	while (true) {
		
		if (stack.empty())break;

		int now_m = stack.top().first;
		int now_n = stack.top().second;

		if (stack.top() != start && (now_m == 0 || now_n == 0 || now_m == M - 1 || now_n == N - 1)) {
			//이러면 도착점 찾은거
			end.first = now_m;
			end.second = now_n;
		}

		stack.pop();
		for (int i = 0; i < 4; i++) {
			if (isinrange(M, N, now_m, now_n, dm[i], dn[i])) {
				int next_m = now_m + dm[i];
				int next_n = now_n + dn[i];
				if (MN[next_m][next_n] == '.' && dist[next_m][next_n] == 0) {
					stack.push({ next_m, next_n });
					dist[next_m][next_n] = dist[now_m][now_n] + 1;
				}
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (dist[i][j] == 0 && MN[i][j] == '.') {
				MN[i][j] = '@';
			}
		}
	}

	while (true) {
		if (dist[start.first][start.second] == 0)break;
		for (int i = 0; i < 4; i++) {
			if (isinrange(M, N, end.first, end.second, dm[i], dn[i])) {
				int next_m = end.first + dm[i];
				int next_n = end.second + dn[i];
				if (dist[next_m][next_n] == dist[end.first][end.second] - 1) {
					dist[end.first][end.second] = 0;
					end.first = next_m;
					end.second = next_n;
				}
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (dist[i][j] > 0) {
				MN[i][j] = '@';
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << MN[i][j];
		}
		cout << endl;
	}
}
