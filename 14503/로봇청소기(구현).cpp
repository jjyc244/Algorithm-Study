#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//û���ϱ�
void clean(const vector<vector<int>>& MN, vector<vector<int>>& is_clean, int& r, int& c, int& d, int& num) {
	if (is_clean[r][c] == 0) { 
		is_clean[r][c] = 1;
		num++; 
	}
}

//4���� �߿� û�� �����ִ��� Ȯ��
bool can_clean(const vector<vector<int>>& MN, vector<vector<int>>& is_clean, int M, int N, int& r, int& c, int& d) {
	int dm[] = { 0,0,1,-1 };
	int dn[] = { 1,-1,0,0 };
	for (int i = 0; i < 4; i++) {
		//4���� Ȯ���ϸ鼭 û�� ����(is_clean == 0 && MN == 0) ������ true
		if (is_clean[min(max(r + dm[i], 0), M - 1)][min(max(c + dn[i], 0), N - 1)] == 0 && MN[min(max(r + dm[i], 0), M - 1)][min(max(c + dn[i], 0), N - 1)] == 0) return true;
	}
	return false;
}

//������ �� �� �ִ��� Ȯ��
bool can_back(const vector<vector<int>>& MN, vector<vector<int>>& is_clean,int M, int N, int& r, int& c, int& d) {
	int dm[] = { 1,0,-1,0 };
	int dn[] = { 0,-1,0,1 };
	if (!(max(min(r + dm[d], M - 1), 0) == r && max(min(c + dn[d], N - 1), 0) == c)) {
		//���� �ƴϸ� ����
		if (MN[r + dm[d]][c + dn[d]] == 0) {
			r = r + dm[d];
			c = c + dn[d];
			return true;
		}
	}
	return false;
}

//�ݽð� ȸ���� �չ��� û�� �����̸� ����
// 0: �� 1: �� 2: �� 3: �� 
void rotation(const vector<vector<int>>& MN, vector<vector<int>>& is_clean, int M ,int N, int& r, int& c, int& d) {
	//�ݽð� ȸ��
	int direction[] = { 3,0,1,2 };
	d = direction[d];
	int dm[] = { -1, 0 ,1, 0 };
	int dn[] = { 0, 1, 0, -1 };

	//��Ÿ�� ���� �������ְ�
	if (!(max(min(r + dm[d], M - 1), 0) == r && max(min(c + dn[d], N - 1), 0) == c)) {
		//���� �ƴϰ�, û�Ұ� �����ϸ�
		if (MN[r + dm[d]][c + dn[d]] == 0 && is_clean[r + dm[d]][c + dn[d]] == 0) {
			// ����
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