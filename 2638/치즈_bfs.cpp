#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<numeric>
using namespace std;

//처음 is_air 배열 만들고
//MN배열에서 현재 1인 원소들 싹다 조사 후
//위아래 양 옆 is_air = 1 카운트가 2 이상이면 삭제 후 queue에 넣어 준다.
//그러면 함수를 이용해 is_air 업데이트 해주고
//MN이 모두 0이되면 반복 종료 후 cnt 리턴

bool check_inrange(int m, int n, int M, int N) {
	return m >= 0 && n >= 0 && m < M && n < N;
}

int sum(const vector<vector<int>>& MN, int M, int N) {
	int sum = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			sum += MN[i][j];
		}
	}
	return sum;
}

void update_is_air(const vector<vector<int>>& MN, vector<vector<int>>& is_air, int M, int N ) {

	queue<pair<int,int>> q;
	q.push({ 0,0 });

	int dm[] = { 0,0,1,-1 };
	int dn[] = { 1,-1,0,0 };

	//is_air 초기화
	for (int i = 0; i < MN.size(); i++) {
		for (int j = 0; j < MN[0].size(); j++) {
			is_air[i][j] = 0;
		}
	}

	is_air[0][0] = 1;

	while (!q.empty()) {
		int now_m = q.front().first;
		int now_n = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_m = now_m + dm[i];
			int next_n = now_n + dn[i];
			if (check_inrange(next_m, next_n,M,N)) {
				if (is_air[next_m][next_n] == 0 && MN[next_m][next_n] == 0) {
					q.push({ next_m, next_n });
					is_air[next_m][next_n] = 1;
				}
			}
		}
	}
}

int run(vector<vector<int>>& MN, int M, int N) {

	int dm[] = { 0,0,1,-1 };
	int dn[] = { 1,-1,0,0 };

	int cheese = sum(MN, M, N);

	//is_air 배열 만들기
	vector<vector<int>> is_air(M, vector<int>(N, 0));
	queue<pair<int,int>> q;

	int cnt = 0;
	while (cheese) {

		cnt++;
		update_is_air(MN, is_air,M,N);

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (MN[i][j] == 1) {
					int c = 0;
					for (int k = 0; k < 4; k++) {
						int check_m = i + dm[k];
						int check_n = j + dn[k];
						if (check_inrange(check_m, check_n,M,N)) {
							if (is_air[check_m][check_n] == 1)c++;
						}
					}
					if (c >= 2) {
						MN[i][j] = 0;
						cheese--;
					}
				}
			}
		}
	}

	return cnt;
}
int main() {
	int M,N;
	cin >> M >> N;
	vector<vector<int>> MN(M, vector<int>(N));
	for (int i = 0; i < M; i++) {
		for (int j = 0;j < N; j++) cin >> MN[i][j];
	}
	cout << run(MN, M, N);

}