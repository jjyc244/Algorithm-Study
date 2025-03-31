#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//청소하기
void clean(const vector<vector<int>>& MN, vector<vector<int>>& is_clean, int& r, int& c, int& d, int& num) {
	if (is_clean[r][c] == 0) { 
		is_clean[r][c] = 1;
		num++; 
	}
}

//4방향 중에 청소 가능있는지 확인
bool can_clean(const vector<vector<int>>& MN, vector<vector<int>>& is_clean, int M, int N, int& r, int& c, int& d) {
	int dm[] = { 0,0,1,-1 };
	int dn[] = { 1,-1,0,0 };
	for (int i = 0; i < 4; i++) {
		//4방향 확인하면서 청소 가능(is_clean == 0 && MN == 0) 나오면 true
		if (is_clean[min(max(r + dm[i], 0), M - 1)][min(max(c + dn[i], 0), N - 1)] == 0 && MN[min(max(r + dm[i], 0), M - 1)][min(max(c + dn[i], 0), N - 1)] == 0) return true;
	}
	return false;
}

//후진을 할 수 있는지 확인
bool can_back(const vector<vector<int>>& MN, vector<vector<int>>& is_clean,int M, int N, int& r, int& c, int& d) {
	int dm[] = { 1,0,-1,0 };
	int dn[] = { 0,-1,0,1 };
	if (!(max(min(r + dm[d], M - 1), 0) == r && max(min(c + dn[d], N - 1), 0) == c)) {
		//벽이 아니면 후진
		if (MN[r + dm[d]][c + dn[d]] == 0) {
			r = r + dm[d];
			c = c + dn[d];
			return true;
		}
	}
	return false;
}

//반시계 회전후 앞방향 청소 가능이면 전진
// 0: 북 1: 동 2: 남 3: 서 
void rotation(const vector<vector<int>>& MN, vector<vector<int>>& is_clean, int M ,int N, int& r, int& c, int& d) {
	//반시계 회전
	int direction[] = { 3,0,1,2 };
	d = direction[d];
	int dm[] = { -1, 0 ,1, 0 };
	int dn[] = { 0, 1, 0, -1 };

	//런타임 오류 방지해주고
	if (!(max(min(r + dm[d], M - 1), 0) == r && max(min(c + dn[d], N - 1), 0) == c)) {
		//벽이 아니고, 청소가 가능하면
		if (MN[r + dm[d]][c + dn[d]] == 0 && is_clean[r + dm[d]][c + dn[d]] == 0) {
			// 전진
			r += dm[d]; c += dn[d];
		}
	}
}

int run(const vector<vector<int>>& MN, vector<vector<int>>& is_clean, const int M, const int N, int& r, int& c, int& d) {
	int num = 0;
	while (true) {
		clean(MN, is_clean, r, c, d, num);
		if(!(can_clean(MN, is_clean, M, N, r, c, d))){
			if (!can_back(MN, is_clean, M, N, r, c, d)) break;
		}
		else {
			rotation(MN, is_clean, M, N, r, c, d);
		}

	}
	
	return num;
}

int main() {
	int M, N;
	cin >> M >> N;
	int r, c, d;
	cin >> r >> c >> d;

	vector<vector<int>> is_clean(M, vector<int>(N, 0));
	vector<vector<int>> MN(M, vector<int>(N, 0));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MN[i][j];
		}
	}

	cout << run(MN, is_clean, M, N, r, c, d);
}