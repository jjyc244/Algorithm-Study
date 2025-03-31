#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;


//���� Ȯ���� �ִ� �Լ� (��Ÿ�� ���� ����)
bool Check_RunTime_ERROR(int next_m, int next_n, int N) {
	if (next_m < 0 || next_n < 0 || next_m >= N || next_n >= N)return false;
	return true;
}

//���� ����� ���̵��� ã�� �Լ�
bool find_food(vector<vector<int>>& MN, queue<pair<int, int>>& food, const pair<int, int>& baby_shark, const int N, int size, int& move_count) {

	move_count = 0;
	queue<pair<int, int>> q;
	q.push(baby_shark);
	int dm[] = { 0,0,1,-1 };
	int dn[] = { 1,-1,0,0 };

	//ù ���̸� ã���� �� ���� ���� ���ʹ� ť�� push ����
	bool find = false;

	vector<vector<int>> dist(N, vector<int>(N, INT_MAX));

	//����� ��ġ�� dist 0
	dist[baby_shark.first][baby_shark.second] = 0;

	while (!q.empty()) {
		int now_m = q.front().first;
		int now_n = q.front().second;
		q.pop();

		for (int i = 0; i < 4;i++) {
			int next_m = now_m + dm[i];
			int next_n = now_n + dn[i];

			// �� ������ �������� �ִٸ�(�ش� ����Ⱑ �� ������� ���ų� �۴ٸ� �̵�
			if (Check_RunTime_ERROR(next_m, next_n, N)) {
				if (MN[next_m][next_n] <= size && dist[now_m][now_n] + 1 < dist[next_m][next_n])
				{
					// ����� ����� ���ٸ� or 0�̸�
					if (MN[next_m][next_n] == size || MN[next_m][next_n] == 0) {
						q.push({ next_m, next_n });
						dist[next_m][next_n] = dist[now_m][now_n] + 1;
					}
					// ����� ����� �Ʊ���� ������
					else {
						find = true;
						dist[next_m][next_n] = dist[now_m][now_n] + 1;
						food.push({ next_m,next_n });
					}
				}
			}
		}
	}
	//���� ����� �� ã��
	int r = food.size();
	int min = INT_MAX;
	while (r--) {
		if (dist[food.front().first][food.front().second] < min) min = dist[food.front().first][food.front().second];
		food.push(food.front());
		food.pop();
	}
	move_count = min;
	r = food.size();
	while (r--) {
		if (dist[food.front().first][food.front().second] == min) food.push(food.front());
		food.pop();
	}

	return find;
}

//���� ����� ���̵� �� ���� ������ ���̸� ã�Ƽ� �̵��ϴ� �Լ�
void move(vector<vector<int>>& MN, queue<pair<int, int>>& food, pair<int, int>& baby_shark, const int& N) {

	// ���� ���� ��ġ ã��
	int max_top = N;
	int r = food.size();
	while (r--) {
		if (food.front().first < max_top)max_top = food.front().first;
		food.push(food.front());
		food.pop();
	}

	// �׿� �ش��ϴ� ��� ����⸸ �߸���
	r = food.size();
	while (r--) {
		if (max_top == food.front().first) {
			food.push(food.front());
		}
		food.pop();
	}

	// ���� ���� ��ġ ã��
	int max_left = N;
	r = food.size();
	while (r--) {
		if (food.front().second < max_left)max_left = food.front().second;
		food.push(food.front());
		food.pop();
	}

	// �׿� �ش��ϴ� �����( �̵��� ����� �߸��� )
	r = food.size();
	while (r--) {
		if (max_left == food.front().second) {
			food.push(food.front());
		}
		food.pop();
	}

	// ���� �̵�
	baby_shark = food.front();
	while(!food.empty())food.pop();
	MN[baby_shark.first][baby_shark.second] = 0;

}

int run(vector<vector<int>>& MN, pair<int, int>& baby_shark, const int N) {
	int eat_count = 0;
	int size = 2;
	int move_count = 0;
	int mv = 0;
	queue<pair<int, int>> food;

	while (true) {

		if (!find_food(MN, food, baby_shark, N, size, move_count)) return mv;


		mv += move_count;
		move(MN, food, baby_shark, N);
		eat_count++;
		if (eat_count == size) {
			size++;
			eat_count = 0;
		}

	}
}

int main() {
	int N;
	cin >> N;
	vector<vector<int>> MN(N, vector<int>(N));
	pair<int, int> baby_shark;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MN[i][j];
			if (MN[i][j] == 9) {
				MN[i][j] = 0;
				baby_shark = { i,j };
			}
		}
	}
	cout << run(MN, baby_shark, N);
}