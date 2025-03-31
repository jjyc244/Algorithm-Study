#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

struct pos {
	int m;
	int n;
	bool breakable;
};
bool isinrange(int M, int N, int m, int n) {
	if (m < 0 || n < 0 || m >= M || n >= N)return false;
	return true;
}

int main() {

	int M, N;
	cin >> M >> N;
	vector<vector<int>> MN(M, vector<int>(N));
	vector<vector<int>> dist(M, vector<int>(N, 0));
	vector<vector<int>> broken_dist(M, vector<int>(N, 0));
	queue<pos> q;

	dist[0][0] = 1;
	broken_dist[0][0] = 1;

	string s;
	for (int i = 0; i < M; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			MN[i][j] = s[j] - '0';
		}
	}

	int dm[] = { 0,0,1,-1 };
	int dn[] = { 1,-1,0,0 };

	//bfs ����
	q.push({ 0,0,true });
	while (!q.empty()) {

		int now_m = q.front().m;
		int now_n = q.front().n;
		bool breakable = q.front().breakable;
		q.pop();
		for (int i = 0; i < 4;i++) {
			int next_m = now_m + dm[i];
			int next_n = now_n + dn[i];
			if (isinrange(M, N, next_m, next_n)) {
				int now_dist = dist[now_m][now_n];
				int next_dist = dist[next_m][next_n];
				int now_broken_dist = broken_dist[now_m][now_n];
				int next_broken_dist = broken_dist[next_m][next_n];

				if (MN[next_m][next_n] == 0) {
					//�����ϴ� ���� �� X && ���� �μ���ȸ O
					//dist ���ؼ� ����Ƚ�� ������ �� || dist 0 �̸� ��
					if (breakable) {
						if (next_dist > now_dist + 1 || next_dist == 0) {
							dist[next_m][next_n] = now_dist + 1;
							q.push({ next_m,next_n,true });
						}
					}
					//�����ϴ� ���� �� X && ���� �μ���ȸ X
					//dist ���ؼ� ����Ƚ�� ������ �� && ( broken_dist ���ؼ� ����Ƚ�� ������ �� || broken_dist 0�̸� �� )
					else {
						if ((next_dist > now_broken_dist + 1 || next_dist == 0) && (next_broken_dist > now_broken_dist + 1 || next_broken_dist == 0)) {
							broken_dist[next_m][next_n] = now_broken_dist + 1;
							q.push({ next_m,next_n,false });
						}
					}
				}
				//�����ϴ� ���� �� O && ���� �μ���ȸ O
				//broken_dist ���ؼ� ����Ƚ�� ������ �� || broken_dist 0�̸� ��
				else if (MN[next_m][next_n] == 1 and breakable) {
					if (next_broken_dist > now_broken_dist + 1 || next_broken_dist == 0) {
						broken_dist[next_m][next_n] = now_dist + 1;
						q.push({ next_m,next_n,false });
					}
				}
			}
		}
	}

	M--, N--;
	if (dist[M][N] == 0 && broken_dist[M][N] == 0)cout << -1;
	else if (min(dist[M][N], broken_dist[M][N]) == 0)cout << max(dist[M][N], broken_dist[M][N]);
	else cout << min(dist[M][N], broken_dist[M][N]);
}